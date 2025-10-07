package bg.sofia.uni.fmi.mjt.itinerary;

import bg.sofia.uni.fmi.mjt.itinerary.exception.CityNotKnownException;
import bg.sofia.uni.fmi.mjt.itinerary.exception.NoPathToDestinationException;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.SequencedCollection;
import java.util.Set;

public class RideRight implements ItineraryPlanner {
    private record CityNodeData(Journey arrivedFrom, BigDecimal totalPrice, int distanceFromDestination) {
    }

    private Map<City, List<Journey>> schedule;
    private Map<City, CityNodeData> cityData;

    private class CityPriceComparator implements Comparator<City> {

        @Override
        public int compare(City o1, City o2) {
            var d1 = cityData.get(o1);
            var d2 = cityData.get(o2);

            BigDecimal w1 = d1.totalPrice().add(BigDecimal.valueOf(d1.distanceFromDestination()));
            BigDecimal w2 = d2.totalPrice().add(BigDecimal.valueOf(d2.distanceFromDestination()));

            if (w1.equals(w2)) {
                return o1.name().compareTo(o2.name());
            }

            return w1.compareTo(w2);
        }
    }

    public RideRight(List<Journey> schedule) {
        this.schedule = new HashMap<>();
        cityData = new HashMap<>();
        for (var journey : schedule) {
            if (!this.schedule.containsKey(journey.from())) {
                this.schedule.put(journey.from(), new ArrayList<>(Arrays.asList(journey)));
                continue;
            }

            this.schedule.get(journey.from()).add(journey);
        }
    }

    private SequencedCollection<Journey> findCheapestPathWithoutTransfers(City start, City destination)
        throws NoPathToDestinationException {
        for (var journey : schedule.get(start)) {
            if (journey.to().equals(destination)) {
                return Arrays.asList(journey);
            }
        }
        throw new NoPathToDestinationException("Could not find a path to destination.");
    }

    private SequencedCollection<Journey> getPath(CityNodeData destinationData) {
        SequencedCollection<Journey>  path = new ArrayList<>();

        Journey edge = destinationData.arrivedFrom;
        while (edge != null) {
            path.addFirst(edge);
            edge = cityData.get(edge.from()).arrivedFrom;
        }
        return path;
    }

    private void processNeighbouringCities(City current, CityNodeData currentData, City destination,
                                           PriorityQueue<City> citiesToVisit, Set<City> alreadyVisitedCities) {
        for (var journey : schedule.get(current)) {
            BigDecimal tax = journey.vehicleType().getGreenTax();
            BigDecimal taxAmount = journey.price().multiply(tax);
            BigDecimal price = journey.price().add(taxAmount);

            City neighbour = journey.to();
            if (!citiesToVisit.contains(neighbour) && !alreadyVisitedCities.contains(neighbour)) {
                cityData.put(neighbour, new CityNodeData(
                    journey,
                    currentData.totalPrice().add(price),
                    neighbour.distanceTo(destination))
                );
                citiesToVisit.add(journey.to());
            } else {
                if ((currentData.totalPrice().add(price)).compareTo(cityData.get(neighbour).totalPrice()) < 0) {
                    cityData.put(journey.to(), new CityNodeData(
                        journey,
                        currentData.totalPrice().add(price),
                        neighbour.distanceTo(destination))
                    );

                    if (alreadyVisitedCities.contains(neighbour)) {
                        alreadyVisitedCities.remove(journey.to());
                        citiesToVisit.add(journey.to());
                    }
                }
            }
        }
    }

    private SequencedCollection<Journey> findCheapestPathWithTransfers(City start, City destination)
        throws NoPathToDestinationException {
        PriorityQueue<City> citiesToVisit = new PriorityQueue<>(new CityPriceComparator().reversed());
        Set<City> alreadyVisitedCities = new HashSet<>();

        cityData.put(start,
            new CityNodeData(
                null,
                new BigDecimal(0),
                start.distanceTo(destination))
        );

        citiesToVisit.add(start);

        while (!citiesToVisit.isEmpty()) {
            City current = citiesToVisit.poll();
            CityNodeData currentData = cityData.get(current);

            if (current.equals(destination)) {
                return getPath(currentData);
            }

            processNeighbouringCities(current, currentData, destination, citiesToVisit, alreadyVisitedCities);

            citiesToVisit.remove(current);
            alreadyVisitedCities.add(current);
        }

        throw new NoPathToDestinationException("Could not find a path to destination.");
    }

    @Override
    public SequencedCollection<Journey> findCheapestPath(City start, City destination, boolean allowTransfer)
        throws CityNotKnownException, NoPathToDestinationException {

        if (!schedule.containsKey(start) || !schedule.containsKey(destination)) {
            throw new CityNotKnownException("Start and destination should be valid cities.");
        }

        if (!allowTransfer) {
            return findCheapestPathWithoutTransfers(start, destination);
        }
        return findCheapestPathWithTransfers(start, destination);
    }
}
