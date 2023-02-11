package monday;
//2021114818
//김찬호
public class YutPlayerApp {

	public static void main(String[] args) {
		YutPlayer player1 =new YutPlayer("흥부");
		YutPlayer player2 =new YutPlayer("놀부");
		boolean stop=false;
	
		for(;;) {
		
			for(;;) {
				
				player1.castYut();
				player1.setTotalScore();
				
				if(player1.score<4) {
					System.out.print(player1);
					System.out.printf("(%d점/총 %2d점)--->\n",player1.score,player1.getTotalScore());
					if((player1.getTotalScore()>=20))
						stop=true;
					break;
				}
				
				else {
					System.out.print(player1);
					System.out.printf("(%d점/총 %2d점)--->\n",player1.score,player1.getTotalScore());
					if((player1.getTotalScore()>=20)) {
						stop=true;
						break;
					}
				}
				
			}
			
			if(stop)
				break;
			
			for(;;) {
		
				player2.castYut();
				player2.setTotalScore();
		
				if(player2.score<4) {
					System.out.printf("\t\t\t\t<---(%d점/총 %2d점)",player2.score,player2.getTotalScore());
					System.out.println(player2);
					if((player2.getTotalScore()>=20)) {
						stop=true;
					}
					break;
				}
				else {
					System.out.printf("\t\t\t\t<---(%d점/총 %2d점)",player2.score,player2.getTotalScore());
					System.out.println(player2);
					
					if((player2.getTotalScore()>=20)) {
						stop=true;
						break;
					}
				}
			}
			
			if(stop)
				break;
			
			
		}
		System.out.println("");
		System.out.printf("흥부: %2d, 놀부: %2d ==> ",player1.getTotalScore(),player2.getTotalScore());
		if(player1.compareTo(player2)==1)
			System.out.println("흥부 승리");
		
		else if(player1.compareTo(player2)==-1)
			System.out.println("놀부 승리");
		
		System.out.println("-------------------------------------------------");	
		player1.displayResult();
		player2.displayResult();
		
			
			
			
			
		}
	

}

	

