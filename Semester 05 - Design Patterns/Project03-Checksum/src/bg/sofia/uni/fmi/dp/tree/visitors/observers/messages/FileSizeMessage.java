package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.tree.FileComponent;

public class FileSizeMessage implements AbstractMessage {
    private final FileComponent fileComponent;

    public FileSizeMessage(FileComponent fileComponent) {
        this.fileComponent = fileComponent;
    }

    @Override
    public String getData() {
        return String.valueOf(fileComponent.getSize());
    }
}
