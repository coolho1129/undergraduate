//학번: 2021114818
//이름: 김찬호
package hw3;
public class Staff extends Employee {

	
	
	public int getAnnualSalary() {
		 
	 return 12*getSalary();	 
		 
		 
	 }
	 
	 public void printEmployeeInfo() {
		 
		 
		 System.out.printf("%15s   %2d\t%15s\t%9d\t%9d\n",getName(),getAge(),getPosition(),getSalary(),getAnnualSalary());
		 
		 
	 }

}
