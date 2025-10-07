package bg.sofia.uni.fmi.dp.tree.visitors;

import bg.sofia.uni.fmi.dp.resources.Constants;
import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.FileComponent;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.io.StringWriter;
import java.util.List;

public class ReportWriterTest {
    @Test
    public void testReportWriterWithDefaultTree() {
        try(StringWriter writer = new StringWriter()) {
            AbstractFileComponentVisitor visitor = new ReportWriter(writer);

            Constants.testRootDir01DefaultTree.acceptVisitor(visitor);

            List<String> expected = List.of(
                    "27 bytes Level01-01\\Level02-01\\Level03-01.txt",
                    "20 bytes Level01-01\\Level02-01.txt",
                    "77 bytes Level01-01\\Level02-02\\Level03-01\\Level04-01.txt",
                    "18 bytes Level01-01\\Level02-02\\Level03-01.txt",
                    "1082 bytes Level01-01-Shortcut.lnk",
                    "57 bytes Level01-01.txt",
                    "38 bytes Level01-02\\Level02-01\\Level03-01\\Level04-01\\Level05-01\\Level06-01.txt",
                    "35 bytes Level01-02\\Level02-01\\Level03-01.txt",
                    "44 bytes Level01-02.txt",
                    "50 bytes Level01-03\\Level02-01\\Level03-01.txt",
                    "865 bytes Level01-03\\Level02-01\\RootDir02-Shortcut.lnk",
                    "22 bytes Level01-03\\Level02-01.txt",
                    "21 bytes Level01-03\\Level02-02\\Level03-02.txt",
                    "21 bytes Level01-03\\Level02-02.txt"
            );
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
