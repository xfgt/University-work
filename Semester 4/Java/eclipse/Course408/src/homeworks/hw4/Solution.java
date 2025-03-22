package homeworks.hw4;

import java.util.ArrayList;
import java.math.BigDecimal;
import java.util.Scanner;


enum Contract{
	PERMANENT, PART_TIME, TRAINEE
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
			
		setSalaryDependingOn(this.contractType);
		
	}
	
	
// 	Getters
	public String getName() { return name; }
	public int getWorkedHours() { return workedHours; }
	public Contract getContractType() { return contractType; }
	public BigDecimal getMinimalWagePerHour() { return minimalWagePerHour; }
	public BigDecimal getAdditionalWagePerHour() { return additionalWagePerHour; }
		
	// TODO:
	public BigDecimal getSalary() {
		return salary;
	}
	
	
	
	
	
	
	
//	Setters
	public void setMinimalWagePerHourFrom() {
		this.minimalWagePerHour.setScale(0);
		return;
	}
	
	public void setAdditionalWagePerHourFrom() {
		this.additionalWagePerHour.setScale(0);
		return;
	}
	
	public void setSalaryDependingOn(Contract type) {
		switch(type) {
		case PERMANENT:
			break;
		case PART_TIME:
			break;
		case TRAINEE:
			break;
			default:
				break;
		}
	}
		
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
		if(!(employeeList.contains( obj )) && employeeList.size() > maxEmployees);
			employeeList.add(obj);
		
	}
	
	public void fireEmployee(Employee obj) {
		employeeList.remove(obj);
	}
	
	public BigDecimal averageSalary() {
	}
	
	public void increaseSalaries(BigDecimal percentage) {
		
	}
	public BigDecimal averageSalaryPerContractType() {
		
	}
}










































public class Solution {
	


	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		
		// get input
		
		
		
	}

}












