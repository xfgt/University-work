package homeworks.hw3.exercise;

//Interface
interface Animal {
	public void animalSound(); // interface method (does not have a body)
	public void sleep(); // interface method (does not have a body)
	public void getPoroda();
	static double tovaSedi = 420.69;
	
}

abstract class Poroda{
	public void getPoroda() {
		System.out.println("Nikakva poroda.. :/");
	}
}


//Pig "implements" the Animal interface
class Pig implements Animal {
	
	public void animalSound() {
	 // The body of animalSound() is provided here
	 System.out.println("The pig says: wee wee");
	}
	public void sleep() {
	 // The body of sleep() is provided here
	 System.out.println("Zzz");
	 
	}
	
	public void getPoroda() {
		System.out.println("Svinski mirizliv nerez");
	}
}

class Horse extends Poroda implements Animal {
	
	
	public void animalSound() {
		 System.out.println("MIIHIHIHIHI NEIIIGHGHIGGG");
	}
	public void sleep() {
		System.out.println("KONQ NE POCHIVA, BUSHUVA S MAIKA TI GORCHIVA");
	}
	
		
	// DEFAULT NIKAKVA PORODA, IMPLEMENT EMPTY FOR EMPTY OR CUSTOM FOR CUSTOM
	
	

}

class Main {
	public static void main(String[] args) {
	 
	Animal a;
	
	Horse chocho = new Horse();
	Pig myPig = new Pig();  
	 
	 
	 a = myPig;
	 a.animalSound();
	 a.sleep();
	 System.out.println(a.tovaSedi);
	 a.getPoroda();
	 
	 a = chocho;
	 a.animalSound();
	 a.sleep();
	 System.out.println(a.tovaSedi);
	 a.getPoroda();
	 
	 
	 // ideqta e da moje da se izpolzvat funkcii ot bazov obekt
	 
	 
	 
	}
}