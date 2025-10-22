package org.example.Providers;

public class TaxiDriver extends RegisteredProvider{

    private double distanceDriven;
    private double pricePerKilometer;

    public TaxiDriver(String regNumber, double distanceDriven, double pricePerKilometer) {
        super(regNumber); // because it extends Base
        this.distanceDriven = distanceDriven;
        this.pricePerKilometer = pricePerKilometer;
    }


    public double getDistanceDriven() {
        return distanceDriven;
    }

    public void setDistanceDriven(double distanceDriven) {
        this.distanceDriven = distanceDriven;
    }

    public double getPricePerKilometer() {
        return pricePerKilometer;
    }

    public void setPricePerKilometer(double pricePerKilometer) {
        this.pricePerKilometer = pricePerKilometer;
    }

    @Override
    public String toString() {
        return "TaxiDriver{" +
                "distanceDriven=" + distanceDriven +
                ", pricePerKilometer=" + pricePerKilometer +
                "} " + super.toString();
    }

    @Override
    public double earnings() {
        return this.getDistanceDriven() * this.getPricePerKilometer();
    }
}
