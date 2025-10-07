package bg.sofia.uni.fmi.mjt.csvprocessor;

import bg.sofia.uni.fmi.mjt.csvprocessor.exceptions.CsvDataNotCorrectException;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.BaseTable;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.Table;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.printer.ColumnAlignment;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.nio.file.Files;
import java.nio.file.Paths;

public class CsvProcessorTest {
    private static boolean deleteDirectory(File directoryToBeDeleted) {
        File[] allContents = directoryToBeDeleted.listFiles();
        if (allContents != null) {
            for (File file : allContents) {
                deleteDirectory(file);
            }
        }
        return directoryToBeDeleted.delete();
    }

    @BeforeAll
    static void setUpTestFiles() {
        try {
            Files.createDirectory(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @AfterAll
    static void cleanUp() {
        deleteDirectory(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles").toFile());
    }

    @Test
    void testSuccessfulReadFromFile() throws IOException {
        try (Writer writer = new FileWriter("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/toRead.csv")){
            writer.write("header1,header2,header3,header4\n");
            writer.write("col11,col21,col31,col41\n");
            writer.write("col12,bigColumn22,col32,col42\n");
            writer.write("col13,col23,col33,col43");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try (Writer writer = new FileWriter("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempExpected.md")){
            writer.write("| header1 | header2     | header3 | header4 |\n");
            writer.write("| :------ | :---------: | ------: | ------- |\n");
            writer.write("| col11   | col21       | col31   | col41   |\n");
            writer.write("| col12   | bigColumn22 | col32   | col42   |\n");
            writer.write("| col13   | col23       | col33   | col43   |");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        CsvProcessorAPI csvProcessor = new CsvProcessor();
        try (Reader reader = new FileReader("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/toRead.csv")) {
            csvProcessor.readCsv(reader, ",");
        } catch (CsvDataNotCorrectException | IOException e) {
            throw new RuntimeException(e);
        }

        try (Writer writer = new FileWriter("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempActual.md")){
            csvProcessor.writeTable(writer,
                ColumnAlignment.LEFT,
                ColumnAlignment.CENTER,
                ColumnAlignment.RIGHT,
                ColumnAlignment.NOALIGNMENT);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Assertions.assertEquals(
            Files.readAllLines(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempExpected.md")),
            Files.readAllLines(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempActual.md"))
        );

        Files.delete(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/toRead.csv"));
        Files.delete(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempExpected.md"));
        Files.delete(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/tempActual.md"));
    }

    @Test
    void testSuccessfulWriting() throws CsvDataNotCorrectException, IOException {
        try (Writer writer = new FileWriter("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp1.md")){
            writer.write("| header1 | header2     | header3 | header4 |\n");
            writer.write("| :------ | :---------: | ------: | ------- |\n");
            writer.write("| col11   | col21       | col31   | col41   |\n");
            writer.write("| col12   | bigColumn22 | col32   | col42   |\n");
            writer.write("| col13   | col23       | col33   | col43   |");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Table table = new BaseTable();
        table.addData(new String[] {"header1", "header2", "header3", "header4"});
        table.addData(new String[] {"col11", "col21", "col31", "col41"});
        table.addData(new String[] {"col12", "bigColumn22", "col32", "col42"});
        table.addData(new String[] {"col13", "col23", "col33", "col43"});
        CsvProcessorAPI csvProcessor = new CsvProcessor(table);

        try (Writer writer = new FileWriter("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp2.md")){
            csvProcessor.writeTable(writer,
                ColumnAlignment.LEFT,
                ColumnAlignment.CENTER,
                ColumnAlignment.RIGHT,
                ColumnAlignment.NOALIGNMENT);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Assertions.assertEquals(
            Files.readAllLines(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp1.md")),
            Files.readAllLines(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp2.md"))
        );

        Files.delete(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp1.md"));
        Files.delete(Paths.get("test/bg/sofia/uni/fmi/mjt/csvprocessor/TestFiles/temp2.md"));
    }
}
