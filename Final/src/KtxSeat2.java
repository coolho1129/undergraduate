import java.awt.Color;

//2021114818
//김찬호
public class KtxSeat2 {
	int [][] seats =new int [4][10];
	String [][]owner=new String[4][10];
	KtxReservationApp2 gui;
	int count=0;
	
	public int reserveSeat(String seatName,String threadName,int findrow,int findcol) {
		
		if(count==40) {
			System.out.println(threadName+"가 빈 좌석이 없어서 예약이 불가능합니다.");
			return -1;
		}
	
		if(threadName.contains("broker")) {
			if(this.seats[findrow][findcol]==0) {
				this.seats[findrow][findcol]=1;
				owner[findrow][findcol]=threadName;
				count++;
				System.out.printf("[좌석 예약] %s: 좌석: %s\n",owner[findrow][findcol],seatName);
				
			
				return 0;
			}
			
			else if(this.seats[findrow][findcol]==1) {
				System.out.printf("[예약 실패] 좌석: %s은 이미 예약된 좌석입니다.\n",seatName);
				return -1;
			}
			return -1;
		}
			
		else {
			if(this.seats[findrow][findcol]==0||this.seats[findrow][findcol]==2) {
				this.seats[findrow][findcol]=1;
				owner[findrow][findcol]=threadName;
				count++;
				System.out.printf("[좌석 예약] %s: 좌석:%s 남은 좌석: %d\n",owner[findrow][findcol],seatName,40-count);
				
			
				return 0;
			}
			
			else if(this.seats[findrow][findcol]==1) {
				System.out.printf("[예약 실패] 좌석: %s은 이미 예약된 좌석입니다\n",seatName);
				return -1;	
		
			}
			return -1;
		}
			
			
	}
		
	
	

	

	public int cancelSeat(String seatName,String threadName,int findrow,int findcol) {
		
		
		
		
		if(this.seats[findrow][findcol]==1) {
				this.seats[findrow][findcol]=2;
				owner[findrow][findcol]=threadName;
				count--;
				System.out.printf("[예약 취소] %s: 좌석:%s 남은 좌석: %d\n",owner[findrow][findcol],seatName,40-count);
				
				return 0;
		}
			
		else if(this.seats[findrow][findcol]==0) {
				System.out.printf("[예약 취소 실패] %s: 예약 되지 않은 좌석입니다.\n",seatName);
				return -1;
			}
		
		else {
				System.out.printf("[예약 취소 실패]: 잘못된 좌석 이름입니다.\n");
				return -1;
				
			}
	

	}

	public void setGUI(KtxReservationApp2 gui) {
		this.gui=gui;
	}
	
	public KtxReservationApp2 getGUI() {
		return this.gui;
	}

	public int colorYellow() {
		int count=0;
		for(int i=0;i<4;i++) {
			for(int j=0;j<10;j++) {
				if(gui.seat.get(i).get(j).getBackground()==Color.YELLOW) 
					count++;
			}
		}
		return count;
	}





	

}
