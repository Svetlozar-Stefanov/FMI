package bg.sofia.uni.fmi.mjt.photoalbum;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public class ParallelMonochromeAlbumCreator implements MonochromeAlbumCreator {
    private final int imageProcessorsCount;
    private final Object lock = new Object();

    private AtomicBoolean allImagesLoaded;
    private Deque<Image> images;

    public  ParallelMonochromeAlbumCreator(int imageProcessorsCount) {
        this.imageProcessorsCount = imageProcessorsCount;
        images = new ArrayDeque<>();
        allImagesLoaded = new AtomicBoolean(false);
    }

    private List<Thread> startConsumers(String outputDirectory) {
        Path outputDirPath = Path.of(outputDirectory);
        if (!Files.exists(outputDirPath)) {
            try {
                Files.createDirectory(outputDirPath);
            } catch (IOException e) {
                throw new RuntimeException("Could not create the specified directory.", e);
            }
        }

        List<Thread> consumerThreads = new ArrayList<>();
        for (int i = 0; i < imageProcessorsCount; i++) {
            Thread consumerThread = Thread.ofVirtual()
                .start(new ImageConsumer(outputDirPath, images, allImagesLoaded, lock));
            consumerThreads.add(consumerThread);
        }

        return consumerThreads;
    }

    private List<Thread> startProducers(String sourceDirectory) {
        Path sourceDirPath = Path.of(sourceDirectory);
        if (!Files.exists(sourceDirPath) || !Files.isDirectory(sourceDirPath)) {
            throw new IllegalArgumentException("Provided path does not lead to a valid directory.");
        }

        List<Thread> producerThreads = new ArrayList<>();
        try (var sourceDirStream = Files.walk(sourceDirPath, Integer.MAX_VALUE)) {
            var temp = sourceDirStream
                .filter(p -> p.getFileName().toString().matches(".*\\.jpg")
                    || p.getFileName().toString().matches(".*\\.jpeg")
                    || p.getFileName().toString().matches(".*\\.png")).toList();
            for (var imageFile : temp) {
                Thread producerThread = Thread.ofVirtual()
                    .start(new ImageProducer(imageFile, images, lock));
                producerThreads.add(producerThread);
            }
        } catch (IOException e) {
            throw new RuntimeException("Failed to find all files in directory.", e);
        }

        return producerThreads;
    }

    @Override
    public void processImages(String sourceDirectory, String outputDirectory) {
        List<Thread> consumerThreads = startConsumers(outputDirectory);

        List<Thread> producerThreads = startProducers(sourceDirectory);

        for (var thread : producerThreads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                throw new RuntimeException("Main thread was interrupted while waiting for producer threads.", e);
            }
        }

        allImagesLoaded.set(true);

        for (var thread : consumerThreads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                throw new RuntimeException("Main thread was interrupted while waiting for consumer threads.", e);
            }
        }
    }
}
