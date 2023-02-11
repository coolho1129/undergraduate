package hw8;



import java.util.*;
import java.io.*;
import java.net.*;


public class CurrencyDownloadThread extends Thread{
	String url;
	CurrencyConverterFrame callback;
	
	public CurrencyDownloadThread(String url, CurrencyConverterFrame obj) {
		this.url = url;
		this.callback = obj;
	}
	

	public void run(){
		
		for(;;) {
			getLatestCurrency();
		try {
			Thread.sleep(60000);
		}catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			}
		}
		
	}
	
	public void getLatestCurrency() {
		String line = "";
		int responseCode = 0;
		
		try {
			URL currencyUrl = new URL(url);
		
			HttpURLConnection httpConn = (HttpURLConnection)currencyUrl.openConnection();
			httpConn.setRequestMethod("GET");
			responseCode = httpConn.getResponseCode();
			System.out.println("responseCode: " + responseCode);
		
			if(responseCode == HttpURLConnection.HTTP_OK){
				InputStreamReader inReader = new InputStreamReader(httpConn.getInputStream(), "euc-kr");
				BufferedReader reader = new BufferedReader(inReader);
				while((line = reader.readLine()) != null){
					//System.out.println(line);
					// 아래 문자열을 만나면 Html 문서를 파싱하기 시작
					if(line.contains("<td class='nation'>")) {
						String currencyName=line.split("<|>|;")[4];
						
						//System.out.print(currencyName+" ");
						String temp=reader.readLine().split("<|>")[2];
						//System.out.println(temp);
						Double exchangeRate=Double.parseDouble(temp);
						
						callback.updateCurrencyData(currencyName, exchangeRate);
					}
					// 아래 문자열을 만나면 Html 파싱을 종료함
					if(line.contains("<div class='date'>")) {
						String dateString=reader.readLine().split("<|>")[2];
						//System.out.println(dateString);
						//System.out.println("");
						callback.updateLatestDate(dateString);
						break;
					}
		
				}
		
				httpConn.disconnect();
				inReader.close();
				reader.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
		

}



	


 
