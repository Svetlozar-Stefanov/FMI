package bg.sofia.uni.fmi.mjt.intelligenthome.device;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class WiFiThermostatTest {
    @Test
    void testGetIdReturnsCorrectId() {
        WiFiThermostat alexa = new WiFiThermostat("TestThermostat", 0, null);
        Assertions.assertTrue(alexa.getId().matches("^TMST-TestThermostat-[0-9]+$"),
            "GetId does not return the correct id format.");
    }
}
