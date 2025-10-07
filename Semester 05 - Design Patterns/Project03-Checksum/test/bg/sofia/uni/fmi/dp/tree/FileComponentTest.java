package bg.sofia.uni.fmi.dp.tree;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.nio.file.Path;

public class FileComponentTest {
    @Test
    public void testGetSize() {
        AbstractFileComponent fileComponent = new FileTreeBuilder().build(
                Constants.TEST_RESOURCE_DIR.resolve("singleFile")
        );

        long expected = 5136;
        long actual = fileComponent.getSize();
        Assertions.assertEquals(expected, actual,
                "File component does not return correct size.");
    }

    @Test
    public void testGetRelativePath() {
        Path root = Constants.TEST_RESOURCE_DIR;
        Path path = Constants.TEST_RESOURCE_DIR.resolve("singleFile/text.txt");
        FileComponent fileComponent = new FileComponent(0, path, root);

        Path expected = Path.of("singleFile/text.txt");
        Path actual = fileComponent.getRelativePath();

        Assertions.assertEquals(actual, expected, "Relative path was not constructed properly.");
    }
}
