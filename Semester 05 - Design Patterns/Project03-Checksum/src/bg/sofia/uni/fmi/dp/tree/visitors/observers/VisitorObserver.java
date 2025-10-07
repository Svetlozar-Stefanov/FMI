package bg.sofia.uni.fmi.dp.tree.visitors.observers;

import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.AbstractMessage;

public interface VisitorObserver {
    public void update(VisitorObservable source, AbstractMessage... message);
}
