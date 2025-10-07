package bg.sofia.uni.fmi.mjt.photoalbum;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Path;
import java.util.Deque;

public class ImageProducer implements Runnable {
    private final Object lock;
    private Path imagePath;
    private Deque<Image> images;

    public ImageProducer(Path imagePath, Deque<Image> images, Object lock) {
        this.imagePath = imagePath;
        this.images = images;
        this.lock = lock;
    }

    private Image loadImage(Path imagePath) {
        try {
            BufferedImage imageData = ImageIO.read(imagePath.toFile());
            return new Image(imagePath.getFileName().toString(), imageData);
        } catch (IOException e) {
            throw new UncheckedIOException(String.format("Failed to load image %s", imagePath.toString()), e);
        }
    }

    @Override
    public void run() {
        Image image = loadImage(imagePath);

        synchronized (lock) {
            images.push(image);
            lock.notifyAll();
        }
    }
}