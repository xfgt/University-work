package org.example.Vehicles;



// TODO: Дефинирай композиция, агрегация, асоциация (lecture week2 36:00)
// TODO: hint -> Единия обект е съставна част на другия
// TODO: Гледа се съставната част;

public class Vehicle {

    private double engineVolume;
    private Engine engine;

    public Vehicle(double engineVolume, Engine engine) {
        this.engineVolume = engineVolume;
        this.engine = engine;
    }

    public double getEngineVolume() {
        return engineVolume;
    }

    public void setEngineVolume(double engineVolume) {
        this.engineVolume = engineVolume;
    }

    public Engine getEngine() {
        return engine;
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    @Override
    public String toString() {
        return "Vehicle{" +
                "engineVolume=" + engineVolume +
                ", engine=" + engine +
                '}';
    }
}
