package bg.sofia.uni.fmi.mjt.simcity.property;

import bg.sofia.uni.fmi.mjt.simcity.property.buildable.BuildableType;

public class InfrastructureBuilding extends Building {
    public InfrastructureBuilding(double waterConsumption,
                                  double electricityConsumption,
                                  double gasConsumption,
                                  int area) {
        super(waterConsumption, electricityConsumption, gasConsumption, area);
        type = BuildableType.INFRASTRUCTURE;
    }
}
