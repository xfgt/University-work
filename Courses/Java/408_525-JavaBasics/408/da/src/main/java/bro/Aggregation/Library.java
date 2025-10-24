package bro.Aggregation;

public class Library {

    public String name;
    int year;
    Book[] books;

    public Library(String name, int year, Book[] books) {
        this.name = name;
        this.year = year;
        this.books = books;
    }

    public void displayInfo(){
        System.out.printf("The \"%s\" library established in the year of %d.\n\tHas those books available:\n", this.name, this.year);
        for(Book i : this.books)
            System.out.println("\t\t" + " * " + i.displayInfo()); // Library::displayInfo() has Book::displayInfo()
    }
}
