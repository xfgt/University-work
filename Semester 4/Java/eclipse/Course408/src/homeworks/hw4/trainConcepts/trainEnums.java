package homeworks.hw4.trainConcepts;


import java.lang.Enum;

enum Fruit {
	APPLE, PEACH, BANANA, ORANGE
}

public class trainEnums {
	public static void main(String[] args) {
		Fruit fruit;
		Fruit fruits[] = Fruit.values();
		
		for(Fruit f : fruits) {
			System.out.println(f);
		}
		
		fruit = Fruit.valueOf("ORANGE");
		System.out.println("fruit contains " + fruit);
		

		
		
	}

}
