package bg.sofia.uni.fmi.dp.tree.visitors;

import bg.sofia.uni.fmi.dp.tree.DirectoryComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;

import java.io.IOException;
import java.io.Writer;
import java.nio.file.Path;

public class ReportWriter implements AbstractFileComponentVisitor {
    private final Writer writer;

    public ReportWriter(Writer writer) {
        this.writer = writer;
    }

    @Override
    public void visit(FileComponent fileComponent) {
        String size = String.valueOf(fileComponent.getSize()).concat(" bytes");
        Path relative = fileComponent.getRelativePath();

        try {
            writer.write(size.concat(" ").concat(relative.toString()).concat(System.lineSeparator()));
        } catch (IOException e) {
            throw new RuntimeException("Could not write in file entry properly.", e);
        }
    }

    @Override
    public void visit(DirectoryComponent directoryComponent) {
        for (var child : directoryComponent.getChildren()) {
            child.acceptVisitor(this);
        }
    }
}
