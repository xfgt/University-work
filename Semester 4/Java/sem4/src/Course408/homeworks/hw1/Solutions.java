package Course408.homeworks.hw1;

import java.util.Scanner;

public class Solutions {
    public static void main(String[] args) {
        //System.out.println(task1());
        System.out.println(task2());

    }


    public static int changeNumber(int number){
        int n = 0;
        String sn = String.valueOf(number);
        String mod = sn.substring(1, sn.length());
        mod += sn.charAt(0);
        n = Integer.parseInt(mod);
        return n;
    }
    public static int task1(){
        Scanner scanner = new Scanner(System.in);
        int bottom = Integer.parseInt(scanner.nextLine());
        int top = Integer.parseInt(scanner.nextLine());
        int difference = Integer.parseInt(scanner.nextLine());

        if(bottom < 0 || top < 0){ return 0; }

        int count = 0;
        for(int i = bottom; i <= top; i++) {
            int ch = changeNumber(i);
            if (ch - i > difference) {
                //System.out.printf("%d - %d = %d > %d\n", ch, i, ch - i, difference);
                count++;
            }
        }
        return count;


    }
    public static int task2() {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        if (n < 1 || n > 9) return 0;

        int NUM = 0;
        int sum = 0;

        for(int i = 1; i <= n; i++) {
            NUM += i * 2;
        }

        for(int i = 0, d = 2; i < n; i++, d += 2){
            sum += NUM - d;
        }
        sum *= 2;
        sum += n * 2;



        return 1;
    }
}
