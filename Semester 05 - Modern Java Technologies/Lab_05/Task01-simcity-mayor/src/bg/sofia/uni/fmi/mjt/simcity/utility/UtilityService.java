package bg.sofia.uni.fmi.mjt.simcity.utility;

import bg.sofia.uni.fmi.mjt.simcity.property.billable.Billable;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class UtilityService implements UtilityServiceAPI {
    private Map<UtilityType, Double> taxRates;
    public UtilityService(Map<UtilityType, Double> taxRates) {
        this.taxRates = taxRates;
    }

    @Override
    public <T extends Billable> double getUtilityCosts(UtilityType utilityType, T billable) {
        if (utilityType == null) {
            throw new IllegalArgumentException("UtilityType cannot be null.");
        }
        if (billable == null) {
            throw new IllegalArgumentException("Billable cannot be null.");
        }

        Double taxRate = taxRates.get(utilityType);
        switch (utilityType) {
            case WATER -> {
                return  taxRate * billable.getWaterConsumption();
            }
            case ELECTRICITY -> {
                return taxRate * billable.getElectricityConsumption();
            }
            case NATURAL_GAS -> {
                return taxRate * billable.getNaturalGasConsumption();
            }
        }
        throw new IllegalArgumentException("Utility type does not exist.");
    }

    @Override
    public <T extends Billable> double getTotalUtilityCosts(T billable) {
        if (billable == null) {
            throw new IllegalArgumentException("Billable cannot be null.");
        }

        Double utiliyCosts = 0.0;
        for (var type : UtilityType.values()) {
            utiliyCosts += getUtilityCosts(type, billable);
        }

        return utiliyCosts;
    }

    @Override
    public <T extends Billable> Map<UtilityType, Double> computeCostsDifference(T firstBillable, T secondBillable) {
        if (firstBillable == null || secondBillable == null) {
            throw new IllegalArgumentException("Billable cannot be null.");
        }

        Map<UtilityType, Double> costDifference = new HashMap<>();

        for (var type : UtilityType.values()) {
            Double differance = Math.abs(getUtilityCosts(type, firstBillable) - getUtilityCosts(type, secondBillable));
            costDifference.put(type, differance);
        }

        return Collections.unmodifiableMap(costDifference);
    }
}
