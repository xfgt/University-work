package repo;

public class Repository {

    private double maxSize;
    private int uploadedFiles;
    private double currentSize;


    public Repository(double maxSize) {
        this.maxSize = maxSize;
    }

    public Repository(double maxSize, int uploadedFiles, double currentSize) {
        this.maxSize = maxSize;
        this.uploadedFiles = uploadedFiles;
        this.currentSize = currentSize;
    }

    public double getMaxSize() {
        return maxSize;
    }

    public void setMaxSize(double maxSize) {
        this.maxSize = maxSize;
    }

    public int getUploadedFiles() {
        return uploadedFiles;
    }

    public void setUploadedFiles(int uploadedFiles) {
        this.uploadedFiles = uploadedFiles;
    }

    public double getCurrentSize() {
        return currentSize;
    }

    public void setCurrentSize(double currentSize) {
        this.currentSize = currentSize;
    }

    @Override
    public String   toString() {
        return "Repository{" +
                "maxSize=" + maxSize +
                ", uploadedFiles=" + uploadedFiles +
                ", currentSize=" + currentSize +
                '}';
    }
}
