package org.example.Providers;

public class Engineer implements Provider {
    private double salaryPerHour;
    private double hoursWorked; // ако не си сигурен не слагай int; double e mid решение, за по-специфични случаи е удачно BigDecimal;



    public Engineer(double salaryPerHour, double hoursWorked) {
        this.salaryPerHour = salaryPerHour;
        this.hoursWorked = hoursWorked;
    }


    public double getSalaryPerHour() {
        return salaryPerHour;
    }

    public void setSalaryPerHour(double salaryPerHour) {
        this.salaryPerHour = salaryPerHour;
    }

    public double getHoursWorked() {
        return hoursWorked;
    }

    public void setHoursWorked(double hoursWorked) {
        this.hoursWorked = hoursWorked;
    }

    @Override
    public String toString() {
        return "Engineer{" +
                "salaryPerHour=" + salaryPerHour +
                ", hoursWorked=" + hoursWorked +
                '}';
    }

    @Override
    public double earnings() {
        return this.getSalaryPerHour() * this.getHoursWorked();
    }
}
