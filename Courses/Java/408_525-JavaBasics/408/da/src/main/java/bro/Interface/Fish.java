package bro.Interface;

public class Fish implements Prey, Predator{
    @Override
    public void hunt() {
        System.out.println("* Big fish ate the smaller fish. *");
    }

    @Override
    public void flee() {
        System.out.println("* The fish swam away! *");
    }
}
