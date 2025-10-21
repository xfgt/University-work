package org.example.figures;

public class Rectangle extends Figure{


    public Rectangle(double dim1, double dim2) {
        super(dim1, dim2);
    }

    @Override
    public double area() {
        return (this.getDim1() * getDim2());
    }
}
