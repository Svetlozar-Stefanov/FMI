package bg.sofia.uni.fmi.mjt.csvprocessor.table.printer;

import bg.sofia.uni.fmi.mjt.csvprocessor.exceptions.CsvDataNotCorrectException;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.BaseTable;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.Table;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class TablePrinterTest {
    @Test
    void testPrintOfTableExactAlignments() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        table.addData(new String[] {"header1", "header2", "header3", "header4"});
        table.addData(new String[] {"col11", "col21", "col31", "col41"});
        table.addData(new String[] {"col12", "bigColumn22", "col32", "col42"});
        table.addData(new String[] {"col13", "col23", "col33", "col43"});

        TablePrinter printer = new MarkdownTablePrinter();
        var printData = printer.printTable(table, ColumnAlignment.LEFT,
            ColumnAlignment.CENTER,
            ColumnAlignment.RIGHT,
            ColumnAlignment.NOALIGNMENT);

        var iter = printData.iterator();
        Assertions.assertEquals("| header1 | header2     | header3 | header4 |", iter.next());
        Assertions.assertEquals("| :------ | :---------: | ------: | ------- |", iter.next());
        Assertions.assertEquals("| col11   | col21       | col31   | col41   |", iter.next());
        Assertions.assertEquals("| col12   | bigColumn22 | col32   | col42   |", iter.next());
        Assertions.assertEquals("| col13   | col23       | col33   | col43   |", iter.next());
    }

    @Test
    void testPrintOfTableLessAlignments() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        table.addData(new String[] {"header1", "header2", "header3", "header4"});
        table.addData(new String[] {"col11", "col21", "col31", "col41"});
        table.addData(new String[] {"col12", "bigColumn22", "col32", "col42"});
        table.addData(new String[] {"col13", "col23", "col33", "col43"});

        TablePrinter printer = new MarkdownTablePrinter();
        var printData = printer.printTable(table, ColumnAlignment.LEFT,
            ColumnAlignment.CENTER);

        var iter = printData.iterator();
        Assertions.assertEquals("| header1 | header2     | header3 | header4 |", iter.next());
        Assertions.assertEquals("| :------ | :---------: | ------- | ------- |", iter.next());
        Assertions.assertEquals("| col11   | col21       | col31   | col41   |", iter.next());
        Assertions.assertEquals("| col12   | bigColumn22 | col32   | col42   |", iter.next());
        Assertions.assertEquals("| col13   | col23       | col33   | col43   |", iter.next());
    }

    @Test
    void testPrintOfTableMoreAlignments() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        table.addData(new String[] {"header1", "header2", "header3", "header4"});
        table.addData(new String[] {"col11", "col21", "col31", "col41"});
        table.addData(new String[] {"col12", "bigColumn22", "col32", "col42"});
        table.addData(new String[] {"col13", "col23", "col33", "col43"});

        TablePrinter printer = new MarkdownTablePrinter();
        var printData = printer.printTable(table,
            ColumnAlignment.LEFT,
            ColumnAlignment.CENTER,
            ColumnAlignment.RIGHT,
            ColumnAlignment.LEFT,
            ColumnAlignment.CENTER,
            ColumnAlignment.LEFT);

        var iter = printData.iterator();
        Assertions.assertEquals("| header1 | header2     | header3 | header4 |", iter.next());
        Assertions.assertEquals("| :------ | :---------: | ------: | :------ |", iter.next());
        Assertions.assertEquals("| col11   | col21       | col31   | col41   |", iter.next());
        Assertions.assertEquals("| col12   | bigColumn22 | col32   | col42   |", iter.next());
        Assertions.assertEquals("| col13   | col23       | col33   | col43   |", iter.next());
    }

    @Test
    void testPrintOfTableSmallValues() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        table.addData(new String[] {"h1", "h2", "h3", "h4"});
        table.addData(new String[] {"a", "d", "g", "j"});
        table.addData(new String[] {"b", "e", "h", "k"});
        table.addData(new String[] {"c", "f", "i", "l"});

        TablePrinter printer = new MarkdownTablePrinter();
        var printData = printer.printTable(table,
            ColumnAlignment.LEFT,
            ColumnAlignment.CENTER,
            ColumnAlignment.RIGHT,
            ColumnAlignment.LEFT);

        var iter = printData.iterator();
        Assertions.assertEquals("| h1  | h2  | h3  | h4  |", iter.next());
        Assertions.assertEquals("| :-- | :-: | --: | :-- |", iter.next());
        Assertions.assertEquals("| a   | d   | g   | j   |", iter.next());
        Assertions.assertEquals("| b   | e   | h   | k   |", iter.next());
        Assertions.assertEquals("| c   | f   | i   | l   |", iter.next());
    }
}
