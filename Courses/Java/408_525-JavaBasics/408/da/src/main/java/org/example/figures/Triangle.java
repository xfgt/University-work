package org.example.figures;

public class Triangle extends Figure{

    public Triangle(double dim1, double dim2) {
        super(dim1, dim2);
    }

    @Override
    public double area() {
        return (this.getDim1() *  this.getDim2()) / 2;
    }

}
