package org.example.mid;

public class EmployeeWithSalary extends Employee implements Payable{
    private double annualSalary;

    public EmployeeWithSalary(String name, int id, double annualSalary) {
        super(name, id);

        if (annualSalary <= 0) {
            throw new IllegalArgumentException("Annual salary must be positive.");
        }

        this.annualSalary = annualSalary;
    }

    // Implements the calculatePay method from Payable.
    @Override
    public double calculatePay() {
        // Returns monthly pay by dividing the annual salary by 12.
        return annualSalary / 12;
    }

    // Implements the abstract displayRole method.
    @Override
    public void displayRole() {
        System.out.println("Role: Salaried Employee");
    }

    // Updates the annual salary. Throws exception for invalid values.
    public void updateSalary(double newSalary) {
        if (!isValidSalary(newSalary)) {
            throw new IllegalArgumentException("Salary must be positive.");
        }
        annualSalary = newSalary;
    }

    // Applies a bonus to the annual salary and returns the bonus amount.
    public double applyBonus(double bonusPercentage) {
        if (bonusPercentage < 0) {
            throw new IllegalArgumentException("Bonus percentage must be non-negative.");
        }
        double bonus = annualSalary * bonusPercentage / 100;
        annualSalary += bonus;
        return bonus;
    }

    // Returns the current annual salary.
    public double getAnnualSalary() {
        return annualSalary;
    }

    // Validates that the salary is a positive number.
    private boolean isValidSalary(double salary) {
        return salary > 0;
    }
}
