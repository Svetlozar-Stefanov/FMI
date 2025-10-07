package bg.sofia.uni.fmi.dp.methods.calculators;

import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.AbstractMessage;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.VisitorObservable;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.VisitorObserver;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.PausedMessage;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.ReadBytesMessage;

import java.io.IOException;
import java.io.InputStream;
import java.security.DigestInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public class MD5Calculator implements ChecksumCalculator, VisitorObservable, VisitorObserver {
    private final static int BYTES_TO_READ_BEFORE_NOTIFICATION = 100;

    private AtomicBoolean paused;

    private final List<VisitorObserver> observers;

    public MD5Calculator() {
        observers = new ArrayList<>();
        paused = new AtomicBoolean(false);
    }
    public MD5Calculator(VisitorObserver... observers) {
        this.observers = List.of(observers);
        paused = new AtomicBoolean(false);
    }

    @Override
    public String calculate(InputStream inputStream) {
        if (inputStream == null) {
            throw new IllegalArgumentException("Input stream cannot be null.");
        }

        MessageDigest messageDigest;
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("Specified algorithm does not exist.", e);
        }

        DigestInputStream dis = new DigestInputStream(inputStream, messageDigest);
        try {
            long bytesRead = 0;
            long read;
            while ((read = dis.readNBytes(BYTES_TO_READ_BEFORE_NOTIFICATION).length) != 0) {
                if (paused.get()) {
                    return "";
                }
                bytesRead += read;
                notifyObservers(new ReadBytesMessage(bytesRead), new ReadBytesMessage(read));
            }
        } catch (IOException e) {
            throw new RuntimeException("Error while reading file.", e);
        }

        StringBuilder sb = new StringBuilder();
        for (byte b : messageDigest.digest()) {
            sb.append(String.format("%02x", b));
        }

        return sb.toString();
    }

    @Override
    public void addObserver(VisitorObserver observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(VisitorObserver observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(AbstractMessage... message) {
        for(var observer : observers) {
            observer.update(this, message);
        }
    }

    @Override
    public void update(VisitorObservable source, AbstractMessage... message) {
        for (var m : message) {
            if (m instanceof PausedMessage) {
                paused.set(Boolean.parseBoolean(m.getData()));
            }
        }
    }
}
