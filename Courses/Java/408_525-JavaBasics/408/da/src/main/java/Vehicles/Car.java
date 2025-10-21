package Vehicles;

import java.beans.VetoableChangeListener;

public class Car extends Vehicle{
    private boolean isWagon;
    private Vehicle vehicle;

    public Car(Engine engine, boolean isWagon) {
        super(engine);
        this.isWagon = isWagon;
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
