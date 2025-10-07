package bg.sofia.uni.fmi.dp.tree.visitors.mementos;

import bg.sofia.uni.fmi.dp.tree.visitors.mementos.states.ProgressReporterState;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.ProgressReporter;

public class ProgressReporterMemento implements Memento {
    private final ProgressReporter originator;
    private final ProgressReporterState state;

    public ProgressReporterMemento(ProgressReporter originator, ProgressReporterState state) {
        this.originator = originator;
        this.state = state;
    }

    @Override
    public void restore() {
        originator.setState(state);
    }
}
