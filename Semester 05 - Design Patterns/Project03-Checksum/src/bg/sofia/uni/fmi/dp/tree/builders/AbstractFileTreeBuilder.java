package bg.sofia.uni.fmi.dp.tree.builders;

import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;

import java.nio.file.Path;

public interface AbstractFileTreeBuilder {
    public AbstractFileComponent build(Path directoryToTraverse);
}
