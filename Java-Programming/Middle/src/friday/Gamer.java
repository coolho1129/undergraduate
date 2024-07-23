package friday;

//2021114818
//김찬호
public class Gamer implements RollingDiceInterface{

	int num1,num2,Max;
	int Dice[];
	
	String Name; 
	
	public Gamer(String Name, int Maxnum) {
		this.Name=Name;
		this.Max=Maxnum;
	}

	
	public String toString() {
		
		if(getFaceNumbers()[0]<10&&getFaceNumbers()[1]<10) {
			if(getDiceSum()<9)
				return Name +"("+" "+getFaceNumbers()[0]+", "+getFaceNumbers()[1]+") =  "+ getDiceSum();
			else
				return Name +"("+" "+getFaceNumbers()[0]+", "+getFaceNumbers()[1]+") = "+ getDiceSum();
		
		
		}
		else if (getFaceNumbers()[0]<10&&getFaceNumbers()[1]>=10) {
			if(getDiceSum()<9)
				return Name +"("+" "+getFaceNumbers()[0]+","+getFaceNumbers()[1]+") =  "+getDiceSum();
			else
				return Name +"("+" "+getFaceNumbers()[0]+","+getFaceNumbers()[1]+") = "+getDiceSum();
		}
		else if (getFaceNumbers()[0]>=10&&getFaceNumbers()[1]<10) {
			if(getDiceSum()<9) 
				return Name +"("+getFaceNumbers()[0]+", "+getFaceNumbers()[1]+") =  "+getDiceSum();
			else
				return Name +"("+getFaceNumbers()[0]+", "+getFaceNumbers()[1]+") = "+getDiceSum();
		}
			else {
				if(getDiceSum()<9) 
					return Name +"("+getFaceNumbers()[0]+","+getFaceNumbers()[1]+") =  "+getDiceSum();
				else
					return Name +"("+getFaceNumbers()[0]+","+getFaceNumbers()[1]+") = "+getDiceSum();
		}
	}
	

	
	
	
	
	@Override
	public void roll() {
		num1=(int)(Math.random()*Max+1);
		num2=(int)(Math.random()*Max+1);
	}

	@Override
	public int[] getFaceNumbers() {
		this.Dice= new int [2];
		Dice[0]=num1;
		Dice[1]=num2;
		
		
		
		return Dice;
	}

	@Override
	public int getDiceSum() {
		
		return Dice[0]+Dice[1];
	}

	@Override
	public int compareTo(Object obj) {
		
		int player1 =this.getDiceSum();
		int player2 =((Gamer)obj).getDiceSum();
		
		if(player1>player2)
			return 1;
		
		else if(player1 == player2)
			return 0;
		
		else
			return -1;


	

	}
}
