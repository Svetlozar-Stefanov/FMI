package bg.sofia.uni.fmi.dp.tree.visitors;

import bg.sofia.uni.fmi.dp.methods.AbstractFileChecksumCalculator;
import bg.sofia.uni.fmi.dp.methods.FileChecksumCalculator;
import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;
import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.DirectoryComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.HashStreamWriterMemento;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.Memento;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.MementoOriginator;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.states.HashStreamWriterState;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.*;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.*;

import java.io.IOException;
import java.io.Writer;
import java.nio.file.Path;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class HashStreamWriter implements AbstractFileComponentVisitor, VisitorObservable, MementoOriginator, VisitorObserver {
    private Writer writer;
    private ChecksumCalculator calculator;
    private AbstractFileChecksumCalculator checksumCalculator;
    private Deque<AbstractFileComponent> componentDeque;
    private AtomicBoolean paused;

    private List<VisitorObserver> observers;

    private boolean firstVisit;
    private long processedTreeSize;

    public HashStreamWriter(Writer writer, ChecksumCalculator calculator) {
        this.writer = writer;
        this.calculator = calculator;
        checksumCalculator = new FileChecksumCalculator(calculator);
        componentDeque = new LinkedList<>();
        observers = new ArrayList<>();
        processedTreeSize = -1;
        firstVisit = true;
        paused = new AtomicBoolean(false);
    }

    public HashStreamWriter(Writer writer, ChecksumCalculator calculator, VisitorObserver... observers) {
        this.writer = writer;
        this.calculator = calculator;
        checksumCalculator = new FileChecksumCalculator(calculator);
        componentDeque = new LinkedList<>();
        this.observers = List.of(observers);
        for(var observer : observers) {
            ((VisitorObservable) calculator).addObserver(observer);
        }
        processedTreeSize = -1;
        firstVisit = true;
        paused = new AtomicBoolean(false);
    }

    public void reset(Writer writer) {
        this.writer = writer;
        processedTreeSize = -1;
        firstVisit = true;
        componentDeque.clear();
        paused.set(false);
    }

    @Override
    public void visit(FileComponent fileComponent) {
        if (!firstVisit) {
            notifyObservers(
                    new FilePathMessage(fileComponent),
                    new FileSizeMessage(fileComponent));
        } else {
            notifyObservers(
                    new FilePathMessage(fileComponent),
                    new FileSizeMessage(fileComponent),
                    new FirstVisitMessage(processedTreeSize));
            firstVisit = false;
        }

        Path relative = fileComponent.getRelativePath();
        String checksum = checksumCalculator.calculate(fileComponent.getPath());
        if (paused.get()) {
            return;
        }

        try {
            writer.write(checksum.concat(" ").concat(relative.toString()).concat(System.lineSeparator()));
        } catch (IOException e) {
            throw new RuntimeException("Could not write in file entry properly.", e);
        }
    }

    public void processComponents() {
        while (!componentDeque.isEmpty()) {
            AbstractFileComponent current = componentDeque.pollFirst();

            if (current instanceof DirectoryComponent dir) {
                for (var child : dir.getChildren()) {
                    componentDeque.addFirst(child);
                }
            } else if (current instanceof FileComponent file) {
                file.acceptVisitor(this);
                if (paused.get()) {
                    componentDeque.addFirst(current);
                    return;
                }
            }
        }
    }

    @Override
    public void visit(DirectoryComponent directoryComponent) {
        processedTreeSize = directoryComponent.getSize();

        componentDeque.addFirst(directoryComponent);
        processComponents();
    }

    @Override
    public void addObserver(VisitorObserver observer) {
        observers.add(observer);
        ((VisitorObservable) calculator).addObserver(observer);
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
    public Memento save() {
        return new HashStreamWriterMemento(this, new HashStreamWriterState(
                writer,
                calculator,
                checksumCalculator,
                componentDeque,
                paused,
                observers,
                firstVisit,
                processedTreeSize
        ));
    }

    public void setState(HashStreamWriterState state) {
        this.writer = state.writer();
        this.calculator = state.calculator();
        this.checksumCalculator = state.checksumCalculator();
        this.componentDeque = state.componentDeque();
        this.paused = state.paused();
        this.observers = state.observers();
        this.firstVisit = state.firstVisit();
        this.processedTreeSize = state.processedTreeSize();
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
