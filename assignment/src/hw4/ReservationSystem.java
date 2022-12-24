package hw4;

import java.util.InputMismatchException;
import java.util.Scanner;

//학번: 2021114818
//이름: 김찬호


public class ReservationSystem implements ReservationInterface {
	
	
	
	int [][] seats;
	int findrow,findcol,Seat=0,input;
	String seatName;
	Scanner scan;

	
	public ReservationSystem(Scanner scan) {
		this.scan=scan;
		
	}

	public void selectMenu(String systemTitle) {
		
		
		for(;;) {
			
			for(;;) {
				System.out.println("-------------------------" );
				System.out.printf("%s \n",systemTitle);
				System.out.println("1. 좌석 예약");
				System.out.println("2. 예약 취소");
				System.out.println("3. 예약 현황 조회");
				System.out.println("4. 메인 메뉴로 돌아가기");
				System.out.println("-------------------------" );
				System.out.print(" 번호를 선택해주세요: ");
			
				try {
			
					input=scan.nextInt();
		
				}
		
		
				catch(InputMismatchException e) {
					System.out.println("잘못된 번호 선택입니다. 숫자를 다시 입력해주세요 (1~4)");
					scan.next();
					continue;
				}
		
				if(1<=input&&input<=4) {
					break;
				}
		
				else {
					System.out.println("잘못된 번호 선택입니다. 다시 입력해주세요 (1~4)");
					continue;
				}
	
			}
	
			if(input==1) {
				
				System.out.print("예약할 좌석 이름을 입력하세요: ");
				seatName=scan.next();
				if(reserveSeat(seatName)==0) 
					displaySeat(systemTitle);
				
			}
		
		
		
		
			else if(input==2) {
			
				System.out.print("취소할 좌석 이름을 입력하세요: ");
				seatName=scan.next();
				if(cancelSeat(seatName)==0) 
					displaySeat(systemTitle);
				
		}
		
		
			else if(input==3) {
				displaySeat(systemTitle);
			}
		
		
			else if(input==4) {
				System.out.printf("%s을 종료하고 메인 메뉴로 돌아갑니다.\n",systemTitle);
				break;
			}
		}
			
}
			

	@Override
	public void makeSeats(int row, int col) {
	
		this.seats= new int[row][col];
	}

	
	@Override
	public int reserveSeat(String seatName) {
		
		if(seatName.length()==2) {
		  findcol=seatName.charAt(0)-'0'-1;
		  findrow=seats.length-1-(seatName.charAt(1)-'A');
		}
			
		else if(seatName.length()==3) {
			findcol=(seatName.charAt(0)-'0')*10+seatName.charAt(1)-'0'-1;
			findrow=seats.length-1-(seatName.charAt(2)-'A');
			}
		else {
			System.out.printf("[예약 실패]: 잘못된 좌석 이름입니다.\n");
			return -1;
			
		}
		
		
		if(Character.isDigit(seatName.charAt(0))==false) {
			System.out.printf("%s: 숫자가 아닌 잘못된 좌석 이름입니다. \n",seatName);
			System.out.printf("[예약 실패]: 잘못된 좌석 이름입니다.\n");
			return -1;
		}
		
		else if(!((0<=findrow&&findrow<seats.length)&&(0<=findcol&&findcol<seats[0].length))) {
			System.out.printf("%s: 좌석의 범위를 넘은 잘못된 좌석 이름입니다. \n",seatName);
			System.out.printf("[예약 실패]: 잘못된 좌석 이름입니다.\n");
			return -1;
		}
	
		else if(this.seats[findrow][findcol]==0) {
			this.seats[findrow][findcol]=1;
			System.out.printf("[예약 성공] %s\n",seatName);
			Seat++;
			
			
			
			return 0;
		}
		
		else if(this.seats[findrow][findcol]==1) {
			System.out.printf("[예약 실패] %s: 이미 예약된 좌석입니다.\n",seatName);
			return -1;
		}
		
		else {
			System.out.printf("[예약 실패]: 잘못된 좌석 이름입니다.\n");
			return -1;
			
		}
	}

	
	@Override
	public int cancelSeat(String seatName) {
		if(seatName.length()==2) {
			  findcol=seatName.charAt(0)-'0'-1;
			  findrow=seats.length-1-(seatName.charAt(1)-'A');
			}
				
		else if(seatName.length()==3) {
				findcol=(seatName.charAt(0)-'0')*10+(seatName.charAt(1)-'0')-1;
				findrow=seats.length-1-(seatName.charAt(2)-'A');
			}
		
		else {
				System.out.printf("[예약 취소 실패]: 잘못된 좌석 이름입니다.\n");
				return -1;
				
			}
		
		
		if(Character.isDigit(seatName.charAt(0))==false) {
			System.out.printf("%s: 숫자가 아닌 잘못된 좌석 이름입니다. \n",seatName);
			System.out.printf("[예약 취소 실패]: 잘못된 좌석 이름입니다.\n");
			return -1;
		}
		
		else if(!((0<=findrow&&findrow<seats.length)&&(0<=findcol&&findcol<seats[0].length))) {
				System.out.printf("%s : 좌석의 범위를 넘은 잘못된 좌석 이름입니다. \n",seatName);
				System.out.printf("[예약 취소 실패]: 잘못된 좌석 이름입니다.\n");
				return -1;
			}
		
		else if(this.seats[findrow][findcol]==1) {
				this.seats[findrow][findcol]=0;
				System.out.printf("[예약 취소 성공] %s\n",seatName);
				Seat--;
				
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

	

	@Override
	public void displaySeat(String systemTitle) {
		
			System.out.printf("[%s 예약 현황] 예약 좌석: %d/ 총 좌석: %d\n",systemTitle,Seat,seats.length*seats[0].length);
			System.out.println("");
			for(int i=0;i<this.seats.length;i++) {
				for(int j=0;j<this.seats[i].length;j++) {
					System.out.printf("[%2d%c] ",j+1,seats.length-1-i+'A');
					
				}
				System.out.println("");
				for(int j=0;j<this.seats[i].length;j++) {
					if(seats[i][j]==0){
						System.out.printf("%4c  ",'O');
					}
					else {
						System.out.printf("%4c  ",'X');
						
					}
				}
				System.out.println("");
				if(i==(seats.length/2-1)) {
					System.out.println("-----------------------------------------------------------");
					System.out.println("  앞\t\t\t   통로\t\t\t\t  뒤");
					System.out.println("-----------------------------------------------------------");
				}
				
			
			}
		}
			
		
	
 }
	
		
	


	








