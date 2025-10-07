package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.nio.file.Files;
import java.nio.file.Path;

public class ReadBytesMessageTest {
    @Test
    public void testGetData() {
        AbstractMessage message = new ReadBytesMessage(42);

        String expected = "42";
        String actual = message.getData();

        Assertions.assertEquals(expected, actual, "Message data was not the correct number of bytes.");
    }
}
