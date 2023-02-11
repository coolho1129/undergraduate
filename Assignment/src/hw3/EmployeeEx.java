//학번: 2021114818
//이름: 김찬호


package hw3;
import java.util.Scanner;

public class EmployeeEx {

	public static void main(String[] args) {
		
		Staff[] staffs=new Staff[3];
		Engineer[] engineers=new Engineer[3]; 
		int[] cnt=new int[10];
		
		for(int i=0;i<staffs.length;i++) {
			
			staffs[i]=new Staff();
			
		}
		
		for(int i=0;i<engineers.length;i++) {
	
			engineers[i]=new Engineer();
	
		}
		
		staffs[0].setName("John", "Smith");
		staffs[0].setAge(25);
		staffs[0].setPosition("Newcomer");
		staffs[0].setSalary(300);
		
		staffs[1].setName("Marry", "Anne");
		staffs[1].setAge(45);
		staffs[1].setPosition("Executive");
		staffs[1].setSalary(600);
		
		staffs[2].setName("Sue", "Jones");
		staffs[2].setAge(38);
		staffs[2].setPosition("Office manager");
		staffs[2].setSalary(450);

		engineers[0].setName("Bob", "Lewis");
		engineers[0].setAge(28);
		engineers[0].setPosition("Junior Engineer");
		engineers[0].setSalary(350);
		engineers[0].setOverWorkingDay(17);
		
		engineers[1].setName("Lisa", "Barnes");
		engineers[1].setAge(37);
		engineers[1].setPosition("Senior Engineer");
		engineers[1].setSalary(580);
		engineers[1].setOverWorkingDay(20);
		
		engineers[2].setName("Michael", "Kevin");
		engineers[2].setAge(46);
		engineers[2].setPosition("SW Manager");
		engineers[2].setSalary(650);
		engineers[2].setOverWorkingDay(20);
		
		
		Scanner scan = new Scanner(System.in);
		
		
		
		for(;;) {
			System.out.println("========================================================");
			System.out.println("1. Display all employees' information (Staff, Engineer)");
			System.out.println("2. Display all staffs' information ");
			System.out.println("3. Display all engineers' information ");
			System.out.println("4. Display all employees' name, salary, annual salary ");
			System.out.println("5. Display all employees' name, position");
			System.out.println("6. Display statistics of annual salary ");
			System.out.println("0. Quit");
			System.out.println("========================================================");
			System.out.print("-> ");
			
			int menu=scan.nextInt();
			
			if (menu==0) {
				
				
				System.out.println("Bye!");
				scan.close();
				break;
				
			}
			else if(menu==1) {
				System.out.println("[Staff]");
				System.out.printf("%15s %4s %18s %10s %15s\n","Name","Age","Position","Salary","Annual Salary");
				System.out.println("--------------------------------------------------------------------");
				
				for(int i=0;i<staffs.length;i++)
					staffs[i].printEmployeeInfo();
				
				
					
				
				System.out.println("[Engineer]");
				System.out.printf("%15s %4s %18s %16s %10s %14s\n","Name","Age","Position","Overworking Pay","Salary","Annual Salary");
				System.out.println("-----------------------------------------------------------------------------------");
				for(int i=0;i<engineers.length;i++)
					engineers[i].printEmployeeInfo();
				
				
			}
			
			else if(menu==2) {
				System.out.println("[Staff]");
				System.out.printf("%15s %4s %18s %10s %15s\n","Name","Age","Position","Salary","Annual Salary");
				System.out.println("--------------------------------------------------------------------");
				
				for(int i=0;i<staffs.length;i++)
					staffs[i].printEmployeeInfo();
				
				
				
				
			}
			
			else if(menu==3) {
				
				System.out.println("[Engineer]");
				System.out.printf("%15s %4s %18s %16s %10s %14s\n","Name","Age","Position","Overworking Pay","Salary","Annual Salary");
				System.out.println("-----------------------------------------------------------------------------------");
				for(int i=0;i<engineers.length;i++)
					engineers[i].printEmployeeInfo();
				
				
				
				
			}
			
			else if(menu==4) {
				
				System.out.println("[Staff]");
				System.out.printf("%15s  %11s\t%11s \n","Name","Salary","Yearly Salary");
				System.out.println("----------------------------------------------------");
				
				for(int i=0;i<staffs.length;i++)
					System.out.printf("%15s %10d %15d\n" ,staffs[i].getName(), staffs[i].getSalary(),staffs[i].getAnnualSalary());
				
				System.out.println("");
				System.out.println("[Engineer]");
				System.out.printf("%15s  %11s\t%11s \n","Name","Salary","Yearly Salary");
				System.out.println("----------------------------------------------------");
				
				for(int i=0;i<engineers.length;i++)
					System.out.printf("%15s %10d %15d\n" ,engineers[i].getName(), engineers[i].getSalary(),engineers[i].getAnnualSalary());
				
				
			}
			
			else if(menu==5) {
				System.out.println("[Staff]");
				System.out.printf("%15s  %19s\n","Name","Position");
				System.out.println("----------------------------------------------------");
				
				for(int i=0;i<staffs.length;i++)
					System.out.printf("%15s %20s \n" ,staffs[i].getName(), staffs[i].getPosition());
				
				System.out.println("");
				System.out.println("[Engineer]");
				System.out.printf("%15s  %19s\n","Name","Position");
				System.out.println("----------------------------------------------------");
				
				for(int i=0;i<engineers.length;i++)
					System.out.printf("%15s %20s\n" ,engineers[i].getName(), engineers[i].getPosition());
				
				
				
				
			}
			
			
			else if(menu==6) {
				
				
				for(int i=0;i<staffs.length;i++) {
					cnt[(staffs[i].getAnnualSalary()/1000)]++;
				}
				for(int i=0;i<engineers.length;i++) {
						cnt[(engineers[i].getAnnualSalary()/1000)]++;	
					
					
					
				}
				
				for(int i=0;i<cnt.length;i++) {
					
					System.out.printf("[%d000]:",i);
					
					for(int j=0;j<cnt[i];j++) {
						System.out.print("#");
					}
					
					System.out.println("");
				}
			
			
			
			}
			
			else {
				
				
				
				System.out.println("Wrong input. Try again!");
				
			} 
				
			
			
				
			
			
	} 
		
	
			
		

	
		}
	
	
	
	
	
}
