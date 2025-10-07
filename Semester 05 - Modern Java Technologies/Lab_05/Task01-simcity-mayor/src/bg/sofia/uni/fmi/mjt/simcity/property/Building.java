package bg.sofia.uni.fmi.mjt.simcity.property;

import bg.sofia.uni.fmi.mjt.simcity.property.billable.Billable;
import bg.sofia.uni.fmi.mjt.simcity.property.buildable.Buildable;
import bg.sofia.uni.fmi.mjt.simcity.property.buildable.BuildableType;

public abstract class Building implements Buildable, Billable {

    protected double waterConsumption;
    protected double electricityConsumption;
    protected double gasConsumption;
    protected BuildableType type;
    protected int area;

    public Building(double waterConsumption, double electricityConsumption, double gasConsumption, int area) {
        this.waterConsumption = waterConsumption;
        this.electricityConsumption = electricityConsumption;
        this.gasConsumption = gasConsumption;
        type = null;
        this.area = area;
    }

    @Override
    public double getWaterConsumption() {
        return waterConsumption;
    }

    @Override
    public double getElectricityConsumption() {
        return electricityConsumption;
    }

    @Override
    public double getNaturalGasConsumption() {
        return gasConsumption;
    }

    @Override
    public BuildableType getType() {
        return type;
    }

    @Override
    public int getArea() {
        return area;
    }
}
