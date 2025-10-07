import bg.sofia.uni.fmi.mjt.trading.price.PriceChart;

public class Main {
    public static void main(String[] args) {
        PriceChart priceChart = new PriceChart(3,3,3);
        System.out.println(priceChart.getCurrentPrice(null));
    }
}