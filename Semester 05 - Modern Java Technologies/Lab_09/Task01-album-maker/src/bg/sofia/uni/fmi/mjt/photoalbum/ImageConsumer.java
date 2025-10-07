package bg.sofia.uni.fmi.mjt.photoalbum;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Deque;
import java.util.concurrent.atomic.AtomicBoolean;

public class ImageConsumer implements Runnable {
    private final Object lock;
    private Path imagesOutputDirPath;
    private Deque<Image> images;

    private AtomicBoolean allImagesLoaded;

    public ImageConsumer(Path imagesOutputDirPath, Deque<Image> images, AtomicBoolean allImagesLoaded, Object lock) {
        this.images = images;
        this.imagesOutputDirPath = imagesOutputDirPath;
        this.allImagesLoaded = allImagesLoaded;
        this.lock = lock;
    }

    private Image convertToBlackAndWhite(Image image) {
        BufferedImage processedData = new BufferedImage(
            image.data.getWidth(),
            image.data.getHeight(),
            BufferedImage.TYPE_BYTE_GRAY);
        processedData.getGraphics().drawImage(image.data, 0, 0, null);

        return new Image(image.name, processedData);
    }

    @Override
    public void run() {
        while (true) {
            Image bwImage = null;
            synchronized (lock) {
                if (images.isEmpty() && !allImagesLoaded.get()) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        throw new RuntimeException("Consumer thread waiting for new elements was interrupted.", e);
                    }
                } else if (images.isEmpty() && allImagesLoaded.get()) {
                    break;
                } else {
                    bwImage = images.pop();
                }
            }

            if (bwImage != null) {
                bwImage = convertToBlackAndWhite(bwImage);
                try {
                    ImageIO.write(bwImage.data, bwImage.name.split("\\.")[1],
                        Files.createFile(Path.of(imagesOutputDirPath.toString(), bwImage.name)).toFile());
                } catch (IOException e) {
                    throw new RuntimeException("Could not save image", e);
                }
            }
        }
    }
}
