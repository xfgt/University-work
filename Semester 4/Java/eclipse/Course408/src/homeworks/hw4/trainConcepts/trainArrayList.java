package homeworks.hw4.trainConcepts;

import java.util.List;
import java.util.ArrayList;


public class trainArrayList {
	public static void main(String[] args) {
		
		List<String> l = new ArrayList<String>();
		
		// add elements
		l.add("asdf");
		l.add("XDXD");
		
		// print the list
		System.out.println(l);
		
		// get single element at index
		System.out.println(l.get(1));
		
		// Set item value
		l.set(0, "Jeff" );
		System.out.println(l);

		// Remove an item
		l.remove(0);
		System.out.println(l);

		// Return size of the Arraylist
		System.out.println(l.size());
		
		// Remove all items
		l.clear();
		System.out.println(l.size());

		// Add item to an ArrayList
		l.add("Adf");
		l.add("Richard");
		// Loop through an Arraylist
		for (String name : l) {
			System.out.println(name);
		}

		
		// Return true if l contain XDXD
		System.out.println(l.contains("XDXD"));
		System.out.println(l.contains("123"));

	}
}
