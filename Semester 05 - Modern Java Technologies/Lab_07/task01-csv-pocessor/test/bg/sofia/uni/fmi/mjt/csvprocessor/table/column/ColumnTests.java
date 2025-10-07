package bg.sofia.uni.fmi.mjt.csvprocessor.table.column;

import bg.sofia.uni.fmi.mjt.csvprocessor.table.column.BaseColumn;
import bg.sofia.uni.fmi.mjt.csvprocessor.table.column.Column;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ColumnTests {
    @Test
    void testAddDataWithNull() {
        Column col = new BaseColumn();
        Assertions.assertThrows( IllegalArgumentException.class, () -> col.addData(null));
    }

    @Test
    void testAddDataWithBlank() {
        Column col = new BaseColumn();
        Assertions.assertThrows( IllegalArgumentException.class, () -> col.addData(""));
    }

    @Test
    void testGetDataReturnsUnmodifiable() {
        Column col = new BaseColumn();
        col.addData("temp");
        Assertions.assertThrows(UnsupportedOperationException.class, () -> col.getData().add("newTemp"));
    }
}
