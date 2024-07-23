package hw2;
//학번: 2021114818
//이름: 김찬호

public class Employee {

	private int age,salary;
	private String fullName,position;
	
	
	
	
	public void setAge(int age) {
		
		this.age=age;
		
		
	}
	
	public void setPosition(String position) {
		
		this.position=position;
		
		
	}
	
	public void setName(String firstname, String lastname) {
		
		
		this.fullName=firstname+" "+lastname;
		
		
	}
	public void setSalary(int salary) {
		
		this.salary=salary;
		
		
	}
	
	public String getName() {
		
		return fullName; 
	}
	
	public int getSalary() {
		
		return salary;
		
	}
	public String getPosition() {
		
		return position;
		
		
	}
	public int getAge() {
		
		
		return age;
	}
	public void printEmployeeInfo() {
		
		System.out.printf("%20s   %2d\t%28s\t%8d\n",getName(),getAge(),getPosition(),getSalary());
		
		
	}
}
