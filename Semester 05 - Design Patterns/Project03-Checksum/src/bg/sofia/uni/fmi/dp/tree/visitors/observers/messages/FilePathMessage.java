package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.tree.FileComponent;

public class FilePathMessage implements AbstractMessage {
    private final FileComponent fileComponent;

    public FilePathMessage(FileComponent fileComponent) {
        this.fileComponent = fileComponent;
    }

    @Override
    public String getData() {
        return fileComponent.getRelativePath().toString();
    }
}
