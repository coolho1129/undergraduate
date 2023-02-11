package hw7;
//학번: 2021114818
//이름: 김찬호

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class TextShift extends JFrame {

	public TextShift() {
		
		setTitle("TextShift");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JTextField text=new JTextField("I Love Java Programming!");		
		JLabel label = new JLabel(text.getText());
		JLabel elabel =new JLabel("Key Pressed: ");
		
		text.setFocusable(true);
		text.requestFocus();
		text.addActionListener(new MyActionListener(label));
	
		label.setFont(new Font("TimesRoman", Font.PLAIN, 30));
		label.setForeground(Color.BLACK); // 글자색 변경
		label.setHorizontalAlignment(JLabel.CENTER);
		label.addKeyListener(new MyKeyListener(elabel));
		
		elabel.setHorizontalAlignment(JLabel.CENTER);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(text,BorderLayout.NORTH);
		c.add(label,BorderLayout.CENTER);
		c.add(elabel,BorderLayout.SOUTH);
		
		setSize(500, 300); 
		setVisible(true);
		
		
		
	}
	
	private class MyActionListener implements ActionListener {
		JLabel label;
		
		public MyActionListener(JLabel label) {
			this.label = label;
		}
		
		public void actionPerformed(ActionEvent e) { 
			JTextField text =(JTextField)e.getSource();
			label.setText(text.getText());
			label.setFocusable(true);
			label.requestFocus();
		}
		
	}
	
	
	
	
	
	
	private class MyKeyListener extends KeyAdapter{
		JLabel elabel;
		
		public MyKeyListener(JLabel elabel) {
			this.elabel=elabel;
		}
		
		public void keyPressed(KeyEvent e) {
			JLabel label=(JLabel)e.getSource();
			char keyChar = e.getKeyChar();
			int keyInt = e.getKeyCode();
			
			if(keyInt==KeyEvent.VK_LEFT) {
				String str=label.getText();
				String sub1,sub2;
				sub1=str.substring(0,1);
				sub2=str.substring(1);
				label.setText(sub2.concat(sub1));
			}
			
			else if(keyInt==KeyEvent.VK_RIGHT) {
				String str=label.getText();
				String sub1,sub2;
				sub1=str.substring(0,str.length()-1);
				sub2=str.substring(str.length()-1);
				label.setText(sub2.concat(sub1));
			}
			
			else {	
				switch(keyChar) {
			
				case 'r':
					label.setForeground(Color.RED);
					break;
				case 'g':
					label.setForeground(Color.GREEN);
					break;
				case 'b':
					label.setForeground(Color.BLUE);
					break;
				default:
					label.setForeground(Color.BLACK);
					break;
				}
			}
			elabel.setText("KeyEvent: "+ KeyEvent.getKeyText(keyInt)+" pressed");
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new TextShift();
	}

}
