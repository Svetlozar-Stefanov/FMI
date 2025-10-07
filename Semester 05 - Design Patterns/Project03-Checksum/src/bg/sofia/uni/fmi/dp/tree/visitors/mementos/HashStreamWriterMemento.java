package bg.sofia.uni.fmi.dp.tree.visitors.mementos;

import bg.sofia.uni.fmi.dp.tree.visitors.HashStreamWriter;
import bg.sofia.uni.fmi.dp.tree.visitors.mementos.states.HashStreamWriterState;

public class HashStreamWriterMemento implements Memento {
    private final HashStreamWriter originator;
    private final HashStreamWriterState state;

    public HashStreamWriterMemento(HashStreamWriter originator, HashStreamWriterState state) {
        this.originator = originator;
        this.state = state;
    }

    @Override
    public void restore() {
        originator.setState(state);
    }
}
