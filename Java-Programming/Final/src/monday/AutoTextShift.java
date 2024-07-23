package monday;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class AutoTextShift extends JFrame {
	boolean isleft,isright,isspace;
	JTextField text=new JTextField("I Love Java Programming!");		
	JLabel label = new JLabel(text.getText());
	JLabel elabel =new JLabel("Key Pressed: ");
	public  AutoTextShift() {
		
		setTitle("TextShift");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
		text.setFocusable(true);
		text.requestFocus();
		text.addActionListener(new MyActionListener());
	
		label.setFont(new Font("TimesRoman", Font.PLAIN, 30));
		label.setForeground(Color.BLACK); // 글자색 변경
		label.setHorizontalAlignment(JLabel.CENTER);
		label.addKeyListener(new MyKeyListener());
		
		elabel.setHorizontalAlignment(JLabel.CENTER);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(text,BorderLayout.NORTH);
		c.add(label,BorderLayout.CENTER);
		c.add(elabel,BorderLayout.SOUTH);
		
		setSize(500,300); 
		setVisible(true);
		new Thread(new moveThread(this)).start();
		
		
	}
	
	private class MyActionListener implements ActionListener {
		
		public void actionPerformed(ActionEvent e) { 
			JTextField text =(JTextField)e.getSource();
			label.setText(text.getText());
			label.setFocusable(true);
			label.requestFocus();
		}
		
	}
	
	
	
	
	
	
	private class MyKeyListener extends KeyAdapter{
	
		public void keyPressed(KeyEvent e) {
			JLabel label=(JLabel)e.getSource();
			char keyChar = e.getKeyChar();
			int keyInt = e.getKeyCode();
			
			
			if(keyInt==KeyEvent.VK_LEFT) {
					isleft=true;
					isright=false;
				
			}
			
			
			else if(keyInt==KeyEvent.VK_RIGHT) {
				isright=true;
				isleft=false;
				
			}
			
			else if(keyInt==KeyEvent.VK_SPACE) {
				isright=false;
				isleft=false;
				
			}
			
	
			else {	
				switch(keyChar) {
			
				case 'r','R':
					label.setForeground(Color.RED);
					break;
				case 'g','G':
					label.setForeground(Color.GREEN);
					break;
				case 'b','B':
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
	
	public void move() {
	
		for(;;) {
			
		
			if(isleft) 
				left();
				
			else if(isright) 
				right();
			
			
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
	}
	
	public void right() {
		String str=label.getText();
		String sub1,sub2;
		sub1=str.substring(0,str.length()-1);
		sub2=str.substring(str.length()-1);
		label.setText(sub2.concat(sub1));
		
	}	
	
	public void left() {
		String str=label.getText();
		String sub1,sub2,concat;
		str=label.getText();
		sub1=str.substring(0,1);
		sub2=str.substring(1);
		concat=sub2.concat(sub1);
		label.setText(concat);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new AutoTextShift();
	}

}
