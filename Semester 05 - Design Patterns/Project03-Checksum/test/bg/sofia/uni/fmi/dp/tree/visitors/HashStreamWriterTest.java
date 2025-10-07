package bg.sofia.uni.fmi.dp.tree.visitors;

import bg.sofia.uni.fmi.dp.methods.calculators.MD5Calculator;
import bg.sofia.uni.fmi.dp.resources.Constants;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.io.StringWriter;
import java.util.List;

public class HashStreamWriterTest {
    @Test
    public void testHashStreamWriterWithDefaultTree() {
        try(StringWriter writer = new StringWriter()) {
            AbstractFileComponentVisitor visitor = new HashStreamWriter(writer, new MD5Calculator());

            Constants.testRootDir01DefaultTree.acceptVisitor(visitor);

            List<String> expected = List.of(
                    "ab781e18cb027506f2f040432884ff61 Level01-01\\Level02-01\\Level03-01.txt",
            "949da2d31bc3b50ae1ddada60eae847b Level01-01\\Level02-01.txt",
            "f2a3a1829880dd1bc591e4361b950620 Level01-01\\Level02-02\\Level03-01\\Level04-01.txt",
            "fdc737922b79ec1a7fffad563277ef3e Level01-01\\Level02-02\\Level03-01.txt",
            "c8ced515194008b76078c15a729e0960 Level01-01-Shortcut.lnk",
            "79d872ccdf73a94c9fd7ce6459a0d16c Level01-01.txt",
            "c38bc77a2d1feb0c45888d9ab61b4ce1 Level01-02\\Level02-01\\Level03-01\\Level04-01\\Level05-01\\Level06-01.txt",
            "ab6ef7f005333dc348fb3ff9bd7793ae Level01-02\\Level02-01\\Level03-01.txt",
            "9e767238b19c8b02f6329897eedc9f3a Level01-02.txt",
            "0a9e516530912cf947b2989174dd44ab Level01-03\\Level02-01\\Level03-01.txt",
            "af23f305d1ed19bc5fc88cdc853625be Level01-03\\Level02-01\\Level04-02.txt",
            "d732bccd9e46c075d6fce2988e2054ed Level01-03\\Level02-01\\RootDir02-Shortcut.lnk",
            "ae87f770282cfbd34c3eec258d31ea7b Level01-03\\Level02-01.txt",
            "33b8e2abe696320d780c8628f20549e8 Level01-03\\Level02-02\\Level03-02.txt",
            "33b8e2abe696320d780c8628f20549e8 Level01-03\\Level02-02.txt");
            String actual = writer.toString();

            for (var entry : expected) {
                Assertions.assertTrue(actual.contains(entry),
                        "A file was not processed by visitor.");
            }
        } catch (IOException e) {
            throw new RuntimeException("Error while writing.", e);
        }
    }
}
