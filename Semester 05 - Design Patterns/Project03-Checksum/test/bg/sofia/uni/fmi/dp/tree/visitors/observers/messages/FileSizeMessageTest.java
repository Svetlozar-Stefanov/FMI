package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileSizeMessageTest {
    @Test
    public void testGetData() throws IOException {
        Path root = Constants.TEST_RESOURCE_DIR;
        Path path = Constants.TEST_RESOURCE_DIR.resolve("singleFile/text.txt");
        AbstractMessage message = new FileSizeMessage(new FileComponent(Files.size(path), path, root));

        String expected = "5136";
        String actual = message.getData();

        Assertions.assertEquals(expected, actual, "Message data was not the correct size.");
    }
}
