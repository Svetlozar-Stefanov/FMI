package bg.sofia.uni.fmi.dp.tree.builders;

import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileTreeBuilder extends DefaultFileTreeBuilder {
    @Override
    protected AbstractFileComponent buildFile(Path file) {
        if (file == null) {
            throw new IllegalArgumentException("Provided path cannot be null.");
        }

        try {
            long size = Files.size(file);
            return new FileComponent(size, file, root);
        } catch (IOException e) {
            throw new IllegalArgumentException("Could not read file size.", e);
        }
    }
}
