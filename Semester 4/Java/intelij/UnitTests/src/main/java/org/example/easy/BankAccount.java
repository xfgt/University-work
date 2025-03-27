package org.example.easy;

public class BankAccount {
    private double balance;

    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Deposit amount must be positive.");
        }

        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Withdrawal amount must be positive.");
        }

        if (amount > balance) {
            throw new IllegalArgumentException("Insufficient funds.");
        }

        balance -= amount;
    }

    public double getBalance() {
        return balance;
    }

    public void transfer(BankAccount target, double amount) {
        if (target == null) {
            throw new IllegalArgumentException("Target account cannot be null.");
        }
        this.withdraw(amount);
        target.deposit(amount);
    }

    public void applyInterest(double interestRate) {
        if (interestRate < 0) {
            throw new IllegalArgumentException("Interest rate cannot be negative.");
        }
        balance += balance * interestRate;
    }


}

