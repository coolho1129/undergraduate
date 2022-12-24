package friday;
//2021114818
//김찬호

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KtxReservationApp extends JFrame {
	KtxSeat ktxseat=new KtxSeat();
	JLabel label =new JLabel("KTX 좌석 현황");
	JLabel seat[][]=new JLabel[4][10];
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
			for(int j=0;j<10;j++) {
				String seatNum=String.format("%d%c",j+1,'D'- i);
				seat[i][j]=new JLabel(seatNum);
				seat[i][j].setOpaque(true);
				seat[i][j].setHorizontalAlignment(JLabel.CENTER);
				seat[i][j].setBackground(Color.WHITE);
				panel.add(seat[i][j]);
			}
		}
		
	
		
		ktxseat.setGUI(this);
		c.add(bt,BorderLayout.SOUTH);
		setSize(750,250); 
		setVisible(true);
		
		
	}
	
	private class  MyButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent e) { 
			
			
			new Person(ktxseat,"p1").start();
			new Person(ktxseat,"p2").start();
			new Person(ktxseat,"p3").start();
			new Person(ktxseat,"p4").start();
			new Person(ktxseat,"p5").start();
			new Person(ktxseat,"p6").start();
			
			new Person(ktxseat,"police1").start();
			new Person(ktxseat,"police2").start();
			
			new Person(ktxseat,"broker1").start();
			new Person(ktxseat,"broker2").start();
		
		}
	}
	
	
	
	public static void main(String[] args) {
		new KtxReservationApp();

	}

}
