package bro.Composition;

public class Engine {

    public String type;

    public Engine(String engineType) {
        type = engineType;
    }

    public void start(){
        System.out.println("You start the " + this.type + " engine");;
    }
}
