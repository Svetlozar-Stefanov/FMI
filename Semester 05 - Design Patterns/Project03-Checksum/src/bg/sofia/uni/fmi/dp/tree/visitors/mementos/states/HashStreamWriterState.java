package bg.sofia.uni.fmi.dp.tree.visitors.mementos.states;

import bg.sofia.uni.fmi.dp.methods.AbstractFileChecksumCalculator;
import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;
import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.VisitorObserver;

import java.io.Writer;
import java.util.Deque;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public record HashStreamWriterState(
        Writer writer,
        ChecksumCalculator calculator,
        AbstractFileChecksumCalculator checksumCalculator,
        Deque<AbstractFileComponent> componentDeque,
        AtomicBoolean paused,
        List<VisitorObserver> observers,
        boolean firstVisit,
        long processedTreeSize
) implements State {
}
