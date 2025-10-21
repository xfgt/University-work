package repo;

public class Document {
    private String title;
    private String format;
    private double docSize;



    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public double getDocSize() {
        return docSize;
    }

    public void setDocSize(double docSize) {
        this.docSize = docSize;
    }

    @Override
    public String toString() {
        return "Document{" +
                "title='" + title + '\'' +
                ", format='" + format + '\'' +
                ", docSize=" + docSize +
                '}';
    }
}
