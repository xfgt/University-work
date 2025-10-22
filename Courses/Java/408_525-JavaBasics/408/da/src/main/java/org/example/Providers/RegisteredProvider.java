package org.example.Providers;

public abstract class RegisteredProvider implements Provider {

    private final String regNumber; // не може да се променя. (регистрационен номер: егн, булстат, естествен уникален идентификатор); няма сетър

    public RegisteredProvider(String regNumber) {
        this.regNumber = regNumber;
    }

    public String getRegNumber() { // няма сетър
        return regNumber;
    }


    @Override
    public String toString() {
        return "RegisteredProvider{" +
                "regNumber='" + regNumber + '\'' +
                '}';
    }
}
