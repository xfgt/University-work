package sampleSolution2;

import java.lang.Math;

public class somethingElse {

    public static void main(String[] args) {

        System.out.println("This is a representative of sample solution 2!");
        int n = 16;


        System.out.printf("%d%n", fact(n));
        for(int i = 0; i < n; i++) {
            System.out.printf("%d ", fact(i));
        }
        System.out.println();


        fib(n+1); // sequence starts from 0
        System.out.printf("%n%d", ffp(n));

    }

    static long fact(int n) {
        if(n <= 0) return 1;
        if(n > 14) {
            System.out.println("Too long!");
            return -1;
        }
        if(n == 1)
            return 1;
        n *= fact(n - 1);
        return n;
    }

    // fib generate to N
    static void fib(int n) {
        if(n < 0) return;
        long a = 0;
        long b = 1;
        long c;
        System.out.printf("%d %d ", a, b);
        while(n > 2) {
            c = a + b;
            System.out.printf("%d ", c);
            a = b;
            b = c;
            n--;
        }

    }



    // find the Nth of fib sequence (formula sqrt 5)
    // THE COUNT STARTS FROM 0!

    static long ffp(int n) {

        long a = (long) Math.pow((1+Math.sqrt(5)), n);
        long b = (long) Math.pow((1-Math.sqrt(5)), n);
        long c = (long) (Math.pow(2, n) * Math.sqrt(5));

        return (a+b) / c;


    }
}

