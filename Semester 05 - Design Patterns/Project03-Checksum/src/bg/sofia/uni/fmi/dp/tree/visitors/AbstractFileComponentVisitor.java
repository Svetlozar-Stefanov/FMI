package bg.sofia.uni.fmi.dp.tree.visitors;

import bg.sofia.uni.fmi.dp.tree.DirectoryComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;

public interface AbstractFileComponentVisitor {
    public void visit(FileComponent fileComponent);
    public  void visit(DirectoryComponent directoryComponent);
}
