//2021114818
//김찬호

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Palindrome extends JFrame {
	JTextField text=new JTextField("");		
	JLabel label = new JLabel("Palindrome");
	JButton bt= new JButton("회문검사");

	public Palindrome() {
		setTitle("회문검사 프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
		text.setFocusable(true);
		text.requestFocus();
		text.addActionListener(new MyActionListener());
	
		label.setFont(new Font("TimesRoman", Font.PLAIN, 50));
		label.setForeground(Color.BLACK); // 글자색 변경
		label.setHorizontalAlignment(JLabel.CENTER);
		
		bt.addActionListener(new MyButtonListener());
		
		
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(text,BorderLayout.NORTH);
		c.add(bt,BorderLayout.CENTER);
		c.add(label,BorderLayout.SOUTH);
		
		
		setSize(500,300); 
		setVisible(true);
	}
	
	public void check() {
		
		String input,reverse;
		input=text.getText();
		StringBuffer sb =new StringBuffer(input);
		reverse=sb.reverse().toString();
		
		if(input.equals(reverse)) {
			label.setText("Palindrome");
		
		}
		else
			label.setText("No Palindrome");
	}
		
	
	
	
	
	private class MyActionListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) { 
			JTextField text =(JTextField)e.getSource();
			bt.setFocusable(true);
			bt.requestFocus();
			
		}
		
	}
	
	
	private class  MyButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent e) { 
			JButton bt =(JButton)e.getSource();
			check();
		
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Palindrome();
	}

}
