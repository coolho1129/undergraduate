package friday;
//2021114818
//김찬호

import java.util.*;

class Calc {
		 protected int a, b;
		 public Calc() {
		a = b = 0;
		 }
		 public void setValue(int a, int b) {
			 this.a = a;
			 this.b = b;
		 }
		 	public int calculate(int a,int b) { // 서브 클래스에서 재정의
		 		return 0;
		}
	}


 class Add extends Calc{
	
	 int result;
	 
	
	 
	 public String toString() {
		 
		 
		 return "Add:" + a + " + " + b +  " = " + result;
	 }
	 
	 
	 public int calculate(int a ,int b) {
		 this.result=a+b;
		 
		 return result;
		
		 
	 }

 }

 class Sub extends Calc{
		
	 int result;
	

	 public String toString() {
		 
		 
		 return "Sub:" + a + " - " + b + " = " + result;
	 }
	 
	 
	 public int calculate(int a ,int b) {
		 this.result=a-b;
		 
		 return result;
		
		 
	 }

 }
 
 class Mul extends Calc{
		
	 int result;
	 

	 public String toString() {
		 
		 
		 return "Mul:" + a + " * " + b + " = " + result;
	 }
	 
	 
	 public int calculate(int a ,int b) {
		 this.result=a*b;
		 
		 return result;
		
		 
	 }

 }
 
 class Div extends Calc{
		
	 int result;
	

	 public String toString() {
		 
		 
		 return "Div:" + a + " / " + b + " = " + result;
	 }
	 
	 
	 public int calculate(int a ,int b) {
		 this.result=a/b;
		 
		 return result;
		
		 
	 }

 }
	
	
	








public class Calculator  {


	public static void main(String[] args) {
		
		int num1,num2;
		String op;
		Scanner scan=new Scanner(System.in);
		
		
		for(;;) {
			
				
				System.out.print("두 정수와 연산자를 입력하세요(종료: -1 -1):");
				try {
					
					num1=scan.nextInt();
					num2=scan.nextInt();
					
					if(num1==-1&&num2==-1) {
						System.out.println("종료합니다.");
						scan.close();
						break;
					}
					
					else
						op=scan.next();
					
					
				}
				catch(InputMismatchException e){
					
					System.out.println("잘못된 입력입니다. 다시 입력하세요. ");
					scan.nextLine();
					continue;
					
				}
				
				
			
			
			
			
		
			
			switch(op) {
			
				case "+":
					System.out.println("덧셈 연산");
					Add add= new Add();
					add.calculate(num1, num2);
					add.setValue(num1, num2);
					System.out.println(add);
					break;
					
				case "-":
					System.out.println("뺄셈 연산");
					Sub sub= new Sub();
					sub.calculate(num1, num2);
					sub.setValue(num1, num2);
					System.out.println(sub);
					break;
				
				case "*":
					System.out.println("곱셈 연산");
					Mul mul= new Mul();
					mul.calculate(num1, num2);
					mul.setValue(num1, num2);
					System.out.println(mul);
					break;
					
				case "/":
					System.out.println("나눗셈 연산");
					Div div= new Div();
					if(num2!=0) {
					div.calculate(num1, num2);
					div.setValue(num1, num2);
					System.out.println(div);
					}
					else
						System.out.println("0으로 나눌 수 없습니다.");
					break;
					
					
				
				default:
					System.out.println("잘못된 연산자입니다. 다시 입력하세요.");
					
					
				
			
			}
		
		
		
		
		}
		

	}
	
}


