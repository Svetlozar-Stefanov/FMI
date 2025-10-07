package bg.sofia.uni.fmi.mjt.gym.member;

public record Address(double longitude, double latitude) {
    public double getDistanceTo(Address other) {
        return Math.hypot(longitude - other.longitude, latitude - other.latitude);
    }
}
