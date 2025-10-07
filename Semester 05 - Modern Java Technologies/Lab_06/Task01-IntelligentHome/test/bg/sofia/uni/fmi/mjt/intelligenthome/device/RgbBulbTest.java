package bg.sofia.uni.fmi.mjt.intelligenthome.device;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class RgbBulbTest {
    @Test
    void testGetIdReturnsCorrectId() {
        RgbBulb alexa = new RgbBulb("TestBulb", 0, null);
        Assertions.assertTrue(alexa.getId().matches("^BLB-TestBulb-[0-9]+$"),
            "GetId does not return the correct id format.");
    }
}
