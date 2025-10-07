package bg.sofia.uni.fmi.dp.tree;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class DirectoryComponentTest {
    @Test
    public void testGetSize() {
        long expected = 2427;
        long actual = Constants.testRootDir01DefaultTree.getSize();
        Assertions.assertEquals(expected, actual,
                "File component does not return correct size.");
    }
}
