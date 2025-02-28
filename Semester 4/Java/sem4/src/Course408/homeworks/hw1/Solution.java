package Course408.homeworks.hw1;

import java.time.LocalDate;
import java.time.Period;
import java.util.Scanner;

class Manager{

    private String m_name;
    private String m_date;
    private int m_year;
    private int m_month;
    private int m_day;

    public Manager(String name){
        m_name = name;
    }
    public String getName() { return m_name;}
    public String getDate() { return m_date;}

    public void setName (String name) { m_name = name;}
    public void setDate(int year, int month, int day) {

        m_year = year;
        m_month = month;
        m_day = day;

        LocalDate localDate = LocalDate.of(year, month, day);
        m_date = String.valueOf(localDate);

    }

    public void changeDate(String date_arg){
        m_date = date_arg;
        String[] values = m_date.split("-");
        m_year= Integer.parseInt(values[0]);
        m_month = Integer.parseInt(values[1]);
        m_day = Integer.parseInt(values[2]);

    }

    public void print(){
        System.out.println(m_date);
    }

    public String numberOfYearsInCompanyTill(String datata){
        String[] values = datata.split("-");
        int y = Integer.parseInt(values[0]);
        int m = Integer.parseInt(values[1]);
        int d = Integer.parseInt(values[2]);



        if(m_year > y) {
            return "2020-1-1";
        }else{
            LocalDate startDate = LocalDate.of(m_year, m_month, m_day);
            LocalDate endDate = LocalDate.of(y, m, d);

            Period period = Period.between(startDate, endDate);
            return String.valueOf(period.getYears());
        }

    }
}



public class Solution {
    public static void main(String[] args) {

        //System.out.println(task1());
        //System.out.println(task2());
        //task3();


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
    public static void task3(){
        Scanner sc = new Scanner(System.in);
        String name;
        int year, month, day, y,mm,d;
        name = sc.nextLine();
        Manager m = new Manager(name);
        m.setDate(sc.nextInt(), sc.nextInt(), sc.nextInt());


        y = sc.nextInt();
        mm = sc.nextInt();
        d = sc.nextInt();
        String checkDate = y + "-" + mm + "-" + d;
        m.print();
        System.out.println(m.numberOfYearsInCompanyTill(checkDate));
    }


}
