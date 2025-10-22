package org.example;


// oldest_to_newest ( briefly )
import org.example.Boxes.*;
import org.example.Videos.*;
import org.example.Vehicles.*;
import org.example.goods.Vehicle;
import org.example.recordables.*;

import org.example.figures.*;
import org.example.repo.*;
import org.example.goods.*;
import org.example.Providers.*;



public class Main {

    public static void main(String[] args){

        System.out.println("===== THIS IS MAIN =====");

        // Note: Some examples in main are skipped


        // Scope #1 (repo)
        {

            Document d1 = new Document();
            Document d2 = new Document("Doc 2", "pdf", 5);
            System.out.println(d1);
            System.out.println(d2);

            System.out.println();


            Author author = new Author("Dostoevsky");
            Book b1 = new Book("123-456", author);
            Book b2 = new Book("Book 2", "txt", 3,"6544-9842", author);
            System.out.println(b1);
            System.out.println(b2);


            Repository repository = new Repository(10);
            System.out.println(repository);


            Novel novel = new Novel("asdf", author);
            System.out.println(novel);

        }
        System.out.println();

        // Scope #2 (figures)
        {
            Figure fig = new Figure(4,5) {
                @Override
                public double area() {
                    return 1+2;
                } // this is local. (only for "fig"
            };

            Figure figure;
            Triangle triangle = new Triangle(10, 6);
            System.out.println(triangle);
            System.out.println(triangle.area());

            Rectangle rectangle = new Rectangle(4, 5);
            System.out.println(rectangle);
            System.out.println(rectangle.area());


            // base casting down to...

            figure = triangle; // triangle
            System.out.println(figure);
            System.out.println(figure.area());



            figure = rectangle; // rectangle
            System.out.println(figure);
            System.out.println(figure.area());


            figure = triangle; // this.area()  [triangle::area];
            System.out.printf("Total area: %.2f\n", figure.totalArea(rectangle)); // else -> [rectangle::area]
        }
        System.out.println();

        // Scope #3 (goods)
        {
            ItemForSale itemForSale;
            Goods goods;

            org.example.goods.Vehicle vehicle = new Vehicle(10, 3000, 2000); // not org.example.Vehicles.*; ...
            System.out.println(vehicle);

            System.out.println(vehicle.productionPrice());  // 5000.0
            System.out.println(vehicle.sellingPrice());     // 5500.0


            itemForSale = vehicle; // (virtual) Base* -> &derived (C++)
            System.out.println(itemForSale.productionPrice());
            System.out.println(itemForSale.sellingPrice());


        }
        System.out.println();


        // Scope #4 (providers)
        {
            Provider provider;
            RegisteredProvider registeredProvider;



            Engineer engineer = new Engineer(200, 40);
            System.out.println(engineer);



            TaxiDriver taxiDriver = new TaxiDriver("20120120", 500, 3);
            System.out.println(taxiDriver);






        }


        System.out.println();




    }
}
