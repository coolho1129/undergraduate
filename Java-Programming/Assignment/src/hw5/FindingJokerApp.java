package hw5;
//학번: 2021114818
//이름: 김찬호
import java.util.*;

class Card{
	
	private String suit,num;
	
	public Card(String suit,String num) {
		this.suit=suit;
		this.num=num;
		
		
	}
	
	public String toString() {
		return String.format ("(%s%5s)",suit,num);
	}
	
	public String getNum() {
		
		return this.num;
	}
	public String getSuit() {
	
		return this.suit;
	}
	
	


	
}

class GameDealer{
	
	private String[] suit = {"♣", "♠", "♦", "♥"}; // Joker: 🃟 (Joker suit)
	private String joker = "Joker";
	private String[] number = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	private ArrayList <Card> cardpair = new ArrayList <Card>();
	private Scanner scan = new Scanner(System.in);
	private int turn=0;
	private Player player1;
	private Player player2;
	
	public GameDealer(Player player1, Player player2) {
		this.player1=player1;
		this.player2=player2;
	}




	public void cardPair() {
		
		for(int i=0;i<=suit.length;i++) {
			if(i!=suit.length) {
				for(int j=0;j<number.length;j++) {
					Card card=new Card(suit[i],number[j]);
					cardpair.add(card);
				}
			}
			else {
				Card card=new Card("🃟",joker);
				cardpair.add(card);
				
			}
		}
		
		System.out.println("<< 카드 생성 >>");
		for(int i=0;i<cardpair.size();i++) {
			
			System.out.print(cardpair.get(i));
			if(i%13==12)
				System.out.println("");
				
		}
		
		System.out.println("");
	}
		

	
	
	public void deal() {
		cardPair();
		Collections.shuffle(cardpair);
		
		
		for(;;) {
			player1.getPriCard().add(cardpair.get(0));
			cardpair.remove(0);
			
			if(cardpair.size()==0)
				break;
			
			
			player2.getPriCard().add(cardpair.get(0));
			cardpair.remove(0);
			
		}
	}
		
		
		
	public void game() {
		
		deal();
		//String enter;
		
		for(;;) {
			if(turn==0) {
				
				System.out.printf("\n<<처음 딜러가 나누어 준 카드>>\n");
				player1.printMenu();
				player2.printMenu();
				turn++;
				continue;
				
			}
				
			else if(turn==1) {
				player1.open();
				player2.open();
				System.out.printf("\n<< %2d 단계 >>\n\n",turn);
				printTurn();
						
				if(player2.getPriCard().size()==0) {
					System.out.printf("경기 종료 : %s 가 Joker 를 가지고 있음",player1.getName());
					scan.close();
					break;
				}
				
				System.out.println("다음 단계 게임 진행을 위해 Enter 키를 누르세요 !");
				scan.nextLine();
				
			}
					
			else {
				System.out.printf("\n<< %2d 단계 >>\n\n",turn);
				player1.select(player2);
				printTurn();
					
				if(player1.getPriCard().size()==0) {
					System.out.printf("경기 종료 : %s 가 Joker 를 가지고 있음",player2.getName());
					scan.close();
					break;
				}
				
				else if(player2.getPriCard().size()==0) {
					System.out.printf("경기 종료 : %s 가 Joker 를 가지고 있음",player1.getName());
					scan.close();
					break;
				}
					
				System.out.println("다음 단계 게임 진행을 위해 Enter 키를 누르세요 !");
				scan.nextLine();
					
			}
					
		}
		
			
	}
		
	public void printTurn() {
			
			System.out.println("일치하는 숫자를 가진 카드 공개(2 장씩 허용)");
			player1.printMenu();
			player2.printMenu();
			turn++;
		
	}
		
		
}

class Player {
	
	
	private ArrayList <Card> pubCard = new ArrayList <Card>();
	private ArrayList <Card> priCard = new ArrayList <Card>();
	private String Name;
	
	public Player(String string) {
		Name=string;
	}

	public ArrayList <Card> getPubCard() {
		return this.pubCard;
	}
	
	public ArrayList <Card> getPriCard() {
		return this.priCard;
	}
	
	public String getName() {
		return this.Name;
	}

	public void open() {
		
		for(int i=0;i<priCard.size();i++) {
			for(int j=i+1;j<priCard.size();j++) {
				if(priCard.get(i).getNum().equals(priCard.get(j).getNum())){
					pubCard.add(priCard.remove(i));
					pubCard.add(priCard.remove(j-1));
					i--;
					break;
				}
			}
			
		}

	}
	

	public void select(Player otherplayer) {
		Collections.shuffle(otherplayer.priCard);
		Collections.shuffle(priCard);
		
		int index1=(int)(Math.random()*otherplayer.priCard.size());
		int index2=(int)(Math.random()*priCard.size());
		
		Card sel1= new Card(otherplayer.priCard.get(index1).getSuit(),otherplayer.priCard.get(index1).getNum());
		Card sel2= new Card(priCard.get(index2).getSuit(),priCard.get(index2).getNum());
		
		priCard.add(sel1);
		otherplayer.priCard.add(sel2);
		otherplayer.priCard.remove(index1);
		priCard.remove(index2);
		
		System.out.println("상대방의 카드를 선택하세요 (Random)");
		System.out.println("==================================");
		System.out.printf("%8s 선택 : ",getName());
		System.out.printf("[%2d]%s 가져옴\n",index1,sel1);
		System.out.printf("%8s 선택 : ",otherplayer.getName());
		System.out.printf("[%2d]%s 가져옴",index2,sel2);
		System.out.printf("\n==================================\n");
		
		printMenu();
		otherplayer.printMenu();
		open();
		otherplayer.open();
	
	}
	
	public void printPriCard() {
		
		System.out.printf(" %2d 장\n",priCard.size());
		for(int i=0;i<priCard.size();i++) {
			System.out.printf("[%2d]",i);
			System.out.print(priCard.get(i));
			
			if(i%10==9)
				System.out.println("");
		
		}
		System.out.println("");
		
	
	}
	
	public void printPubCard() {
		
		System.out.printf(" %2d 장\n",pubCard.size());
		for(int i=0;i<pubCard.size();i++) {
			System.out.print(pubCard.get(i));
			
			if(i%10==9)
				System.out.println("");
		
		}
		System.out.println("");
		
	
	}

	public void printMenu() {
		System.out.println("["+getName()+"]");
		System.out.print("공개한 카드:");
		printPubCard();
		System.out.println("");
		System.out.print("가지고 있는 카드:");
		printPriCard();
		System.out.println("---------------------------------------------------------------------------------");
	
	}
}

public class FindingJokerApp {
	public static void main(String[] args) {
		
		GameDealer dealer =new GameDealer(new Player("Computer"),new Player("Human"));
		dealer.game();
		
		
	
		
	}
}






