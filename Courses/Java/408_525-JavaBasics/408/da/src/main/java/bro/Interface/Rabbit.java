package bro.Interface;

public class Rabbit implements Prey {


    @Override
    public void flee() {
        System.out.println("* Rabbit runs away! * ");
    }
}
