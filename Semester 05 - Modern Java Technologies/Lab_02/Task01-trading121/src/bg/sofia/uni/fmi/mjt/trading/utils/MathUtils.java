package bg.sofia.uni.fmi.mjt.trading.utils;

public class MathUtils {
    public static double round(double num, int pos)
    {
        return Math.round(num * Math.pow(10, pos)) / 100.0;
    }
}
