package bg.sofia.uni.fmi.mjt.csvprocessor.table;

import bg.sofia.uni.fmi.mjt.csvprocessor.exceptions.CsvDataNotCorrectException;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.column.BaseColumn;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.column.Column;

import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.Map;

public class BaseTable implements Table {
    private Map<String, Column> columns;

    public BaseTable() {
        columns = new LinkedHashMap<>();
    }

    @Override
    public void addData(String[] data) throws CsvDataNotCorrectException {
        if (data == null) {
            throw new IllegalArgumentException("Data cannot be null.");
        }

        if (columns.isEmpty()) {
            for (var header : data) {
                columns.put(header, new BaseColumn());
            }
            return;
        }

        if (data.length != columns.size()) {
            throw new CsvDataNotCorrectException("Number of values does not match number of columns.");
        }

        var column = columns.values().iterator();
        var values = Arrays.stream(data).iterator();
        while (column.hasNext()) {
            column.next().addData(values.next());
        }
    }

    @Override
    public Collection<String> getColumnNames() {
        return Collections.unmodifiableCollection(columns.keySet());
    }

    @Override
    public Collection<String> getColumnData(String column) {
        if (column == null || column.isBlank() || !columns.containsKey(column)) {
            throw new IllegalArgumentException("Column name is invalid.");
        }
        return columns.get(column).getData();
    }

    @Override
    public int getRowsCount() {
        if (columns.isEmpty()) {
            return 0;
        }
        return columns.values().iterator().next().getData().size() + 1;
    }
}
