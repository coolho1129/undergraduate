package friday;
//2021114818
//김찬호
import java.util.*;

public class RollingDiceApp {

	
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		Gamer player1=new Gamer("Alice",14);
		Gamer player2=new Gamer("Bob",14);
		int N;
		int count[]=new int[27];
		int frq[][]=new int[14][14];
		System.out.print("주사위를 던질 회수를 입력하세요: ");
		N=scan.nextInt();
		System.out.println("---------------------------------");
		
		
		for(int i=0;i<N;i++) {
			player1.roll();
			player1.getFaceNumbers();
			player1.getDiceSum();
			player2.roll();
			player2.getFaceNumbers();
			player2.getDiceSum();
			
			count[player1.getDiceSum()-2]++;
			count[player2.getDiceSum()-2]++;
			frq[player1.getFaceNumbers()[0]-1][player1.getFaceNumbers()[1]-1]++;
			frq[player2.getFaceNumbers()[0]-1][player2.getFaceNumbers()[1]-1]++;
			
			System.out.print(player1);
			
			if(player1.compareTo(player2)==1) {
				System.out.print("  >\t");
				
			}
			else if(player1.compareTo(player2)==0) {
				System.out.print("  =\t");
				
			}
			else {
				System.out.print("  <\t");
			}
			
			System.out.print(player2);
			
			System.out.print(" : ");
			if(player1.compareTo(player2)==1) {
				System.out.println(player1.Name + " Win");
				
			}
			else if(player1.compareTo(player2)==0) {
				System.out.println("Even game");
				
			}
			else {
				System.out.println(player2.Name + " Win");
			}
			
			
			
			
			
		}
		
		
		System.out.println("");	
		System.out.println("[두 주사위 합의 빈도수]");
		System.out.println("--------------------------------------------------------------------------------");
		
		for(int i=0;i<27;i++)
			System.out.printf("%2d ",i+2);
		
		System.out.println("");	
		System.out.println("--------------------------------------------------------------------------------");
		
		for(int i=0;i<27;i++)
			System.out.printf("%2d ",count[i]);
		
		System.out.println("");	
		System.out.println("--------------------------------------------------------------------------------");
		
		System.out.println("[주사위 숫자별 빈도수]");
		System.out.print("  ");
		
		for(int i=1;i<15;i++)
			System.out.printf("%2d ",i);
		
		System.out.println("");
		
		for(int i=0;i<14;i++) {
			System.out.printf("%2d",i+1);
			for(int j=0;j<14;j++) {
				System.out.printf("%2d ",frq[i][j]);
				
			}
			System.out.println("");	
		}
		System.out.println("--------------------------------------------");	
		scan.close();
	}
	

}
