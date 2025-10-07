package bg.sofia.uni.fmi.dp.tree.visitors.observers.messages;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.nio.file.Files;
import java.nio.file.Path;

public class PausedMessageTest {
    @Test
    public void testGetData() {
        AbstractMessage message = new PausedMessage("true");

        String expected = "true";
        String actual = message.getData();

        Assertions.assertEquals(expected, actual, "Message data was not correct.");
    }
}
