package bro.Abstraction;

public class Rectangle extends Shape {

    double lenght;
    double width;

    public Rectangle(double lenght, double width) {
        this.lenght = lenght;
        this.width = width;
    }

    @Override
    public double area() {
        return lenght * width;
    }
}
