package org.example.repo;

public class Novel extends Book{

    private String novelAbstract;


    public Novel(String isbn, Author author) {
        super(isbn, author);
    }

    public Novel(
            String title,
            String format,
            double docSize,
            String isbn,
            Author author
    ) {
        super(title, format, docSize, isbn, author);
    }


    @Override
    public String toString() {
        return "Novel{" +
                "novelAbstract='" + novelAbstract + '\'' +
                "} " + super.toString();
    }
}
