package homeworks.hw4.trainConcepts;


import java.lang.Enum;

enum justFruit {
	APPLE, PEACH, BANANA, ORANGE
}


//


enum Fruit {
    APPLE(3), PEACH(4), BANANA(1.5), ORANGE(2);	
    private double price;
    
    private Fruit(double price) { // the constructor is key; cannot be public, protected
        this.price = price;
    }
    
    public double getPrice() {
        return price;
    }
    public void setPrice(double price) {
    	this.price = price;
    }
    public int getOrdinal() {
    	return this.ordinal();
    }
}




//Java program to demonstrate how values can 
//be assigned to enums. 
enum TrafficSignal 
{ 
	// This will call enum constructor with one 
	// String argument 
	RED("STOP"), GREEN("GO"), ORANGE("SLOW DOWN"); 

	// declaring private variable for getting values 
	private String action; 
	
	// enum constructor - cannot be public or protected 
	private TrafficSignal(String action) { 
		this.action = action; 
	}
	

	// getter methods 
	public String getAction() 
	{ 
		return this.action; 
	} 
	
	
} 


public class trainEnums {
	public static void main(String[] args) {
		
		
		
		
		Fruit[] f_obj = Fruit.values();
		
		System.out.println("Ordinal\t| Value\t| Action");
		for(Fruit i : f_obj)
			System.out.println(i.ordinal() + "\t " + i + "\t\t" + i.getPrice());
		
		Fruit.valueOf("APPLE").setPrice(0.34);
		System.out.println(Fruit.valueOf("APPLE"));
		
		
		for(Fruit i : f_obj)
			System.out.println(i.ordinal() + "\t " + i + "\t\t" + i.getPrice());
		
		
	}

}
