package bg.sofia.uni.fmi.mjt.simcity.plot;

import bg.sofia.uni.fmi.mjt.simcity.exception.BuildableAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.simcity.exception.BuildableNotFoundException;
import bg.sofia.uni.fmi.mjt.simcity.exception.InsufficientPlotAreaException;
import bg.sofia.uni.fmi.mjt.simcity.property.buildable.Buildable;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Plot<E extends Buildable> implements PlotAPI<E> {
    private int initialArea;
    private int buildableArea;
    private Map<String, E> addresses;

    public Plot(int buildableArea) {
        initialArea = buildableArea;
        this.buildableArea = buildableArea;
        addresses = new HashMap<>();
    }

    @Override
    public void construct(String address, E buildable) {
        validateBuildable(address, buildable);

        addresses.put(address, buildable);
        buildableArea -= buildable.getArea();
    }

    @Override
    public void constructAll(Map<String, E> buildables) {
        if (buildables == null || buildables.isEmpty()) {
            throw new IllegalArgumentException("Buildables cannot be null or empty.");
        }
        int areaToAllocate = 0;
        for (var pair : buildables.entrySet()) {
            validateBuildable(pair.getKey(), pair.getValue());
            areaToAllocate += pair.getValue().getArea();
        }
        if (areaToAllocate > buildableArea) {
            throw new InsufficientPlotAreaException("Not enough area to build on this plot.");
        }
        for (var pair : buildables.entrySet()) {
            addresses.put(pair.getKey(), pair.getValue());
            buildableArea -= pair.getValue().getArea();
        }
    }

    @Override
    public void demolish(String address) {
        if (address == null || addresses.isEmpty()) {
            throw new IllegalArgumentException("Address cannot be null or empty.");
        }
        E building = addresses.get(address);
        if (building == null) {
            throw new BuildableNotFoundException("Building on address not found.");
        }

        buildableArea += building.getArea();
        addresses.remove(address);
    }

    @Override
    public void demolishAll() {
        addresses.clear();
        buildableArea = initialArea;
    }

    @Override
    public Map<String, E> getAllBuildables() {
        return Map.copyOf(Collections.unmodifiableMap(addresses));
    }

    @Override
    public int getRemainingBuildableArea() {
        return buildableArea;
    }

    private void validateBuildable(String address, E buildable) {
        if (address == null || address.isBlank()) {
            throw new IllegalArgumentException("Address cannot be null or empty.");
        }
        if (buildable == null) {
            throw new IllegalArgumentException("Buildable cannot be null.");
        }

        if (addresses.containsKey(address)) {
            throw new BuildableAlreadyExistsException("Address already taken.");
        }
        if (buildable.getArea() > buildableArea) {
            throw new InsufficientPlotAreaException("Not enough area to build on this plot.");
        }
    }
}
