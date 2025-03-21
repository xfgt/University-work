package homeworks.hw4;

// array list 
import java.util.ArrayList;

public class Solution {

	public static void main(String[] args) {
		
		ArrayList<String> arl = new ArrayList(5);
		
		arl.add("xd");
		arl.add("x0d");
		arl.add("xxded");

		for(ArrayList e : arl) {
			e.getFirst();
		}
	}

}
