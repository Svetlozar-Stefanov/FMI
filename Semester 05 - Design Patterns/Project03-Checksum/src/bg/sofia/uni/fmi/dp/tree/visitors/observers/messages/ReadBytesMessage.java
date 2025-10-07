package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

public class ReadBytesMessage implements AbstractMessage {
    private final long readBytes;

    public ReadBytesMessage(long readBytes) {
        this.readBytes = readBytes;
    }

    @Override
    public String getData() {
        return String.valueOf(readBytes);
    }
}
