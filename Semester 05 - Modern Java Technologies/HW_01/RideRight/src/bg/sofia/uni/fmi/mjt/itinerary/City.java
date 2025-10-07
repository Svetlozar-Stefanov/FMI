package bg.sofia.uni.fmi.mjt.itinerary;

public record City(String name, Location location) {
    public int distanceTo(City other) {
        return Math.abs(location.x() - other.location.x()) + Math.abs(location.y() - other.location.y());
    }
}
