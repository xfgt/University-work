package bro;

public enum Day {

    // you need constructor
    // getter of value

    MONDAY(1),
    TUESDAY(2),
    WEDNESDAY(3),
    THURSDAY(4),
    FRIDAY(5),
    SATURDAY(6),
    SUNDAY(7),
    XD(1337);




    public final int dayNumber;

    Day(int dayNumber){
        this.dayNumber = dayNumber;
    }

    public final int getDayNumber(){
        return this.dayNumber;
    }
}
