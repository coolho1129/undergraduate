import java.awt.*;
import javax.swing.*;

//2021114818
//김찬호

public class Person extends Thread{
	KtxSeat callback;
	String threadName,seatName,change;
	KtxReservationApp gui;
	int row,col;
	String seat[][]= new String[4][10];
	
			
			
	
	public Person(KtxSeat obj,String name) {
		this.callback=obj;
		this.threadName=name;
	}
	
	public void run() {
		
		for(int i=0;i<20;i++) {
			
			selectThread();
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		}
		System.out.println(threadName+"종료");
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
			if(gui.seat[row][col].getText().contains("broker")&&callback.cancelSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat[row][col].setText(change);
				gui.seat[row][col].setBackground(Color.GREEN);
				gui.seat[row][col].setHorizontalAlignment(JLabel.CENTER);
			}
		}
		else if(threadName.contains("broker")) {
			if(callback.reserveSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat[row][col].setText(change);
				gui.seat[row][col].setBackground(Color.RED);
				gui.seat[row][col].setHorizontalAlignment(JLabel.CENTER);
				
			}
			
		}
			
		else {
			if(callback.reserveSeat(seatName,threadName,row,col)==0) {
				change=seatName+"("+threadName+")";
				gui.seat[row][col].setText(change);
				gui.seat[row][col].setBackground(Color.YELLOW);
				gui.seat[row][col].setHorizontalAlignment(JLabel.CENTER);
				
			}
			
		}
		
	}
	


}
