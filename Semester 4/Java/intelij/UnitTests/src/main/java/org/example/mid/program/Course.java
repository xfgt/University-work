package org.example.mid.program;

public class Course {
    private final long id;
    private String name;
    private int credits;
    private CourseType courseType;
    private static long numberOfInstances = 0;
    public Course(String name, int credits, CourseType courseType) {
        Course.numberOfInstances++;
        this.id = Course.numberOfInstances;
        this.name = name;
        this.credits = credits;
        this.courseType = courseType;
    }

    public long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getCredits() {
        return credits;
    }

    public CourseType getCourseType() {
        return courseType;
    }

    public static long getNumberOfInstances() {
        return numberOfInstances;
    }

    @Override
    public String toString() {
        return "Course{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", credits=" + credits +
                ", courseType=" + courseType +
                '}';
    }
}
