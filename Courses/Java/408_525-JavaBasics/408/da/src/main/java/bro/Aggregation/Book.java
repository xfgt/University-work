package bro.Aggregation;

public class Book {
    String title;
    int pages;

    public Book(String title, int pages) {
        this.title = title;
        this.pages = pages;
    }

    public String displayInfo(){
        return this.title + " (" + this.pages + " pages)";
    }
}
