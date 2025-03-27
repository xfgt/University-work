package org.example.mid.program;

import java.util.ArrayList;
import java.util.List;

public class Program {
    private String name;
    private ProgramType programType;
    private List<Course> courses;

    public Program(String name, ProgramType programType) {
        this.name = name;
        this.programType = programType;
        this.courses = new ArrayList<>();
    }

    public Program(String name, ProgramType programType, List<Course> courses) {
        this.name = name;
        this.programType = programType;
        this.courses = courses;
    }

    public String getName() {
        return name;
    }

    public ProgramType getProgramType() {
        return programType;
    }

    public boolean addCourseToProgram(Course course) {
        if (this.courses.contains(course)) {
            return false;
        }
        return this.courses.add(course);
    }
    public boolean removeCourseToProgram(Course course) {
        if (this.courses.contains(course)) {
            return this.courses.remove(course);
        }
        return false;
    }
    public void printCourses() {
        for(Course course : this.courses) {
            System.out.println(course);
        }
    }

    public int totalCredits() {
        int sum = 0;
        for(Course course : this.courses) {
            sum += course.getCredits();
        }
        return sum;
    }



    @Override
    public String toString() {
        return "Program{" +
                "name='" + name + '\'' +
                ", programType=" + programType +
                '}';
    }
}
