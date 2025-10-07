package bg.sofia.uni.fmi.mjt.intelligenthome.device;

import java.time.LocalDateTime;

public interface IoTDevice {
    /**
     * Returns the ID of the device.
     */
    String getId();

    /**
     * Returns the name of the device.
     */
    String getName();

    /**
     * Returns the power consumption of the device. For example, a bulb may consume
     * 30W/hour.
     */
    double getPowerConsumption();

    /**
     * Returns the date and time of device installation. This is a time in the past
     * when the device was 'physically' installed. It is not related to the time
     * when the device is registered in the Home.
     */
    LocalDateTime getInstallationDateTime();

    /**
     * Returns the type of the device.
     */
    DeviceType getType();

    /**
     * Returns the duration since registration
     */
    public long getRegistration();

    /**
     * Setter for registration time
     * @param registration
     * @throws IllegalArgumentException when registration is null
     */
    public void setRegistration(LocalDateTime registration);

    /**
     * Returns the power consumption since physical installation
     */
    public long getPowerConsumptionKWh();
}
