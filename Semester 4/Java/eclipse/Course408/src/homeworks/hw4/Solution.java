package homeworks.hw4;

import java.util.ArrayList;
import java.util.Scanner;
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
	// static id
	int workedHours;
	Contract contractType; 				
	
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
	// get id
	public int getWorkedHours() { return workedHours; }
	public Contract getContractType() { return contractType; }
	public BigDecimal getMinimalWagePerHour() { return minimalWagePerHour; }
	public BigDecimal getAdditionalWagePerHour() { return additionalWagePerHour; }
	public BigDecimal getSalary() { return salary; }
	
//	Setters
	
	public void setInitMinWage() {
		this.minimalWagePerHour = contractType.getAction().add(this.additionalWagePerHour);
	}
	public void setInitSalary() {
		this.salary = BigDecimal.valueOf(this.getWorkedHours()).multiply(this.getMinimalWagePerHour());
	}
	
	
	public void setSalary(BigDecimal amount) {
		this.salary = amount;
	}
	
	public void setAdditionalWagePerHourBy(BigDecimal amount) {
		this.additionalWagePerHour = amount;
	}
	
	public void setIncreaseSalaryByPercentOf(BigDecimal percent) {
		return;
	}
	
	@Override
	public String toString() {
		return 		"Employee: " + this.getName() +
					// 	id
					"\ncontractType: " + this.getContractType().toString() +
					"\nworkedHours: " + this.getWorkedHours() +
					"\n\nminimalWagePerHour: " + this.getMinimalWagePerHour() +
					"\nadditionalWagePerHour: " + this.getAdditionalWagePerHour() +
					"\nsalary: " + this.getSalary() + "\n=========================================";
	}
}



class Company{
	
	String companyName;
	int maxEmployees;
	ArrayList<Employee> employeeList; // size is maxEmployees
	
	
	public Company(String companyName, int maxEmployees) {
		this.companyName = companyName;
		this.maxEmployees = maxEmployees;
		this.employeeList = new ArrayList<Employee>(this.maxEmployees);
	}

//	Setters
	public void hireEmployee(Employee obj) {
		// if already exists and list has a space
		if(!(employeeList.contains( obj )) && employeeList.size() < maxEmployees);
			employeeList.add(obj);
		
	}
	
	public void listEmployees() {
		for(Employee x : employeeList) {
			System.out.println(x.toString());
		}
	}
	
	public void increaseAdditionalSalariesByPercentageOf(BigDecimal percentage) {
		if(percentage.compareTo(BigDecimal.valueOf(0)) <= -1) return;
		
		for(Employee employee : employeeList) {
			employee.setAdditionalWagePerHourBy(
						employee.getAdditionalWagePerHour().add(	employee.getAdditionalWagePerHour().multiply(percentage)	)
					);
		}
		
	}
	
// Getters
	public BigDecimal getSumOfEmployeeSalaries() {
		BigDecimal sumOfSalaries = new BigDecimal("0.0");

		for(Employee x : employeeList) 
			sumOfSalaries = sumOfSalaries.add(x.getSalary());		
		
		return sumOfSalaries;
	}
	
	public BigDecimal getSumOfEmployeeSalariesByContractTypeOf(Contract contractType) {
		BigDecimal sumOfSalaries = new BigDecimal("0.0");
		
		for(Employee x : employeeList) {
			if(x.getContractType().equals(contractType)) {
				sumOfSalaries = sumOfSalaries.add(x.getSalary());
			}
					
		}
		return sumOfSalaries;
	}
	
	public int getEmployeesQuantity() { return maxEmployees; }
	
	public int getEmployeesQuantityByContractTypeOf(Contract contractType) {
		int q = 0;		
		for(Employee x : employeeList)
			if(x.getContractType().equals(contractType))
				q++;
		return q;
	}

	public BigDecimal getAverageSalary() {
		return getSumOfEmployeeSalaries().divide(BigDecimal.valueOf(this.getEmployeesQuantity()));
	}

	public BigDecimal getAverageSalaryByContractTypeOf(Contract contractType) {
		// Sum all salaries of CONTRACT TYPE / their quantity
		
		BigDecimal sumOfSalariesByType = new BigDecimal("0.0");
		int q = getEmployeesQuantityByContractTypeOf(contractType);
		
		if(q != 0)
			sumOfSalariesByType = getSumOfEmployeeSalariesByContractTypeOf(contractType).divide(BigDecimal.valueOf(q));
		
		
		return sumOfSalariesByType;
	}
	
	
	
}



public class Solution {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
				
//		Global / Company variables input
		String companyName = scanner.nextLine();
		int maxEmployees = Integer.parseInt(scanner.nextLine());
		Company myCompany = new Company(companyName, maxEmployees);
				
		String additionals = scanner.nextLine();
		String[] addits_array = additionals.trim().split(" ");
		Contract.valueOf("PERMANENT").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[0])));
		Contract.valueOf("PART_TIME").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[1])));
		Contract.valueOf("TRAINEE").setAction(BigDecimal.valueOf(Double.parseDouble(addits_array[2])));	
		
//		Employee specific input
		String names = scanner.nextLine();
		String workedHours = scanner.nextLine();
		String rawStringContractTypes = scanner.nextLine();
		String additionalWages = scanner.nextLine();
		String contractTypeAverageString = scanner.nextLine();
		String salariesIncreasePercentage = scanner.nextLine();
		
		String[] name_array = names.trim().split(" ");
		String[] workedHours_array = workedHours.trim().split(" ");
		String[] rawStringContractTypes_array = rawStringContractTypes.trim().split(" ");
		String[] additionalWages_array = additionalWages.trim().split(" ");
		
		
		
		
		
		
		
//		Employees fill data
		for(int i = 0; i < maxEmployees; i++) {
			Contract contractTypeFromString = Contract.valueOf(rawStringContractTypes_array[i]);
			Employee temp = new Employee(
					name_array[i], 
					Integer.parseInt(workedHours_array[i]), 
					contractTypeFromString);
			temp.setAdditionalWagePerHourBy(BigDecimal.valueOf(Double.valueOf(additionalWages_array[i])));
			temp.setInitMinWage();
			temp.setInitSalary();
			myCompany.hireEmployee(temp);
		}
		
				
		
//		myCompany.listEmployees();
//		System.out.println();
//		
		
		
		// average salary
		System.out.println(myCompany.getAverageSalary().toString()); // correct
		
		
		// average salary after increasing all employees additional salary per hour
		// increase function
		double increase = Double.parseDouble(salariesIncreasePercentage);
		myCompany.increaseAdditionalSalariesByPercentageOf(BigDecimal.valueOf(increase));
		System.out.println(myCompany.getAverageSalary().toString()); // to be modified (step 2)
		
		
		// average salary by contract type
		System.out.println(myCompany.getAverageSalaryByContractTypeOf(Contract.valueOf(contractTypeAverageString)).toString()); // we need step 2
		
	}

}












