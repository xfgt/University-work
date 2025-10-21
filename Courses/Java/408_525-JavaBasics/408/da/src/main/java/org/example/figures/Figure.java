package org.example.figures;

import java.awt.geom.Area;

public abstract class Figure implements AreaCalculations { // to have abstract methods
    private double dim1; // dimension
    private double dim2; // dimension

    public Figure(double dim1, double dim2) {
        this.dim1 = dim1;
        this.dim2 = dim2;
    }

    public double getDim1() {
        return dim1;
    }

    public void setDim1(double dim1) {
        this.dim1 = dim1;
    }

    public double getDim2() {
        return dim2;
    }

    public void setDim2(double dim2) {
        this.dim2 = dim2;
    }

    @Override
    public String toString() {
        return "Figure{" +
                "dim1=" + dim1 +
                ", dim2=" + dim2 +
                '}';
    }


    // area ( without interface )
//        public abstract double area();
//        public double totalArea(Figure figure1, Figure figure2) {
//              return figure1.area() + figure2.area();
//
//        }


//    @Override
//    // after defining interface
//    public double totalArea(Figure figure2){
//        return this.area() + figure2.area();
//    }



}
