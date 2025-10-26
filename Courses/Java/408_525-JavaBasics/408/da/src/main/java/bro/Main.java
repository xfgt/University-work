package bro;

//import bro.Abstraction.*;


//import bro.Polymorphism.extending.*;
import bro.Threading.MyRunnable1.MyRunnable1;
import bro.Threading.MyRunnable2.MyRunnable2;

import java.io.*;
        import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws IOException {


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


        // Wrappers
        /*{
            // Autoboxing
            Integer a = 123;
            Double b = 3.14;
            Character c = '$';
            Boolean d = true;

            String e = "Whatever";



            // Unboxing
            int x = a; // double, char, boolean


            // toString
            String convert = Integer.toString(1234); // Double, Character
            String convBool = Boolean.toString(false);
            String _x_ = convert + convBool; // 1234false

            // Parsing
            int asf = Integer.parseInt("123"); // Double.parseDouble, ...

            // asf + 1 = 124;


            // Character, String

            char letter = 't';
            // boolean j = Character.is ...

        }*/
        System.out.println();

        // Array list
        /*{
            ArrayList<Integer> list = new ArrayList<>();
            // double, character, ... (generics)
            list.add(3);
            list.add(1);
            list.add(2);

            System.out.println(list);
            System.out.println(list.get(0));
            System.out.println(list.getFirst());
            System.out.println(list.getLast());
            System.out.println(list.size());
            System.out.println(list.contains(2));
            System.out.println(list.contains(6));
            System.out.println(list.indexOf(0));
            System.out.println(list.indexOf(3));
            System.out.println(list.indexOf(1));
            System.out.println(list.indexOf(2));


        }*/



        // Exception
        /*{

            try(Scanner scanner = new Scanner(System.in)){
                System.out.print("Enter a number: ");
                int number = scanner.nextInt();
                System.out.println(42 / number);
                // scanner.nextLine(); // clear '\n' (cin.ignore())

            }catch (InputMismatchException e){
                System.out.println("Not a number!");
            } catch(ArithmeticException e){
                System.out.println("Can't divide by zero..");
            } catch (Exception e){
                System.out.println("Other exception caught. (safety net)");
                System.out.println(e.getCause());
            } finally {
                System.out.println("Closing up scanner..");
                System.out.print ("Remember.. \'Finally\' always executes!");
                System.out.println(" It is for cleaning up.");
            }



        }*/








        // Reading-Writing a file

        // FileWriter - Good for smal or medium-sized text files
        // BufferedWriter - Better performance for large amounts of text
        // PrintWriter - Best for structured data, like reports or logs
        // FileOutputStream - Best for binary files (e.g., images audio files)


        // FileWriter
        /*{

            try(FileWriter writer = new FileWriter("test.txt")) {
                writer.write("Hello file!");
                System.out.println("File has been written");

            } catch(IOException e) {
                System.out.println("Could not write file");
            }
        }*/


        // BufferedReader + FileReader: Best for reading text files line-by-line
        // FileInputStream: Best for binary files (e.g, images, audio files)
        // RandomAccessFile: Best for read/write specific portions of a large file



        // BufferedReader + FileReader
        /*{


            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter absolute path of the file: ");
            String filePath = scanner.nextLine();


                                            // BufferedReader + FileReader
            try(BufferedReader reader = new BufferedReader(new FileReader(filePath))){

                System.out.println("File exists");

                String line;
                while((line = reader.readLine()) != null){
                    System.out.println(line);
                }

            }catch (FileNotFoundException e){
                System.out.println("Could not locate file");
            } catch (IOException e){
                System.out.println("Something went wrong");
            }






        }*/


        // TODO - Audio player
        {




        }


        // HashMap
       /* {

            //      <Key, Value>
            HashMap<String, Double> map = new HashMap<>();


            // map.put() put (key, value)

            map.put("apple", 1.60);
            map.put("orange", 2.43);
            map.put("banana", 4.80);
            map.put("coconut", 7.90);
            map.put("pear", 3.20);





            System.out.print("Set of keys for the hashmap: ");
            System.out.println(map.keySet());
            // map.get(key)
            // map.containsKey(key)
            // map.containsValue(value)



            // Print #1
            System.out.println("Print #1");
            System.out.println(map);
            System.out.println();



            // Print #2
            System.out.println("Print #2");
            for(String key : map.keySet()){ // important to iterate trough the set of keys, with the matching type
                System.out.printf("Item (key): { %s }\t:\t{ %.2f } lv.\n", key, map.get(key));
            }


        }*/



        // Enum - day (good for switch cases)
        /*{


            try (Scanner scanner = new Scanner(System.in)) {
                System.out.print("Enter a day of the week: ");
                String response = scanner.nextLine();

                Day day = Day.valueOf(response.toUpperCase());

                switch (day) {
                    case MONDAY,
                         TUESDAY,
                         WEDNESDAY,
                         THURSDAY,
                         FRIDAY -> System.out.println("Weekday");

                    case SATURDAY, SUNDAY -> System.out.println("Weekend. Take a rest");
                    case XD -> System.out.println("My man.");
                }
            } catch (IllegalArgumentException e) {
                System.out.println("Enter a valid day.");

            } catch (Exception e){
                System.out.println("Safety net. Other exception ocurred.");
            }


        }*/




        // THREADING #1
        /*{

            Scanner scanner = new Scanner(System.in);


            MyRunnable1 myRunnable1 = new MyRunnable1(); // implements Runnable interface (.run() method)
            Thread thread = new Thread(myRunnable1);
            // Thread object constructor accepts a class implementing the Runnable interface. (has run() method overriden)




            // Other thread will end as soon as the main thread is over with setting it as a daemon:
            thread.setDaemon(true);

            thread.start();
            System.out.println("You have 3 seconds to enter your name");


            System.out.print("Enter your name: ");
            String name = scanner.nextLine();
            System.out.println("Hello " + name);






            scanner.close();



        }*/


        // THREADING #2
        {

            Thread thread0 = new Thread(new MyRunnable2("THIS IS THREAD 0")); // anonymous
            Thread thread1 = new Thread(new MyRunnable2("THIS IS THREAD 1")); // anonymous

            System.out.println("Game start!");

            thread0.start();
            thread1.start();


            try{
                thread0.join();
                thread1.join();

            } catch (InterruptedException e){
                e.printStackTrace(); // https://www.geeksforgeeks.org/java/java-program-to-print-stack-trace/
                System.out.println("Thread was interrupted");
            }

            System.out.println("Game over!");

        }



    }
}
