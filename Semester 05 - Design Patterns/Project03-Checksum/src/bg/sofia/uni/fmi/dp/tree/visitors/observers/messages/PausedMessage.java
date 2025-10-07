package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;


public class PausedMessage implements AbstractMessage {
    private final String isPaused;

    public PausedMessage(String message) {this.isPaused = message;}

    @Override
    public String getData() {
        return isPaused;
    }
}
