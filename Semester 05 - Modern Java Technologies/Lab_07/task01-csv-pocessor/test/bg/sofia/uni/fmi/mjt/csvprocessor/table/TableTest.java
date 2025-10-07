package bg.sofia.uni.fmi.mjt.csvprocessor.table;

import bg.sofia.uni.fmi.mjt.csvprocessor.exceptions.CsvDataNotCorrectException;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;

public class TableTest {
    @Test
    void testSuccessfulFirstAddData() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        String[] data = new String[] {"head1", "head2", "head3"};
        table.addData(data);

        var i1 = Arrays.stream(data).iterator();
        var i2 = table.getColumnNames().iterator();
        while (i1.hasNext()) {
            Assertions.assertEquals(i1.next(), i2.next());
        }
    }

    @Test
    void testSuccessfulSubsequentAddData() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        String[] data = new String[] {"head1", "head2", "head3"};
        table.addData(data);

        String[] data2 = new String[] {"val1", "val2", "val3"};
        table.addData(data2);

        var i1 = Arrays.stream(data).iterator();
        var i2 = Arrays.stream(data2).iterator();
        while (i1.hasNext()) {
            var i3 = table.getColumnData(i1.next()).iterator().next();
            Assertions.assertEquals(i2.next(), i3);
        }
    }

    @Test
    void testNullData() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        Assertions.assertThrows(IllegalArgumentException.class, () -> table.addData(null));
    }

    @Test
    void testInvalidCSVFormat() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        String[] data = new String[] {"head1", "head2", "head3"};
        table.addData(data);

        String[] data2 = new String[] {"val1", "val2"};
        Assertions.assertThrows(CsvDataNotCorrectException.class, () -> table.addData(data2));
    }

    @Test
    void testGetRowsCount() throws CsvDataNotCorrectException {
        Table table = new BaseTable();
        String[] data = new String[] {"head1", "head2", "head3"};
        table.addData(data);

        String[] data2 = new String[] {"val11", "val12", "val13"};
        table.addData(data2);
        String[] data3 = new String[] {"val21", "val22", "val23"};
        table.addData(data3);
        String[] data4 = new String[] {"val31", "val32", "val33"};
        table.addData(data4);

        Assertions.assertEquals(4, table.getRowsCount());
    }
}
