package bg.sofia.uni.fmi.dp.tree;

import bg.sofia.uni.fmi.dp.tree.visitors.AbstractFileComponentVisitor;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class DirectoryComponent implements AbstractFileComponent {
    private long size;
    private final List<AbstractFileComponent> children;

    public DirectoryComponent() {
        size = -1;
        children = new ArrayList<>();
    }

    public void addChild(AbstractFileComponent child) {
        children.add(child);
    }

    public Collection<AbstractFileComponent> getChildren() {
        return children;
    }

    @Override
    public long getSize() {
        if (size == -1) {
            size = 0;
            for (var child : children) {
                size += child.getSize();
            }

            return size;
        }
        return size;
    }

    @Override
    public void acceptVisitor(AbstractFileComponentVisitor visitor) {
        visitor.visit(this);
    }
}
