package monday;
//2021114818
//김찬호

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;





public class KtxReservationApp extends JFrame {
	KtxSeat ktxseat2=new KtxSeat();
	JLabel label =new JLabel("KTX 좌석 현황");
	ArrayList <ArrayList<JLabel>> seat = new ArrayList <ArrayList<JLabel>>();
	JPanel panel=new JPanel();
	JButton bt =new JButton("예약 시작");
	
	public KtxReservationApp() {
		
		setTitle("KTX 예약시스템");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.BLACK);
		
		label.setFont(new Font("TimesRoman", Font.PLAIN, 30));
		label.setForeground(Color.BLACK); // 글자색 변경
		label.setHorizontalAlignment(JLabel.CENTER);
	
		panel.setBackground(Color.BLACK);
		
		bt.addActionListener(new MyButtonListener());
		
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(label,BorderLayout.NORTH);
		c.add(panel,BorderLayout.CENTER);
		panel.setLayout(new GridLayout(4,10,1,1));
		for(int i=0;i<4;i++) {
			seat.add(new ArrayList<JLabel>());
			for(int j=0;j<10;j++) {
				String seatNum=String.format("%d%c",j+1,'D'- i);
				seat.get(i).add(new JLabel(seatNum));
				seat.get(i).get(j).setOpaque(true);
				seat.get(i).get(j).setHorizontalAlignment(JLabel.CENTER);
				seat.get(i).get(j).setBackground(Color.WHITE);
				panel.add(seat.get(i).get(j));
			}
		}
		
	
		
		ktxseat2.setGUI(this);
		c.add(bt,BorderLayout.SOUTH);
		setSize(750,250); 
		setVisible(true);
		
		
	}
	
	private class  MyButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent e) { 
			
			
			new Person(ktxseat2,"p1").start();
			new Person(ktxseat2,"p2").start();
			new Person(ktxseat2,"p3").start();
			new Person(ktxseat2,"p4").start();
			new Person(ktxseat2,"p5").start();
			new Person(ktxseat2,"p6").start();
			
			new Person(ktxseat2,"police1").start();
			new Person(ktxseat2,"police2").start();
			
			new Person(ktxseat2,"broker1").start();
			new Person(ktxseat2,"broker2").start();
		
		}
	}
	

	
	
	public static void main(String[] args) {
		new KtxReservationApp();

	}

}
