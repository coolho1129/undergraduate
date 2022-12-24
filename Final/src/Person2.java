import java.awt.*;
import javax.swing.*;

//2021114818
//김찬호

public class Person2 extends Thread{
	KtxSeat2 callback;
	String threadName,seatName,change;
	KtxReservationApp2 gui;
	int row,col;
	String seat[][]= new String[4][10];
	
			
			
	
	public Person2(KtxSeat2 obj,String name) {
		this.callback=obj;
		this.threadName=name;
	}
	
	public void run() {
		
		for(;;) {
			
			selectThread();
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if(callback.colorYellow()==40) {
				System.out.println(threadName+"종료");
				break;
			}
		}
		
	}
	
	
	public void makeRandom() {
		row=(int)(Math.random()*4);
		col=(int)(Math.random()*10);
		seatName=String.format("%d%c",col+1,'D'- row);
		//System.out.println(seatName);
	}
	
	synchronized public void selectThread() {
		makeRandom();
		Thread.yield();
		gui=callback.getGUI();
		if(threadName.contains("police")) {
			if(gui.seat.get(row).get(col).getText().contains("broker")&&callback.cancelSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat.get(row).get(col).setText(change);
				gui.seat.get(row).get(col).setBackground(Color.GREEN);
				gui.seat.get(row).get(col).setHorizontalAlignment(JLabel.CENTER);
			}
		}
		else if(threadName.contains("broker")) {
			if(callback.reserveSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat.get(row).get(col).setText(change);
				gui.seat.get(row).get(col).setBackground(Color.RED);
				gui.seat.get(row).get(col).setHorizontalAlignment(JLabel.CENTER);
				
			}
			
		}
			
		else {
			if(callback.reserveSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat.get(row).get(col).setText(change);
				gui.seat.get(row).get(col).setBackground(Color.YELLOW);
				gui.seat.get(row).get(col).setHorizontalAlignment(JLabel.CENTER);
				
			}
			
		}
		
	}
	
	
	


}
