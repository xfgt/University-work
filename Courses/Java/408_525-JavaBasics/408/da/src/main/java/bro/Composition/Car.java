package bro.Composition;

public class Car {

    public String model;
    public int year;
    public Engine engine;

    public Car(String model, int year, String engineType) {
        this.model = model;
        this.year = year;
        this.engine = new Engine(engineType);
    }

    public void start(){
        this.engine.start();
        System.out.println("The " + model + " is running.");
    }
}
