package bg.sofia.uni.fmi.mjt.csvprocessor;

import bg.sofia.uni.fmi.mjt.csvprocessor.exceptions.CsvDataNotCorrectException;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.BaseTable;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.Table;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.printer.ColumnAlignment;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.printer.MarkdownTablePrinter;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.printer.TablePrinter;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

public class CsvProcessor implements CsvProcessorAPI {

    private Table table;

    public CsvProcessor() {
        table = new BaseTable();
    }

    public CsvProcessor(Table table) {
        this.table = table;
    }

    @Override
    public void readCsv(Reader reader, String delimiter) throws CsvDataNotCorrectException {
        BufferedReader lineReader = new BufferedReader(reader);

        String line;
        while (true) {
            try {
                line = lineReader.readLine();
                if (line == null) {
                    break;
                }
                var del = String.format("\\%s", delimiter);
                var data = line.split(del);
                table.addData(data);
            } catch (IOException e) {
                throw new RuntimeException("Error while reading from file.");
            }
        }
    }

    @Override
    public void writeTable(Writer writer, ColumnAlignment... alignments) {
        TablePrinter tablePrinter = new MarkdownTablePrinter();
        var rows = tablePrinter.printTable(table, alignments);

        var row = rows.iterator();
        for (int i = 0; i < rows.size(); i++) {
            try {
                writer.write(row.next());
                if (i < rows.size() - 1) {
                    writer.write(System.lineSeparator());
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
