//학번: 2021114818 
//이름 김찬호
package hw2;
import java.util.Scanner;

public class EmployeeApp {

	public static void main(String[] args) {
		
		Employee[] employee = new Employee[5];
		Scanner scan=new Scanner(System.in);
		for(int i=0;i<5;i++) {
			
			employee[i]=new Employee();
			
		}
		
		employee[0].setAge(28);
		employee[0].setName("John","Smith");
		employee[0].setPosition("Senior Software Engineer");
		employee[0].setSalary(300);
		
		employee[1].setAge(24);
		employee[1].setName("Kim","Young");
		employee[1].setPosition("Junior Software Engineer");
		employee[1].setSalary(250);
		
		employee[2].setAge(37);
		employee[2].setName("Lisa","Barnes");
		employee[2].setPosition("Team Leader");
		employee[2].setSalary(580);
		
		employee[3].setAge(46);
		employee[3].setName("Michael","Kevin");
		employee[3].setPosition("Project Manager");
		employee[3].setSalary(650);
		
		employee[4].setAge(35);
		employee[4].setName("Mary","Anne");
		employee[4].setPosition("Senior Software Engineer");
		employee[4].setSalary(350);
		
		int index,salary;
		String position;
		
		for(;;) {
			
			System.out.println("================================");
			System.out.println(" Employee Management System");
			System.out.println("================================");
			System.out.println("1. Display Employees' Information");
			System.out.println("2. Chagne Employee's Position");
			System.out.println("3. Change Employee's Salary");
			System.out.println("0. Quit");
			System.out.println("================================");
			System.out.print("-> ");
			
			int input=scan.nextInt();
			
			if(input==0) {
				System.out.println("Bye!");
				scan.close();
				break;
				
			}
			else if(input==1) {
				
				System.out.printf("%23s %5s %30s %11s\n","Name","Age","Position","Salary");
				System.out.println(" -----------------------------------------------------------------------");
				for(int i=0;i<employee.length;i++) {
					System.out.printf("[%2d]",i+1);
					employee[i].printEmployeeInfo();
					
				}
				System.out.println(" -----------------------------------------------------------------------");
			}
		
			else if (input==2) {
				
				for(int i=0;i<employee.length;i++) {
					System.out.printf("[%2d]",i+1);
					System.out.printf("%15s\t%28s\n",employee[i].getName(),employee[i].getPosition());
				
				
				}
				for(;;) {
				System.out.printf("Input index(1~5) and new position: ");
				index=scan.nextInt();
				position=scan.nextLine();
			
				if(0<index&&index<6)
					break;
				else
					System.out.println("Wrong index. Type again.");
				
				
				}
				employee[index-1].setPosition(position);
				System.out.println("-----------------------------------------------------");
				System.out.printf("[%2d] %15s\t%28s\n",index,employee[index-1].getName(),employee[index-1].getPosition());
				System.out.println("-----------------------------------------------------");
			
			
			
			}
				
			else if(input==3) {
				
				for(int i=0;i<employee.length;i++) {
					System.out.printf("[%2d]",i+1);
					System.out.printf("%15s\t%28d\n",employee[i].getName(),employee[i].getSalary());
				
				
				}
				for(;;) {
					System.out.printf("Input index(1~5) and new salary: ");
					index=scan.nextInt();
					salary=scan.nextInt();
				
					if(0<index&&index<6)
						break;
					else
						System.out.println("Wrong index. Type again.");
				
					}
					employee[index-1].setSalary(salary);
					System.out.println("-----------------------------------------------------");
					System.out.printf("[%2d] %15s\t%28d\n",index,employee[index-1].getName(),employee[index-1].getSalary());
					System.out.println("-----------------------------------------------------");
			
			}
			
			else {
				
				System.out.println("Wrong input. Try again");
				
			}
		}

		
	}

	
	
	
	
}
