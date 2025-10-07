package bg.sofia.uni.fmi.dp.tree;

import bg.sofia.uni.fmi.dp.tree.visitors.AbstractFileComponentVisitor;

import java.nio.file.Path;

public class FileComponent implements AbstractFileComponent {
    private final long size;
    private final Path path;
    private final Path root;

    public FileComponent(long size, Path path, Path root) {
        this.size = size;
        this.path = path;
        this.root = root;
    }

    public Path getPath() {
        return path;
    }

    public Path getRelativePath() {
        return root.relativize(path);
    }

    @Override
    public long getSize() {
        return size;
    }

    @Override
    public void acceptVisitor(AbstractFileComponentVisitor visitor) {
        visitor.visit(this);
    }
}