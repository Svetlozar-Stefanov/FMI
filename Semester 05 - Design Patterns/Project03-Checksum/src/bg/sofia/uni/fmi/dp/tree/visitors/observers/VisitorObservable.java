package bg.sofia.uni.fmi.dp.tree.visitors.observers;

import bg.sofia.uni.fmi.dp.tree.visitors.observers.messages.AbstractMessage;

public interface VisitorObservable {
    public void addObserver(VisitorObserver observer);

    public void removeObserver(VisitorObserver observer);

    public void notifyObservers(AbstractMessage... message);
}
