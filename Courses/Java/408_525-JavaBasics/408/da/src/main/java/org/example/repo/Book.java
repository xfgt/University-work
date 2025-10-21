package org.example.repo;

public class Book extends org.example.repo.Document {

    private final String isbn; // final - 'const' in C++; initialized in a constructor
    private org.example.repo.Author author;


    public Book(String isbn, org.example.repo.Author author) {
        super(); // calls Document()
        this.isbn = isbn;
        this.author = author;
    }
    public Book(String title, String format, double docSize, String isbn, org.example.repo.Author author){
        super(title, format, docSize); // calls Document (String , String , double)
        this.isbn = isbn;
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public org.example.repo.Author getAuthor() {
        return author;
    }

    public void setAuthor(org.example.repo.Author author) {
        this.author = author;
    }

    @Override
    public String toString() {
        return super.toString() + "Book{" +
                "isbn='" + isbn + '\'' +
                ", author=" + author +
                '}';
    }
}
