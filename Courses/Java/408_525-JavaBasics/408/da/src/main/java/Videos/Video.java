package Videos;

public class Video {

    private final String code;
    private String name;
    private double duration;
    private int likes;
    private boolean isForKids;

    public Video(String code, String name, double duration, int likes, boolean isForKids) {
        this.code = code;
        this.name = name;
        this.duration = duration;
        this.likes = likes;
        this.isForKids = isForKids;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getDuration() {
        return duration;
    }

    public void setDuration(double duration) {
        this.duration = duration;
    }

    public int getLikes() {
        return likes;
    }

    public void setLikes(int likes) {
        this.likes = likes;
    }

    public boolean isForKids() {
        return isForKids;
    }

    public void setForKids(boolean forKids) {
        isForKids = forKids;
    }

    @Override
    public String toString() {
        return "Video{" +
                "name='" + name + '\'' +
                ", duration=" + duration +
                ", likes=" + likes +
                ", isForKids=" + isForKids +
                '}';
    }
}
