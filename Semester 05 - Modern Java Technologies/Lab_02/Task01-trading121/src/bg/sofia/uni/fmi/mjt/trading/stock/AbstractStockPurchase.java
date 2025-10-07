package bg.sofia.uni.fmi.mjt.trading.stock;

import bg.sofia.uni.fmi.mjt.trading.utils.MathUtils;

import java.time.LocalDateTime;

public abstract class AbstractStockPurchase implements StockPurchase{
    private int quantity;
    LocalDateTime purchaseTimestamp;
    double purchasePricePerUnit;

    AbstractStockPurchase(int quantity, LocalDateTime purchaseTimestamp, double purchasePricePerUnit)
    {
        this.quantity = quantity;
        this.purchaseTimestamp = purchaseTimestamp;
        this.purchasePricePerUnit = purchasePricePerUnit;
    }

    @Override
    public int getQuantity() {
        return  quantity;
    }

    @Override
    public LocalDateTime getPurchaseTimestamp() {
        return purchaseTimestamp;
    }

    @Override
    public double getPurchasePricePerUnit() {
        return MathUtils.round(purchasePricePerUnit, 2);
    }

    @Override
    public double getTotalPurchasePrice() {
        return MathUtils.round(purchasePricePerUnit * quantity, 2);
    }
}
