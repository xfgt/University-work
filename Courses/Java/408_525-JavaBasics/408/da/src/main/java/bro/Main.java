package bro;

import bro.Composition.Car;
import bro.Composition.Engine;
import bro.Interface.*;
//import bro.Abstraction.*;

import bro.Aggregation.*;




//import bro.Polymorphism.extending.*;
import bro.Polymorphism.implementing.*;
import bro.Polymorphism.dynamic.*;





public class Main {
    public static void main(String[] args){


        //  Abstraction
        /*{
            Circle circle = new Circle(3);
            Triangle triangle = new Triangle(4, 5);
            Rectangle rectangle = new Rectangle(6, 7);


            circle.display();
            triangle.display();
            triangle.display();

            System.out.println(circle.area());
            System.out.println(triangle.area());
            System.out.println(rectangle.area());
        }*/
        System.out.println();

        //  Interface
        /*{
            Rabbit rabbit = new Rabbit();
            rabbit.flee();

            Hawk hawk = new Hawk();
            hawk.hunt();

            Fish fish = new Fish();
            fish.flee();
            fish.hunt();
        }*/
        System.out.println();


        // Polymorphism
        /*{
            Car car = new Car();
            Bike bike = new Bike();
            Boat boat = new Boat();


            bike.go();
            boat.go();
            car.go();

            System.out.println();

            // Car[] cars = {car, bike, boat}; // incompatible types
            // We need a basic type.

            Vehicle[] vehicles = {car, bike, boat};
            for (Vehicle i : vehicles)
                i.go();

            // much better

        }
        System.out.println();
*/

        // Polymorphism [runtime, dynamic]
        /*{

            // can't go Animal animal = new Animal();
            // but we can create it without instantiating it;


            Animal animalObject;

            int CHANGEME = 2;

            switch (CHANGEME){

                default:
                    animalObject = null;
                    break;

                case 1:
                    animalObject = new Dog();
                    break;
                case 2:
                    animalObject = new Cat();
                    break;
            }

            if(!animalObject.equals(null))
                animalObject.speak();





        }*/
        System.out.println();


        // Aggregation (is-a)
        /*{
            Book book1 = new Book("Lord of the rings 1", 423);
            Book book2 = new Book("The Bible", 1200);
            Book book3 = new Book("Pod Igoto", 300);


            Book[] books = {book1, book2, book3};

            for (Book i : books)
                System.out.println(i.displayInfo());

            // After defining Library, this is where aggregation comes in...
            Library library = new Library("Kiril i Metodii", 1878, books);
            // library object has book objects
            library.displayInfo();


            // If we delete the Library type, the books will still exist.

        }*/
        System.out.println();


        // Composition
        /*{
            Car car = new Car("Volvo", 1999, "V6");

            System.out.println(car.model);
            System.out.println(car.year);
            System.out.println(car.engine.type);

            car.start();

            // So now in COMPOSITION, if we manage to delete the Car object, we are not able to access the engine.

        }*/
        System.out.println();




























    }
}
