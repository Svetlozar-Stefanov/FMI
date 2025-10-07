package bg.sofia.uni.fmi.dp.resources;

import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;

import java.nio.file.Path;

public class Constants {
    public static final Path TEST_RESOURCE_DIR = Path.of("test","bg", "sofia","uni","fmi","dp","resources");

    public static final AbstractFileComponent testRootDir01DefaultTree = new FileTreeBuilder().build(
            TEST_RESOURCE_DIR.resolve("testRootDir01").toAbsolutePath()
    );

    public static final AbstractFileComponent testRootDir02DefaultTree = new FileTreeBuilder().build(
            TEST_RESOURCE_DIR.resolve("testRootDir02").toAbsolutePath()
    );
}
