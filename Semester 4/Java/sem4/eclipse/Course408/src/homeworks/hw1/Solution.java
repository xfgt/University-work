package homeworks.hw1;

import java.math.BigDecimal;
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
class Studio{
    int id;
    BigDecimal leva_rentForHour;
    int maximumHoursPerDay; // 0-24
    int hoursRent;
    static BigDecimal minimalPrice; // for all objects of Studio
    BigDecimal euroRate;


    public Studio(int id, int maxH){
        this.id = id;
        if(maxH >= 0 && maxH <= 24)
            maximumHoursPerDay = maxH;
        else
            maximumHoursPerDay = 24;
    }

    public static void setMinimalPrice(BigDecimal mp) {
        if(mp.compareTo(BigDecimal.ZERO) < 0)
            minimalPrice = new BigDecimal(0);
        else minimalPrice = new BigDecimal(mp.intValue());

    }
    public void setLeva_rentForHour(BigDecimal price){
        if(price.compareTo(minimalPrice) == 1){
           leva_rentForHour = price;
        } else {
            leva_rentForHour = minimalPrice;
        }
    }
    public void setHoursRent(int hours){
        if(hours > maximumHoursPerDay) hoursRent = maximumHoursPerDay;
        else
            hoursRent = hours;
    }
    public void setEuroRate(BigDecimal value){
        euroRate = value;
    }


    public int getId() {return id;}
    public BigDecimal getLeva_rentForHour() {return leva_rentForHour;}
    public int getMaximumHoursPerDay() {return maximumHoursPerDay;} // 0-24
    public int getHoursRent() {return hoursRent;}
    public BigDecimal getMinimalPrice() {return minimalPrice;}; // for all objects of Studio
    public BigDecimal getEuroRate() {return euroRate;}

    public BigDecimal getLeva_Profit() {return getLeva_rentForHour().multiply(BigDecimal.valueOf(hoursRent));}
    public BigDecimal getEuro_Profit() { return getLeva_Profit().multiply(getEuroRate());}

    public Studio compareByLevaRentForHour(Studio first, Studio second){
        if(first.getLeva_rentForHour().compareTo(second.getLeva_rentForHour()) == 1) return first;
        else return second;
    }

    public boolean compareByProfit(Studio first, Studio second){
        if(first.getLeva_Profit().compareTo(second.getLeva_Profit()) == 1) return true;
        return false;
    }
}


public class Solution {
    public static void main(String[] args) {

        //System.out.println(task1());
        //System.out.println(task2());
        //task3();
        task4();


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
        Scanner scanner = new Scanner(System.in);
        String name;
        int year, month, day, y,mm,d;
        name = scanner.nextLine();
        Manager m = new Manager(name);
        m.setDate(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());


        y = scanner.nextInt();
        mm = scanner.nextInt();
        d = scanner.nextInt();
        String checkDate = y + "-" + mm + "-" + d;
        m.print();
        System.out.println(m.numberOfYearsInCompanyTill(checkDate));
    }

    public static void task4(){
        Scanner scanner = new Scanner(System.in);

        int id, maxh, wh;
        BigDecimal mp, e, pph;
        id = scanner.nextInt(); maxh = scanner.nextInt();
        Studio s1 = new Studio(id, maxh);

        mp = scanner.nextBigDecimal();
        Studio.setMinimalPrice(mp);
        e = scanner.nextBigDecimal();
        s1.setEuroRate(e);

        pph = scanner.nextBigDecimal();
        wh = scanner.nextInt();
        s1.setLeva_rentForHour(pph);
        s1.setHoursRent(wh);

        id = scanner.nextInt(); maxh = scanner.nextInt();
        Studio s2 = new Studio(id, maxh);
        pph = scanner.nextBigDecimal();
        wh = scanner.nextInt();
        s2.setLeva_rentForHour(pph);
        s2.setHoursRent(wh);

        System.out.printf("%.1f\n", s1.getLeva_Profit());
        System.out.printf("%.3f\n", s1.getEuro_Profit());
        System.out.println(s1.compareByLevaRentForHour(s1, s2).getId());
        System.out.println(s1.compareByProfit(s1, s2));

    }


}
