package monday;
//2021114818
//김찬호
public class YutPlayer implements YutInterface{

	int yut[]=new int [4];
	int count[]=new int [5];
	int frq=0;
	int score,total;
	String name,yutname;
	
	public YutPlayer(String string) {
		this.name=string;
	}

	
	public String toString() {
		
		return name +" ["+yut[0]+" "+yut[1]+" "+yut[2]+" "+yut[3]+"] "+ yutname+" ";
		
		
	}
	

	public int setTotalScore() {
		total+=score;
		
		return total;
		
	}
	private double percent(int num) {
		
		return (double)(num)/frq*100;
		
	}
	
	@Override
	public int castYut() {
		int cnt=0;
		for(int i=0;i<4;i++)
			yut[i]=(int)(Math.random()*2);
		
		for(int i=0;i<4;i++) {
			if(yut[i]==0)
				cnt++;
			
		}
		frq++;
		
		if(cnt==0) {
			yutname="모";
			count[4]++;
			score=5;
			
		}
		
		else if(cnt==1) {
			yutname="도";
			count[0]++;
			score= 1;
		}
		
		else if(cnt==2) {
			yutname="개";
			count[1]++;
			score= 2;
		}
		
		else if (cnt==3) {
			yutname="걸";
			count[2]++;
			score= 3;
		}
		
		else {
			count[3]++;
			yutname="윳";
			score= 4;
		}
		return score;
	}

	@Override
	public int getTotalScore() {
		
		return total;
	}

	@Override
	public int compareTo(Object obj) {
		int player1=this.getTotalScore();
		int player2= ((YutPlayer)obj).getTotalScore(); 	
		
		if(player1 > player2)
			return 1; 
		
		else if( player1 == player2)
			return 0;
		
		else
			return -1; 
	}

	@Override
	public void displayResult() {
		System.out.println("\t도\t개\t걸\t윷\t모 단위(%)");
		System.out.println("-------------------------------------------------");
		System.out.printf("%2s\t%2.1f\t%2.1f\t%2.1f\t%2.1f\t%2.1f\n",name,percent(count[0]) ,percent(count[1]),percent(count[2]),percent(count[3]),percent(count[4]));
		System.out.println("-------------------------------------------------");
		
		
	}

}
