package org.example.easy;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BankAccountTest {


    @Test
    public void testDepositValid() {
        //Arrange
        BankAccount account = new BankAccount(100.0);

        //Act
        account.deposit(50.0);

        //Assert
        assertEquals(150.0, account.getBalance(), "Deposit should increase the balance correctly.");
    }

    // Test depositing a non-positive amount throws an exception.
    @Test
    public void testDepositInvalid() {
        BankAccount account = new BankAccount(100.0);
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account.deposit(-20.0);
        });
        assertEquals("Deposit amount must be positive.", exception.getMessage());
    }

    // Test withdrawing a valid amount decreases the balance.
    @Test
    public void testWithdrawValid() {
        BankAccount account = new BankAccount(100.0);
        account.withdraw(30.0);
        assertEquals(70.0, account.getBalance(), "Withdraw should decrease the balance correctly.");
    }
}