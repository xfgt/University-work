package repo;

public class Book extends Document {

    private final String isbn; // final - 'const' in C++; initialized in a constructor
    private Author author;

    public Book(String isbn, Author author) {
        super();
        this.isbn = isbn;
        this.author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public Author getAuthor() {
        return author;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }
}
