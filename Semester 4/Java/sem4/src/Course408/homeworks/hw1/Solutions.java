package Course408.homeworks.hw1;

import java.util.Scanner;

public class Solutions {
    public static void main(String[] args) {
        //System.out.println(task1());
        //System.out.println(task2());

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

        for(int k = 1; k <= n; k++){
            for(int i = k; i <= n; i++) {
                NUM += i * 2;
            }
        }

        for(int h = 1; h < n; h++){
            for(int i = n; i >= h; i--) {
                NUM += i * 2;
            }
        }
        return NUM;
    }
    class Manager{

        String m_name;
        String m_date;

        public Manager(String name){
            m_name = name;

        }
        public String getName() { return m_name;}
        public String getDate() { return m_date;}

        public void setName (String name) { m_name = name;}
        public void setDate(String date) {



            m_date = date;

        }

    }
}
