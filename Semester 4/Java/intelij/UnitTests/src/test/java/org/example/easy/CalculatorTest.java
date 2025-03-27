package org.example.easy;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {

    @Test
    void add() {
    }

    @Test
    void subtract() {
    }

    @Test
    void multiply() {
    }

    @Test
    void divide() {
        Calculator calculator = new Calculator();

        assertThrowsExactly(IllegalArgumentException.class, () -> {
            calculator.divide(10, 0);
        });
    }

    @Test
    void power() {
    }
}