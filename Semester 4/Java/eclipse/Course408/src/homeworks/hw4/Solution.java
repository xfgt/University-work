package homeworks.hw4;

import java.util.ArrayList;
import java.util.Scanner;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.lang.Enum;
import java.math.BigDecimal;



enum Contract{
		
	PERMANENT(new BigDecimal("0.0")), 
	PART_TIME(new BigDecimal("0.0")), 
	TRAINEE(new BigDecimal("0.0"));
	
	BigDecimal action;
	
	private Contract(BigDecimal action) {
		this.action = action;
	}
	
	public BigDecimal getAction() { 
		return this.action; 
	} 
	
	public void setAction(BigDecimal amount) {
		this.action = amount;
	}
}


class Employee{
	
	
	String name;
	int workedHours;
	Contract contractType; 				// determines minimalWagePerHour
	
	BigDecimal minimalWagePerHour;
	BigDecimal additionalWagePerHour;
	BigDecimal salary;
	
	
	
	public Employee(String name, int workedHours, Contract contractType) {
		
		this.name = name;
		this.workedHours = workedHours;
		this.contractType = contractType;
		
		
	}
	
	
// 	Getters
	public String getName() { return name; }
	// id
	public int getWorkedHours() { return workedHours; }
	public Contract getContractType() { return contractType; }
	
	public BigDecimal getMinimalWagePerHour() { return minimalWagePerHour; }
	public BigDecimal getAdditionalWagePerHour() { return additionalWagePerHour; }
	public BigDecimal getSalary() {
		return salary;
	}
	
//	Setters
	
	public void setAdditionalWagePerHourBy(double amount) {
		BigDecimal additional = new BigDecimal(amount);
		this.additionalWagePerHour = additional;
	}
	
	public void setIncreaseSalaryByPercentOf(BigDecimal percent) {
		return;
	}
	
	@Override
	public String toString() {
		return 		"Employee: " + this.getName() +
					"\ncontractType: " + this.getContractType().toString() +
					"\nworkedHours: " + this.getWorkedHours() +
					"\n" +
					"minimalWagePerHour: " + this.getMinimalWagePerHour() +
					"\nadditionalWagePerHour: " + this.getAdditionalWagePerHour() +
					"\nsalary: " + this.getSalary() + "\n=========================================";
	}
}



class Company{
	
	String companyName;
	int maxEmployees;
	ArrayList<Employee> employeeList; // size is maxEmployees
	
	
	
	public void hireEmployee(Employee obj) {
		// if already exists and list has a space
		if(!(employeeList.contains( obj )) && employeeList.size() < maxEmployees);
			employeeList.add(obj);
		
	}
	
	public void fireEmployee(Employee obj) {
		employeeList.remove(obj);
	}
	
//	public BigDecimal averageSalary() {
//	}
//	
//	public void increaseSalaries(BigDecimal percentage) {
//		
//	}
//	public BigDecimal averageSalaryPerContractType() {
//		
//	}
	
	
	
}



public class Solution {
	
	


	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		
		
		
//		Global / Company variables input
		String companyName = scanner.nextLine();
		int maxEmployees = Integer.parseInt(scanner.nextLine());
				
		String additionals = scanner.nextLine();
		String[] addits_array = additionals.trim().split(" ");
		Contract.valueOf("PERMANENT").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[0])));
		Contract.valueOf("PART_TIME").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[1])));
		Contract.valueOf("TRAINEE").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[2])));
			
		
		
//		Employee specific input
		ArrayList<Employee> employees = new ArrayList<Employee>();
		
		String names = scanner.nextLine();
		String workedHours = scanner.nextLine();
		String rawStringContractTypes = scanner.nextLine();
		String additionalWages = scanner.nextLine();
		
		String[] name_array = names.trim().split(" ");
		String[] workedHours_array = workedHours.trim().split(" ");
		String[] rawStringContractTypes_array = rawStringContractTypes.trim().split(" ");
		String[] additionalWages_array = additionalWages.trim().split(" ");
		
		
		for(int i = 0; i < maxEmployees; i++) {
			Contract contractTypeFromString = Contract.valueOf(rawStringContractTypes_array[i]);
			Employee temp = new Employee(
					name_array[i], 
					Integer.parseInt(workedHours_array[i]), 
					contractTypeFromString);
			
			
			temp.setAdditionalWagePerHourBy(Double.parseDouble(additionalWages_array[i]));
			employees.add(temp);
		}
		
		
		for(Employee x : employees) {
			System.out.println(x.toString());
		}
		
	}

}












