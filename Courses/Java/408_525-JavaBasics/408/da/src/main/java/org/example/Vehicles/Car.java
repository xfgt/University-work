package org.example.Vehicles;

public class Car extends Vehicle{
    private boolean isWagon;
    private Vehicle vehicle;

    public Car(double engineVolume, Engine engine, boolean isWagon, Vehicle vehicle) {
        super(engineVolume, engine);
        this.isWagon = isWagon;
        this.vehicle = vehicle;
    }

    public boolean isWagon() {
        return isWagon;
    }

    public void setWagon(boolean wagon) {
        isWagon = wagon;
    }

    @Override
    public String toString() {
        return super.toString() + "Car{" +
                "isWagon=" + isWagon +
                '}';
    }
}
