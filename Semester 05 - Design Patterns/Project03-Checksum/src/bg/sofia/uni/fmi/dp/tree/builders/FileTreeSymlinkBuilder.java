package bg.sofia.uni.fmi.dp.tree.builders;

import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashSet;
import java.util.Set;

public class FileTreeSymlinkBuilder extends DefaultFileTreeBuilder {
    private final Set<Path> checkedSymlinks;

    public FileTreeSymlinkBuilder() {
        checkedSymlinks = new HashSet<>();
    }

    private FileComponent buildFileInstance(Path file) {
        try {
            long size = Files.size(file);
            return new FileComponent(size, file, root);
        } catch (IOException e) {
            throw new IllegalArgumentException("Could not read file size.", e);
        }
    }

    @Override
    protected AbstractFileComponent buildFile(Path file) {
        if (file == null) {
            throw new IllegalArgumentException("Provided path cannot be null.");
        }
        if (Files.isSymbolicLink(file) && !checkedSymlinks.contains(file)) {
            try {
                Path target = Files.readSymbolicLink(file);
                checkedSymlinks.add(file);
                if (Files.isDirectory(target)) {
                    return buildDirectory(target);
                }
                return buildFileInstance(target);

            } catch (IOException e) {
                throw new RuntimeException("Could not find symlink target.", e);
            }
        }

        return buildFileInstance(file);
    }
}
