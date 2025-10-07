package bg.sofia.uni.fmi.mjt.trading;

import bg.sofia.uni.fmi.mjt.trading.price.PriceChartAPI;
import bg.sofia.uni.fmi.mjt.trading.stock.*;
import bg.sofia.uni.fmi.mjt.trading.utils.MathUtils;

import java.time.LocalDateTime;
import java.util.Arrays;

public class Portfolio implements PortfolioAPI{

    private String owner;
    private PriceChartAPI priceChart;
    private double budget;
    private int maxSize;
    private int size;
    private StockPurchase[] stockPurchases;

    public Portfolio(String owner, PriceChartAPI priceChart, double budget, int maxSize) {
        this.owner = owner;
        this.priceChart = priceChart;
        this.budget = budget;
        this.maxSize = maxSize;
        this.size = 0;
        this.stockPurchases = new StockPurchase[maxSize];
    }

    public Portfolio(String owner, PriceChartAPI priceChart, StockPurchase[] stockPurchases, double budget, int maxSize) {
        this.owner = owner;
        this.priceChart = priceChart;
        this.budget = budget;
        this.maxSize = maxSize;
        this.size = stockPurchases.length;
        this.stockPurchases = Arrays.copyOf(stockPurchases, maxSize);
    }

    @Override
    public StockPurchase buyStock(String stockTicker, int quantity) {
        if(stockTicker == null) { return null; }
        if(quantity <= 0) { return null; }
        if(size == maxSize) { return null; }

        StockPurchase stockPurchase;
        switch (stockTicker) {
            case "MSFT" -> stockPurchase = new MicrosoftStockPurchase(quantity,
                    LocalDateTime.now(),
                    priceChart.getCurrentPrice(stockTicker));
            case "AMZ" -> stockPurchase = new AmazonStockPurchase(quantity,
                    LocalDateTime.now(),
                    priceChart.getCurrentPrice(stockTicker));
            case "GOOG" -> stockPurchase = new GoogleStockPurchase(quantity,
                    LocalDateTime.now(),
                    priceChart.getCurrentPrice(stockTicker));
            default -> { return null; }
        }

        if (budget < stockPurchase.getTotalPurchasePrice()) { return null; }

        budget -= stockPurchase.getTotalPurchasePrice();
        stockPurchases[size++] = stockPurchase;
        priceChart.changeStockPrice(stockTicker, 5);
        return stockPurchase;
    }

    @Override
    public StockPurchase[] getAllPurchases() {
        return Arrays.copyOf(stockPurchases, size);
    }

    @Override
    public StockPurchase[] getAllPurchases(LocalDateTime startTimestamp, LocalDateTime endTimestamp) {
        StockPurchase[] stockPurchasesInRange = new StockPurchase[maxSize];
        int index = 0;
        for(int i = 0; i < size; i++)
        {
            if (startTimestamp.isBefore(stockPurchases[i].getPurchaseTimestamp())
            && endTimestamp.isAfter(stockPurchases[i].getPurchaseTimestamp()))
            {
                stockPurchasesInRange[index++] = stockPurchases[i];
            }
        }
        return Arrays.copyOf(stockPurchasesInRange, index);
    }

    @Override
    public double getNetWorth() {
        double netWorth = 0;
        for(int i = 0; i < size; i++)
        {
            netWorth += stockPurchases[i].getQuantity() * priceChart.getCurrentPrice(stockPurchases[i].getStockTicker());
        }
        return MathUtils.round(netWorth,2);
    }

    @Override
    public double getRemainingBudget() {
        return MathUtils.round(budget, 2);
    }

    @Override
    public String getOwner() {
        return owner;
    }
}
