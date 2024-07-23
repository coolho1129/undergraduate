package hw8;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class CurrencyConverterFrame extends JFrame {
	String url;
	JLabel changeLabel=new JLabel("환율 변환");
	JLabel Label=new JLabel();
	JLabel Label2=new JLabel();
	JTextArea currency= new JTextArea ();
	JTextField text=new JTextField("0");	
	JTextField text2=new JTextField("0");
	JComboBox<String> changeBox=new JComboBox<String>();
	JLabel dateLabel=new JLabel("Updated ");
	HashMap<String, Double> exchange=new HashMap<>();
	boolean ininit=true;
	
	public CurrencyConverterFrame(String url) {
		this.url = url;
		changeBox.addActionListener(new currencyCombo());
		//changeBox.addItemListener(new ItemChangeListener());
		text.addActionListener(new MyActionListener1());
		text2.addActionListener(new MyActionListener2());
			
		setTitle("환율 계산기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		Container c = getContentPane();
		c.setLayout(new GridLayout(3,3));
		c.add(changeLabel);
		c.add(changeBox);
		c.add(dateLabel);
		
		c.add(Label);
		c.add(Label2);
		c.add(currency);
		
		c.add(text);
		c.add(text2);
		
		//changeBox.setLayout(new BorderLayout(10,10));

		changeLabel.setHorizontalAlignment(JLabel.RIGHT);
		dateLabel.setHorizontalAlignment(JLabel.CENTER);
		Label.setHorizontalAlignment(JLabel.CENTER);
		Label2.setHorizontalAlignment(JLabel.CENTER);
		text.setHorizontalAlignment(JTextField.RIGHT);
		text2.setHorizontalAlignment(JTextField.RIGHT);
		
		setSize(600, 300); 
		setVisible(true);
		
		new CurrencyDownloadThread(url, this).start();
	}
	
	
	 public void updateLatestDate(String dateString) {
			// TODO Auto-generated method stub
			dateLabel.setText("Update "+dateString);
			
			//System.out.println("update Date");
		}

	public void updateCurrencyData(String currencyName,double exchangeRate) {
		String changeName="";
		switch(currencyName){
			case "1USD":
				changeName="미국USD";
				break;
			case "100&yen":
				changeName="일본JPY(100엔)";
				break;
			case "1EUR":
				changeName="EU(EURO)";
				break;
			case "1CNY":
				changeName="중국CNY";
				break;
			
			}
			
			exchange.put(changeName,exchangeRate);
			currency.setText("");
			
		
			
			for(String key:exchange.keySet()) {
				
				if(ininit) {
					Label.setText(key);
					Label2.setText("한국KRW");
					ininit=false;
				}
				if(exchange.size()==4&&changeBox.getItemCount()<4)
					changeBox.addItem(key+"<->한국KRW");
				
				String data=String.format("%s:%.2f\n",key,exchange.get(key));
				//System.out.println(data);
				
				currency.append(data);
				
			
			}
		}
	
	private class ItemChangeListener implements ItemListener{
	    @Override
	    public void itemStateChanged(ItemEvent event) {
	       if (event.getStateChange() == ItemEvent.SELECTED) {
	          String item =(String) event.getItem();
	          
	          Label.setText(item.split("<->")[0]);
	          Label2.setText(item.split("<->")[1]);
	          
	          text.setText("0");
	          text2.setText("0");
	       }
	    }
	}
	
	private class currencyCombo implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			JComboBox<String> cb = (JComboBox<String>)e.getSource();
			int comboSelectedIndex = cb.getSelectedIndex();
			changeUnitText(comboSelectedIndex);
			
			
			}
		}
	
	public void changeUnitText(int Index) {
		String item=changeBox.getItemAt(Index);
		Label.setText(item.split("<->")[0]);
        Label2.setText(item.split("<->")[1]);
        text.setText("0");
        text2.setText("0");
		
	}
		
	private class MyActionListener1 implements ActionListener {
	
		public void actionPerformed(ActionEvent e) { 
			JTextField input =(JTextField)e.getSource();
			double output=exchange(Label.getText(),Label2.getText(),Double.parseDouble(input.getText()));
			text2.setText(String.format("%.2f",output));
				
			
		}
		
	}
	
	private class MyActionListener2 implements ActionListener {
		
		public void actionPerformed(ActionEvent e) { 
			JTextField input =(JTextField)e.getSource();
			double output=exchange(Label2.getText(),Label.getText(),Double.parseDouble(input.getText()));
			text.setText(String.format("%.2f",output));
			
		}
		
	}
	
	
	
	public double exchange(String input,String output,double inputMoney) {
		double inputExchange=0,outputMoney=0,outputExchange=0;
		
		if(!(input.equals("한국KRW"))) 
			inputExchange=exchange.get(input);
			
		else if(!(output.equals("한국KRW")))
			outputExchange=exchange.get(output);
			 
		
		
		switch(input) {
		
		case "일본JPY(100엔)":
			outputMoney=inputMoney*inputExchange/100;
			break;
		case "한국KRW":
			if(output.equals("일본JPY(100엔)"))
				outputMoney=100*inputMoney/outputExchange;
			else
				outputMoney=inputMoney/outputExchange;
			break;
			
		default:
			outputMoney=inputMoney*inputExchange;
			break;
	
		}
		
		
		return outputMoney;
		
		
	}

	
	@SuppressWarnings("unused")
	public static void main(String[] args) {
		
		String url="http://fx.kebhana.com/fxportal/jsp/RS/DEPLOY_EXRATE/fxrate_all.html";
		CurrencyConverterFrame exchangeCalculator = new CurrencyConverterFrame(url);
	}

}
