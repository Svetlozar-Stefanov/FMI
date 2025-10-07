package bg.sofia.uni.fmi.mjt.intelligenthome.device;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.platform.commons.util.AnnotationUtils;

import java.time.Duration;
import java.time.LocalDateTime;

class IoTDeviceBaseTest {
    @Test
    void testGetRegistrationReturnsCorrectDuration() {
        IoTDeviceBase baseDevice = new AmazonAlexa("Test", 0, LocalDateTime.MIN);
        baseDevice.setRegistration(LocalDateTime.MIN);
        Assertions.assertEquals(baseDevice.getRegistration(), Duration.between(LocalDateTime.MIN, LocalDateTime.now()).toHours(),
            "Duration since installation not calculated properly.");
    }

    @Test
    void testSetRegistrationWithInvalidDateTime() {
        IoTDeviceBase baseDevice = new AmazonAlexa("Test", 0, LocalDateTime.MIN);
        Assertions.assertThrows(IllegalArgumentException.class, () -> { baseDevice.setRegistration(null); },
            "SetRegistration accepts invalid arguments.");
    }

    @Test
    void testGetPowerConsumptionKWhReturnsCorrectConsumption() {
        IoTDeviceBase baseDevice = new AmazonAlexa("Test", 30.50, LocalDateTime.MIN);
        long consumption =
            (long)(Duration.between(LocalDateTime.MIN, LocalDateTime.now()).toHours()
            * 30.50);
        Assertions.assertEquals(baseDevice.getPowerConsumptionKWh(), consumption,
            "GetPowerConumptionKWh does not return proper calculations.");
    }
}
