package bg.sofia.uni.fmi.dp;

import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;
import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeSymlinkBuilder;
import bg.sofia.uni.fmi.dp.tree.visitors.AbstractFileComponentVisitor;
import bg.sofia.uni.fmi.dp.tree.visitors.HashStreamWriter;
import bg.sofia.uni.fmi.dp.tree.visitors.ReportWriter;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.Memento;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.ProgressReporter;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.VisitorObservable;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.VisitorObserver;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.AbstractMessage;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.PausedMessage;

import java.io.Writer;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class DirectoryManager implements VisitorObservable {
    private Path workingDir;
    private AbstractFileComponent root;

    private final Object lock;
    private boolean paused;

    private ProgressReporter reporter;
    private HashStreamWriter visitor;

    private List<VisitorObserver> observers;
    private List<Memento> mementos;

    public DirectoryManager() {
        workingDir = null;
        root = null;
        observers = new ArrayList<>();
        lock = new Object();
        paused = false;
        mementos = new ArrayList<>();
    }

    public void loadDirectory(String dirPath, boolean traverseSymlinks) {
        workingDir = Path.of(dirPath);
        if (traverseSymlinks) {
            root = new FileTreeSymlinkBuilder().build(workingDir);
        }
        root = new FileTreeBuilder().build(workingDir);
    }

    public void report(Writer writer) {
        if (root == null) {
            throw new IllegalArgumentException("No directory loaded.");
        }

        AbstractFileComponentVisitor visitor = new ReportWriter(writer);
        root.acceptVisitor(visitor);
    }

    public void hash(Writer writer, ChecksumCalculator calculator) {
        if (root == null) {
            throw new IllegalArgumentException("No directory loaded.");
        }

        reporter = new ProgressReporter();
        visitor = new HashStreamWriter(writer, calculator, reporter);
        addObserver(visitor);
        addObserver((VisitorObserver) calculator);
        root.acceptVisitor(visitor);
        if (paused) {
            mementos.add(reporter.save());
            mementos.add(visitor.save());
        }
    }

    public void pause() {
        synchronized (lock) {
            paused = true;
        }
        notifyObservers(new PausedMessage("true"));
    }

    public void resumeRequest() {
        synchronized (lock) {
            paused = false;
        }
        notifyObservers(new PausedMessage("false"));

        for(var memento : mementos) {
            memento.restore();
        }
        mementos.clear();
    }

    public void resumeTraversal() {
        visitor.processComponents();
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
        for (var observer : observers) {
            observer.update(this, message);
        }
    }
}