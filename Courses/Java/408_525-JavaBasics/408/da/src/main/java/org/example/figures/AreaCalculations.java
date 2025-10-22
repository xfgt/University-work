package org.example.figures;

import java.sql.SQLOutput;

public interface AreaCalculations {
    double area(); // implicit (by default is public)

    // all interface member-variables - public static final (constants)
    // You can't have capsulated uninitialized member variables

    public static final int memberVariable = 0;


    public default double totalArea(Figure figure){ // implicit public (by default is public)
        if(validation()){
            return this.area() + figure.area();
        }
        return 0;
    }


    // инстанционен метод не може да бъде static
    /**
     *
     * The static keyword in Java is used to indicate that a member (variable or method)
     * belongs to the class itself rather than to any specific instance of the class.
     *
     * This means that static members are shared among
     * all instances and can be accessed without creating an object of the class.
     */

    static double testStaticReturnHundred() { // implicit public
        System.out.println("AreaCalculations.class");
        return 100;
    }

    // inside methods [private]
    private boolean validation(){
        return true; // for example
    }
}
