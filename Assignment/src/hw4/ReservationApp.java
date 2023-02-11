
//학번: 2021114818
//이름: 김찬호
package hw4;
import java.util.*;

public class ReservationApp {

	public static void main(String[] args) {

		Scanner scan =new Scanner(System.in);
		AirlineSystem air = new AirlineSystem(scan);
		BusSystem bus = new BusSystem(scan); 
		
		
		int menu;
	
		air.makeSeats(4, 10);
		bus.makeSeats(3, 10);
		
		
		for(;;) {
			
			
			for(;;) {
				System.out.println("----------------------------------------------");
				System.out.println("  K-Startup의 통합 예약 시스템을 방문해 주셔서 감사합니다.");
				System.out.println("    1. 항공사 예약 시스템");
				System.out.println("    2. 버스 예약 시스템 ");
				System.out.println("    0. 통합 예약 시스템 종료");
				System.out.println("----------------------------------------------");
				System.out.print(" 메뉴를 선택해주세요: ");
				
				try {
					menu=scan.nextInt();
			
				}
			
			
				catch(InputMismatchException e) {
					System.out.println("잘못된 메뉴 선택입니다. 숫자를 다시 입력해주세요 (0~2)");
					scan.next();
					continue;
				}
			
				if(0<=menu&&menu<=2)
					break;
			
				else {
					System.out.println("잘못된 메뉴 선택입니다.  다시 입력해주세요 (0~2)");
					continue;
				
				}
			}
			
			
			
			if(menu==0) {
				System.out.println("K-Startup 통합 예약 시스템을 종료합니다." );
				scan.close();
				break;
			}
			
			else if(menu==1) {
				
				air.selectMenu("항공사 예약 시스템");
				
			}

			else if(menu==2) {
				bus.selectMenu("버스 예약 시스템");
				
			}
		}
	}
}
					

		
		
		
		
		
		
	



