package org.example;

import org.example.figures.Figure;
import org.example.figures.Rectangle;
import org.example.figures.Triangle;
import org.example.repo.*;

import java.lang.ref.Cleaner;


public class Main {

    public static void main(String[] args){

        System.out.println("===== THIS IS MAIN =====");

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

            System.out.println();


            Novel novel = new Novel("asdf", author);
            System.out.println(novel);

        }



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
            System.out.println(triangle);;
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
            System.out.printf("\nTotal area: %.2f", figure.totalArea(rectangle)); // else -> [rectangle::area]
        }


    }
}
