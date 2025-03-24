package homeworks.hw4;

import java.util.ArrayList;
import java.util.Scanner;

import java.lang.Enum;
import java.math.BigDecimal;



enum Contract{
		
	PERMANENT(new BigDecimal("0.0")), PART_TIME(new BigDecimal("0.0")), TRAINEE(new BigDecimal("0.0"));
	
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
	public int getWorkedHours() { return workedHours; }
	public Contract getContractType() { return contractType; }
	
	public BigDecimal getMinimalWagePerHour() { return minimalWagePerHour; }
	public BigDecimal getAdditionalWagePerHour() { return additionalWagePerHour; }
	public BigDecimal getSalary() {
		return salary;
	}
	
//	Setters
	public void increaseSalaryByPercentOf(BigDecimal percent) {
		return;
	}
	
	@Override
	public String toString() {
		return 		"Employee: " + this.getName() +
					"contractType: " + this.getContractType().toString() +
					"workedHours: " + this.getWorkedHours() +
					"\n" +
					"minimalWagePerHour: " + this.getMinimalWagePerHour() +
					"additionalWagePerHour: " + this.getAdditionalWagePerHour() +
					"salary: " + this.getSalary() + "\n=========================================";
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
		
		
		// get input
		
		String companyName = scanner.nextLine();
		int maxEmployees = Integer.parseInt(scanner.nextLine());
		Contract[] contracts = Contract.values();
		
		// TODO: input values for enums
		
		ArrayList<Employee> employees = new ArrayList<Employee>();
		
		for(int i = 0; i < maxEmployees; i++) {
			String name = scanner.nextLine();
			int workedHours = Integer.parseInt(scanner.nextLine());
			String stringType = scanner.nextLine();
			Contract typeFromString = Contract.valueOf(stringType);
			
			
			Employee hold = new Employee(name, workedHours, typeFromString);
			employees.add(hold);
		}
		
		for(Employee x : employees) {
			System.out.println(x.toString());
		}
		
	}

}












