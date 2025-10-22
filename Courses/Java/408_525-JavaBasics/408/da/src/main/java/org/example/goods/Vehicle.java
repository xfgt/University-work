package org.example.goods;

public class Vehicle extends Goods{

    private double materialsCost;
    private double salariesCost;

    public Vehicle(double overcharge, double materialsCost, double salariesCost) {
        super(overcharge);
        this.materialsCost = materialsCost;
        this.salariesCost = salariesCost;
    }

    public double getMaterialsCost() {
        return materialsCost;
    }

    public void setMaterialsCost(double materialsCost) {
        this.materialsCost = materialsCost;
    }


    public double getSalariesCost() {
        return salariesCost;
    }

    public void setSalariesCost(double salariesCost) {
        this.salariesCost = salariesCost;
    }

    @Override
    public String toString() {
        return "Vehicle{" +
                "materialsCost=" + materialsCost +
                ", salariesCost=" + salariesCost +
                "} " + super.toString();
    }

    @Override
    public double productionPrice() {
        return this.getMaterialsCost() + this.getSalariesCost();
    }
}
