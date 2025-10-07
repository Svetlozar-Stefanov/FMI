package bg.sofia.uni.fmi.dp.tree.builders;

import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.DirectoryComponent;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public abstract class DefaultFileTreeBuilder implements AbstractFileTreeBuilder {
    protected Path root;

    protected abstract AbstractFileComponent buildFile(Path file);

    protected AbstractFileComponent buildDirectory(Path dir) {
        DirectoryComponent parent = new DirectoryComponent();
        try (var dirStream = Files.list(dir)) {
            for (var child : dirStream.toList()) {
                if (Files.isDirectory(child)) {
                    parent.addChild(buildDirectory(child));
                } else {
                    parent.addChild(buildFile(child));
                }
            }
        } catch (IOException e) {
            throw new RuntimeException("Error while traversing directory.", e);
        }
        return parent;
    }

    public AbstractFileComponent build(Path directoryToTraverse) {
        if (directoryToTraverse == null) {
            throw new IllegalArgumentException("Provided path cannot be null.");
        }
        if (!Files.isDirectory(directoryToTraverse)) {
            throw new IllegalArgumentException("Provided path does not lead to a directory.");
        }
        root = directoryToTraverse;
        return buildDirectory(directoryToTraverse);
    }
}
