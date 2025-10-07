package bg.sofia.uni.fmi.dp.tree.visitors.observers;

import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;
import bg.sofia.uni.fmi.dp.tree.visitors.HashStreamWriter;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.Memento;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.MementoOriginator;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.ProgressReporterMemento;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.states.ProgressReporterState;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.AbstractMessage;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.FirstVisitMessage;

import java.util.concurrent.TimeUnit;

public class ProgressReporter implements VisitorObserver, MementoOriginator {
    private final long UPDATE_TIME_BUFFER = 1_000_000_000;

    private String processedFile;
    private String readBytes;
    private String processedFileSize;

    private long totalReadThisFile;
    private long totalBytes;
    private long totalReadBytes;
    private double completeness;

    private long startTime;
    private long remainingTime;
    private long bytesInTimeWindow;

    public ProgressReporter() {
        reset();
    }

    public void reset() {
        processedFile = "";
        readBytes = "0";
        processedFileSize = "";
        totalReadThisFile = 0;
        this.completeness = 0;
        startTime = 0;
        remainingTime = 0;
        bytesInTimeWindow = 0;
    }

    @Override
    public void update(VisitorObservable source, AbstractMessage... message) {
        if (source instanceof HashStreamWriter) {
            if (message.length == 3 && message[2] instanceof FirstVisitMessage) {
                reset();
                totalBytes = Long.parseLong(message[2].getData());
                startTime = System.nanoTime();
            }
            processedFile = message[0].getData();
            processedFileSize = message[1].getData();
            totalReadBytes += totalReadThisFile;
            totalReadThisFile = 0;
        } else if (source instanceof ChecksumCalculator) {
            readBytes = message[0].getData();
            long readBytesThisCycle = Long.parseLong(message[1].getData());
            totalReadThisFile += readBytesThisCycle;
            bytesInTimeWindow += readBytesThisCycle;
            completeness = ((double) (totalReadBytes + totalReadThisFile) / totalBytes) * 100;
        }

        if (System.nanoTime() - startTime > UPDATE_TIME_BUFFER) {
            startTime = System.nanoTime();
            remainingTime = (long) ((totalBytes - totalReadBytes) / (double) bytesInTimeWindow) * UPDATE_TIME_BUFFER;
            bytesInTimeWindow = 0;
            report();
        }
    }

    private void report() {
        String remaining = String.format("%d min, %d sec",
                TimeUnit.NANOSECONDS.toMinutes(remainingTime),
                TimeUnit.NANOSECONDS.toSeconds(remainingTime) -
                        TimeUnit.MINUTES.toSeconds(TimeUnit.NANOSECONDS.toMinutes(remainingTime))
        );

        System.out.print("\rProcessing ".concat(processedFile).concat(" ").concat(readBytes)
                .concat(" bytes read out of ").concat(processedFileSize).concat(" bytes. ")
                .concat("Progress: ").concat(String.format("%2.2f",completeness)).concat("%. ")
                .concat("Remaining time: ").concat(String.valueOf(remaining)));
    }

    @Override
    public Memento save() {
        return new ProgressReporterMemento(this,
                new ProgressReporterState(
                        processedFile,
                        processedFileSize,

                        totalBytes,
                        totalReadBytes));
    }

    public void setState(ProgressReporterState state) {
        reset();
        this.processedFile = state.processedFile();
        this.processedFileSize = state.processedFileSize();

        this.totalBytes = state.totalBytes();
        this.totalReadBytes = state.totalReadBytes();
    }
}
