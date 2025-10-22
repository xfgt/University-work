package org.example.goods;

public class Vehicle extends Goods{

    private double materialCost;
    private double salariesCost;

    public Vehicle(double overcharge, double materialCost, double salariesCost) {
        super(overcharge);
        this.materialCost = materialCost;
        this.salariesCost = salariesCost;
    }

    public double getMaterialCost() {
        return materialCost;
    }



    public void setMaterialCost(double materialCost) {
        this.materialCost = materialCost;
    }

    public double getSalariesCost() {
        return salariesCost;
    }

    public void setSalariesCost(double salariesCost) {
        this.salariesCost = salariesCost;
    }

    @Override
    public double productionPrice() {
        return this.getMaterialCost() + this.getSalariesCost();
    }
}
