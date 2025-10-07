package bg.sofia.uni.fmi.dp.tree;

import bg.sofia.uni.fmi.dp.tree.visitors.AbstractFileComponentVisitor;

public interface AbstractFileComponent {
    public long getSize();
    public void acceptVisitor(AbstractFileComponentVisitor visitor);
}
