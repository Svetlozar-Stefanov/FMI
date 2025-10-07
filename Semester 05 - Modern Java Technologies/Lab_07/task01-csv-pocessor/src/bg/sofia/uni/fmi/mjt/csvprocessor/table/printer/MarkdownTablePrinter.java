package bg.sofia.uni.fmi.mjt.csvprocessor.table.printer;

import bg.sofia.uni.fmi.mjt.csvprocessor.table.Table;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class MarkdownTablePrinter implements TablePrinter {
    final int minCellSize = 3;

    private class LengthComparator implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {
            return Integer.compare(o1.length(), o2.length());
        }
    }

    private void addAlignment(Iterator<ColumnAlignment> alignmentIter, List<String> columnData, int maxWord) {
        var alignment = ColumnAlignment.NOALIGNMENT;
        if (alignmentIter.hasNext()) {
            alignment = alignmentIter.next();
        }

        switch (alignment) {
            case LEFT -> {
                columnData.add(String.format("\s:%s\s",
                    "-".repeat(maxWord - alignment.getAlignmentCharactersCount())));
            }
            case CENTER -> {
                columnData.add(String.format("\s:%s:\s",
                    "-".repeat(maxWord - alignment.getAlignmentCharactersCount())));
            }
            case RIGHT -> {
                columnData.add(String.format("\s%s:\s",
                    "-".repeat(maxWord - alignment.getAlignmentCharactersCount())));
            }
            case NOALIGNMENT -> {
                columnData.add(String.format("\s%s\s",
                    "-".repeat(maxWord - alignment.getAlignmentCharactersCount())));
            }
        }
    }

    private void addColumn(Collection<String> column, List<String> columnData, int maxWord) {
        for (var value : column) {
            int numberOfSpaces = maxWord - value.length();
            columnData.add(String.format("\s%s%s\s", value, " ".repeat(numberOfSpaces)));
        }
    }

    @Override
    public Collection<String> printTable(Table table, ColumnAlignment... alignments) {
        List<List<String>> printDataByColumns = new ArrayList<>();

        var alignmentIter = Arrays.stream(alignments).iterator();
        for (var header : table.getColumnNames()) {
            List<String> columnData = new ArrayList<>();
            var column = table.getColumnData(header);
            int maxCol = Collections.max(column, new LengthComparator()).length();
            int maxWord = Math.max(minCellSize, Math.max(header.length(), maxCol));
            int numberOfSpaces = maxWord - header.length();

            columnData.add(String.format("\s%s%s\s", header, "\s".repeat(numberOfSpaces)));

            addAlignment(alignmentIter, columnData, maxWord);
            addColumn(column, columnData, maxWord);
            printDataByColumns.add(columnData);
        }

        List<String> rows = new ArrayList<>();
        for (int i = 0; i < table.getRowsCount() + 1; i++) {
            StringBuilder rowData = new StringBuilder();
            rowData.append("|");
            for (int j = 0; j < table.getColumnNames().size(); j++) {
                rowData.append(printDataByColumns.get(j).get(i));
                rowData.append("|");
            }
            rows.add(rowData.toString());
        }
        return Collections.unmodifiableCollection(rows);
    }
}