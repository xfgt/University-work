package org.example.mid;

public abstract class Employee {
    private String name;
    private final int id;

    public Employee(String name, int id) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name must not be empty.");
        }
        if (id <= 0) {
            throw new IllegalArgumentException("ID must be positive.");
        }
        this.name = name;
        this.id = id;
    }

    public String getEmployeeInfo() {
        return "Employee: " + name + " (ID: " + id + ")";
    }

    public abstract void displayRole();
}
