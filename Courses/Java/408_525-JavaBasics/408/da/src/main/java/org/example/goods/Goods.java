package org.example.goods;

public abstract class Goods implements ItemForSale{
    private double overcharge;
    // продава за 100
    // надценка 5 %
    // крайна цена 105


    // Хубаво е, когато работим с пари да ползваме BigDecimal (BigD) ;)

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

    // public abstract double productionPrice(); - остава default наследен от интерфейса; затова и 'goods' e abstract;

    @Override
    public double sellingPrice() {
        return this.productionPrice() + this.productionPrice() * this.getOvercharge() / 100;
    }

    @Override
    public double profit(){
        // Със .super. достъпва instance методи на интерфейса
        // Interface.super.<method>
        return ItemForSale.super.profit() + 100; // просто илюстративно
    }
}
