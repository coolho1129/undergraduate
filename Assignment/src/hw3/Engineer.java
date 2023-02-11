//학번: 2021114818
//이름: 김찬호
package hw3;
public class Engineer extends Employee {

	private int day;
	
	
	
	public void setOverWorkingDay(int day) {
		
		this.day=day;
	}
	
	public int getOverworkingPay() {
		
		return 3*this.day;
		
		
		
	}
	
	public int getAnnualSalary() {
		
		return 12*(getSalary()+getOverworkingPay());
		
		
	}
	
	public void printEmployeeInfo() {
		
		System.out.printf("%15s   %2d\t%15s\t%16d %10d %14d\n",getName(),getAge(),getPosition(),getOverworkingPay(),getSalary(),getAnnualSalary());		
		
	}
	


}
