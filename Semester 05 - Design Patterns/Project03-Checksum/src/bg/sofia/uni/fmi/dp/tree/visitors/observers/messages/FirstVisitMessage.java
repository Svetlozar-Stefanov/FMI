package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

public class FirstVisitMessage implements AbstractMessage {
    private final long totalTreeSize;

    public FirstVisitMessage(long totalTreeSize) {
        this.totalTreeSize = totalTreeSize;
    }

    @Override
    public String getData() {
        return String.valueOf(totalTreeSize);
    }
}
