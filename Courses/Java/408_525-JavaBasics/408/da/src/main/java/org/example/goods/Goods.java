package org.example.goods;

public abstract class Goods implements ItemForSale{
    private double overcharge;
    // продава за 100
    // надценка 5 %
    // крайна цена 105

    public Goods(double overcharge) {
        this.overcharge = overcharge;
    }

    public double getOvercharge() {
        return overcharge;
    }

    public void setOvercharge(double overcharge) {
        this.overcharge = overcharge;
    }

    @Override
    public String toString() {
        return "Goods{" +
                "overcharge=" + overcharge +
                '}';
    }

    // public abstract double productionPrice(); - default by the interface

    @Override
    public double sellingPrice() {
        return this.productionPrice() + this.productionPrice() * this.getOvercharge() / 100;
    }
}
