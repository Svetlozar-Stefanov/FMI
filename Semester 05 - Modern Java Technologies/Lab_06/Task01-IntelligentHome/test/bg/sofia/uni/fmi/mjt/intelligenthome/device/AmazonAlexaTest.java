package bg.sofia.uni.fmi.mjt.intelligenthome.device;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;

class AmazonAlexaTest {
    @Test
    void testGetIdReturnsCorrectId() {
        AmazonAlexa alexa = new AmazonAlexa("TestSpeaker", 0, null);
        Assertions.assertTrue(alexa.getId().matches("^SPKR-TestSpeaker-[0-9]+$"),
            "GetId does not return the correct id format.");
    }
}
