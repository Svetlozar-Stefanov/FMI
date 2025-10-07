package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FilePathMessageTest {
    @Test
    public void testGetData() {
        Path root = Constants.TEST_RESOURCE_DIR;
        Path path = Constants.TEST_RESOURCE_DIR.resolve("singleFile/text.txt");
        AbstractMessage message = new FilePathMessage(new FileComponent(0, path, root));

        String expected = "singleFile\\text.txt";
        String actual = message.getData();

        Assertions.assertEquals(expected, actual, "Message data was not the correct path.");
    }
}
