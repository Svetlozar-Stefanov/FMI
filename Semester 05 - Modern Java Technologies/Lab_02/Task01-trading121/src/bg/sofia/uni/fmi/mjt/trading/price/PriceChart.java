package bg.sofia.uni.fmi.mjt.trading.price;

import bg.sofia.uni.fmi.mjt.trading.utils.MathUtils;

public class PriceChart implements PriceChartAPI {
    private double microsoftStockPrice;
    private double googleStockPrice;
    private double amazonStockPrice;

    public PriceChart(double microsoftStockPrice, double googleStockPrice, double amazonStockPrice)
    {
        this.microsoftStockPrice = microsoftStockPrice;
        this.googleStockPrice = googleStockPrice;
        this.amazonStockPrice = amazonStockPrice;
    }

    @Override
    public double getCurrentPrice(String stockTicker) {
        if (stockTicker == null) { return 0.0; }
        Double price =  switch (stockTicker) {
            case "MSFT" -> microsoftStockPrice;
            case "GOOG" -> googleStockPrice;
            case "AMZ" -> amazonStockPrice;
            default -> 0.0;
            };
        return MathUtils.round(price, 2);
    }

    @Override
    public boolean changeStockPrice(String stockTicker, int percentChange) {
        if(stockTicker == null) { return  false; }
        if(percentChange <= 0) { return false; }

        switch (stockTicker) {
            case "MSFT" -> { microsoftStockPrice += microsoftStockPrice * percentChange / 100; }
            case "GOOG" -> { googleStockPrice += googleStockPrice * percentChange / 100; }
            case "AMZ" -> { amazonStockPrice += amazonStockPrice * percentChange / 100; }
            default -> { return false; }
        }
        return true;
    }
}
