package bg.sofia.uni.fmi.mjt.intelligenthome.center;

import bg.sofia.uni.fmi.mjt.intelligenthome.center.exceptions.DeviceAlreadyRegisteredException;
import bg.sofia.uni.fmi.mjt.intelligenthome.center.exceptions.DeviceNotFoundException;
import bg.sofia.uni.fmi.mjt.intelligenthome.device.DeviceType;
import bg.sofia.uni.fmi.mjt.intelligenthome.device.IoTDevice;
import bg.sofia.uni.fmi.mjt.intelligenthome.storage.DeviceStorage;
import bg.sofia.uni.fmi.mjt.intelligenthome.storage.MapDeviceStorage;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import javax.swing.plaf.PanelUI;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.Mockito.atLeast;
import static org.mockito.Mockito.atLeastOnce;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

class IntelligentHomeCenterTest {
    @Test
    void testRegisterWithInvalidDevice() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        Assertions.assertThrows(IllegalArgumentException.class, () -> center.register(null),
            "Register accepted invalid argument.");
    }

    @Test
    void testSuccessfulRegistration() {
        DeviceStorage storage = new MapDeviceStorage();

        IoTDevice device = mock();
        when(device.getId()).thenReturn("shortName-longName-0");

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        center.register(device);

        Assertions.assertTrue(storage.exists(device.getId()));

        verify(device, atLeastOnce()).getId();
    }

    @Test
    void testRegisteringAlreadyExistingDevice() {
        DeviceStorage storage = new MapDeviceStorage();

        IoTDevice device1 = mock();
        when(device1.getId()).thenReturn("shortName-longName-0");

        IoTDevice device2 = mock();
        when(device2.getId()).thenReturn("shortName-longName-0");

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        center.register(device1);

        Assertions.assertThrows(DeviceAlreadyRegisteredException.class, () -> center.register(device2),
            "Register should not allow adding existing devices.");

        verify(device1, atLeastOnce()).getId();
        verify(device2, atLeastOnce()).getId();
    }

    @Test
    void testUnregisterWithNullDevice() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        Assertions.assertThrows(IllegalArgumentException.class, () -> center.unregister(null),
            "Unregister should not accept null arguments.");
        verify(storage, never()).delete(anyString());
    }

    @Test
    void testUnregisterWithNonExistentDevice() {
        DeviceStorage storage = mock();
        when(storage.exists(anyString())).thenReturn(false);

        IoTDevice device = mock();
        when(device.getId()).thenReturn("shortName-longName-0");

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        Assertions.assertThrows(DeviceNotFoundException.class, () -> center.unregister(device),
            "Does not throw when trying to unregister non-existent device.");

        verify(storage, atLeastOnce()).exists(anyString());
        verify(device, atLeastOnce()).getId();
    }

    @Test
    void testSuccessfulUnregister() {
        DeviceStorage storage = new MapDeviceStorage();
        IoTDevice device = mock();
        when(device.getId()).thenReturn("shortName-longName-0");

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        center.register(device);
        Assertions.assertDoesNotThrow(() -> center.unregister(device));
        Assertions.assertTrue(!storage.exists(device.getId()));

        verify(device, atLeast(3)).getId();
    }

    @Test
    void testGetDeviceByIdWithNull() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getDeviceById(null),
            "GetDeviceById should not accept null.");
    }

    @Test
    void testGetDeviceByIdWithNonExistentDevice() {
        DeviceStorage storage = mock();
        when(storage.exists(anyString())).thenReturn(false);

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        Assertions.assertThrows(DeviceNotFoundException.class, () -> center.getDeviceById("shortName-longName-0"),
            "GetDeviceById should not return non-existent device.");

        verify(storage, atLeastOnce()).exists(anyString());
    }

    @Test
    void testSuccessfulGetDeviceById() {
        DeviceStorage storage = new MapDeviceStorage();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        IoTDevice device = mock();
        when(device.getId()).thenReturn("longName-shortName-0");

        center.register(device);
        Assertions.assertEquals(device, center.getDeviceById("longName-shortName-0"),
            "GetDeviceById did not return correct device.");

        verify(device, atLeastOnce()).getId();
    }

    @Test
    void testGetDeviceQuantityPerTypeWithNull() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getDeviceQuantityPerType(null),
            "GetDeviceQuantityPerType should not accept null.");
    }

    @Test
    void testSuccessfulDeviceQuantityPerType() {
        DeviceStorage storage = mock();

        IoTDevice device1 = mock();
        when(device1.getType()).thenReturn(DeviceType.SMART_SPEAKER);
        IoTDevice device2 = mock();
        when(device2.getType()).thenReturn(DeviceType.SMART_SPEAKER);
        IoTDevice device3 = mock();
        when(device3.getType()).thenReturn(DeviceType.THERMOSTAT);
        IoTDevice device4 = mock();
        when(device4.getType()).thenReturn(DeviceType.THERMOSTAT);
        IoTDevice device5 = mock();
        when(device5.getType()).thenReturn(DeviceType.THERMOSTAT);
        IoTDevice device6 = mock();
        when(device6.getType()).thenReturn(DeviceType.BULB);

        when(storage.listAll()).thenReturn(
            Arrays.asList(device1, device2, device3, device4, device5, device6));

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        Assertions.assertEquals(2, center.getDeviceQuantityPerType(DeviceType.SMART_SPEAKER),
            "Does not return correct quantity.");
        Assertions.assertEquals(3, center.getDeviceQuantityPerType(DeviceType.THERMOSTAT),
            "Does not return correct quantity.");
        Assertions.assertEquals(1, center.getDeviceQuantityPerType(DeviceType.BULB),
            "Does not return correct quantity.");
    }

    @Test
    void testGetTopNDevicesByPowerConsumptionWithNegativeOrZero() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getTopNDevicesByPowerConsumption(-1),
            "GetTopNDevicesByPowerConsumptionWithNegative should not accept negative arguments.");
        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getTopNDevicesByPowerConsumption(0),
            "GetTopNDevicesByPowerConsumptionWithNegative should not accept zero.");
    }

    @Test
    void testSuccessfulGetTopNDevicesByPowerConsumption() {
        DeviceStorage storage = new MapDeviceStorage();

        IoTDevice device1 = mock();
        when(device1.getId()).thenReturn("1-1-1");
        when(device1.getPowerConsumptionKWh()).thenReturn(10L);
        IoTDevice device2 = mock();
        when(device2.getId()).thenReturn("2-2-2");
        when(device2.getPowerConsumptionKWh()).thenReturn(23L);
        IoTDevice device3 = mock();
        when(device3.getId()).thenReturn("3-3-3");
        when(device3.getPowerConsumptionKWh()).thenReturn(40L);
        IoTDevice device4 = mock();
        when(device4.getId()).thenReturn("4-4-4");
        when(device4.getPowerConsumptionKWh()).thenReturn(50L);
        IoTDevice device5 = mock();
        when(device5.getId()).thenReturn("5-5-5");
        when(device5.getPowerConsumptionKWh()).thenReturn(5L);
        IoTDevice device6 = mock();
        when(device6.getId()).thenReturn("6-6-6");
        when(device6.getPowerConsumptionKWh()).thenReturn(8L);

        storage.store(device1.getId(), device1);
        storage.store(device2.getId(), device2);
        storage.store(device3.getId(), device3);
        storage.store(device4.getId(), device4);
        storage.store(device5.getId(), device5);
        storage.store(device6.getId(), device6);

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        List<String> devices = new ArrayList<>(center.getTopNDevicesByPowerConsumption(10));
        Assertions.assertEquals(storage.listAll().size() ,devices.size(),
            "When n above number of elements did not return all elements");
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(center.getDeviceById(devices.get(i)).getPowerConsumptionKWh()
                > center.getDeviceById(devices.get(i+1)).getPowerConsumptionKWh(),
                "Incorrect ordering.");
        }

        devices = new ArrayList<>(center.getTopNDevicesByPowerConsumption(6));
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(center.getDeviceById(devices.get(i)).getPowerConsumptionKWh()
                    > center.getDeviceById(devices.get(i+1)).getPowerConsumptionKWh(),
                "Incorrect ordering.");
        }

        devices = new ArrayList<>(center.getTopNDevicesByPowerConsumption(3));
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(center.getDeviceById(devices.get(i)).getPowerConsumptionKWh()
                    > center.getDeviceById(devices.get(i+1)).getPowerConsumptionKWh(),
                "Incorrect ordering.");
        }

        List<IoTDevice> all = new ArrayList<>(storage.listAll());
        for (int i = 0; i < all.size(); i++) {
            Assertions.assertTrue(storage.get(devices.get(0)).getPowerConsumptionKWh()
                    >= all.get(i).getPowerConsumptionKWh(),
                "Incorrect ordering.");
        }
    }

    @Test
    void testGetFirstNDevicesByRegistrationWithNegativeOrZero() {
        DeviceStorage storage = mock();
        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);
        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getFirstNDevicesByRegistration(-1),
            "GetTopNDevicesByPowerConsumptionWithNegative should not accept negative arguments.");
        Assertions.assertThrows(IllegalArgumentException.class, () -> center.getFirstNDevicesByRegistration(0),
            "GetTopNDevicesByPowerConsumptionWithNegative should not accept zero.");
    }

    @Test
    void testSuccessfulGetFirstNDevicesByRegistration() {
        DeviceStorage storage = new MapDeviceStorage();

        IoTDevice device1 = mock();
        when(device1.getId()).thenReturn("1-1-1");
        when(device1.getRegistration()).thenReturn(4L);
        IoTDevice device2 = mock();
        when(device2.getId()).thenReturn("2-2-2");
        when(device2.getRegistration()).thenReturn(5L);
        IoTDevice device3 = mock();
        when(device3.getId()).thenReturn("3-3-3");
        when(device3.getRegistration()).thenReturn(10L);
        IoTDevice device4 = mock();
        when(device4.getId()).thenReturn("4-4-4");
        when(device4.getRegistration()).thenReturn(20L);
        IoTDevice device5 = mock();
        when(device5.getId()).thenReturn("5-5-5");
        when(device5.getRegistration()).thenReturn(100L);
        IoTDevice device6 = mock();
        when(device6.getId()).thenReturn("6-6-6");
        when(device6.getRegistration()).thenReturn(1L);

        storage.store(device1.getId(), device1);
        storage.store(device2.getId(), device2);
        storage.store(device3.getId(), device3);
        storage.store(device4.getId(), device4);
        storage.store(device5.getId(), device5);
        storage.store(device6.getId(), device6);

        IntelligentHomeCenter center = new IntelligentHomeCenter(storage);

        List<IoTDevice> devices = new ArrayList<>(center.getFirstNDevicesByRegistration(10));
        Assertions.assertEquals(storage.listAll().size() ,devices.size(),
            "When n above number of elements did not return all elements");
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(devices.get(i).getRegistration()
                    >= devices.get(i+1).getRegistration(),
                "Incorrect ordering.");
        }

        devices = new ArrayList<>(center.getFirstNDevicesByRegistration(6));
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(devices.get(i).getRegistration()
                    > devices.get(i+1).getRegistration(),
                "Incorrect ordering.");
        }

        devices = new ArrayList<>(center.getFirstNDevicesByRegistration(3));
        for (int i = 0; i < devices.size() - 1; i++) {
            Assertions.assertTrue(devices.get(i).getRegistration()
                > devices.get(i+1).getRegistration(),
                "Incorrect ordering.");
        }
        List<IoTDevice> all = new ArrayList<>(storage.listAll());
        for (int i = 0; i < all.size(); i++) {
            Assertions.assertTrue(devices.get(0).getRegistration()
                    >= all.get(i).getRegistration(),
                "Incorrect ordering.");
        }
    }
}
