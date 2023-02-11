package hw6;
//학번: 2021114818
//이름: 김찬호

import java.io.*;
import java.util.*;

public class SimpleGrep {
	static Vector<String> vector= new Vector<String>();
	
	public static void optionC(File[] file,String searchWord) {
		
		for(int i=0;i<file.length;i++) {
			int cnt=0;
			try {
				
				FileReader fin = new FileReader(file[i].getAbsolutePath());
				BufferedReader breader = new BufferedReader(fin);
				String line,output;
				
				while((line = breader.readLine()) != null) {
					int index=0;
					int startIndex=0;
					for(;;) {
						index=line.indexOf(searchWord,startIndex);
							
							if(index!=-1) {
								startIndex= index + searchWord.length(); // 문자열의 길이만큼 건너뜀
								cnt++;
							}
							
							else {
								break;
							}
					}
					
					
				
				}
				
					output=String.format("%s:%d",file[i].getName(),cnt);
					System.out.println(output);
					vector.add(output);
					breader.close();
				
				
			}
			
			
			
			
			 catch (IOException e) {
				// TODO Auto-generated catch block	
				e.printStackTrace();
			}
			
		}
		saveFile();
		
		
	}
	
	public static void optionN(File[] file,String searchWord) {
		boolean isFound=false;
		
		for(int i=0;i<file.length;i++) {
			
			try {
				
				FileReader fin = new FileReader(file[i].getAbsolutePath());
				BufferedReader breader = new BufferedReader(fin);
				String line,output;
				int linenum=1;
				
				
				
				
				while((line = breader.readLine()) != null) {
					
					
					
						if(line.indexOf(searchWord)!=-1) {
							output=String.format("%s:%d: %s",file[i].getName(), linenum,line);
							System.out.println(output);
							vector.add(output);
							isFound=true;
							
						}
						linenum++;
					
								
				}
				breader.close();
				//fin.close();
				
				
				
					
		}
			
			
			catch (IOException e) {
				// TODO Auto-generated catch block	
				e.printStackTrace();
			}
			
		}
		
		if(isFound)
			saveFile();
			
		else
			System.out.printf("%s not found!",searchWord);
	
	}
	
	
	
	public static void optionI(File[] file,String searchWord) {
		boolean isFound=false;
		
		for(int i=0;i<file.length;i++) {
			
			try {
				
				FileReader fin = new FileReader(file[i].getAbsolutePath());
				BufferedReader breader = new BufferedReader(fin);
				String line,output;
				int linenum=1;
				
				while((line = breader.readLine()) != null) {
					String lowerWord = searchWord.toLowerCase();
					String lowerLine = line.toLowerCase();
					
					
						if(lowerLine.indexOf(lowerWord)!=-1) {
							output=String.format("%s:%d: %s",file[i].getName(), linenum,line);
							System.out.println(output);
							vector.add(output);
							isFound=true;
						}
						linenum++;
						
					
							
				}
				breader.close();
				//fin.close();
				
				
				
					
		}
			
			
			catch (IOException e) {
				// TODO Auto-generated catch block	
				e.printStackTrace();
			}
			
		}
		
		if(isFound)
			saveFile();
			
		else
			System.out.printf("%s not found!",searchWord);
	
	}
	
	public static void saveFile() {	

		try {
			
			FileWriter result =new FileWriter("Result.txt");
			BufferedWriter bwriter = new BufferedWriter(result);
			
			for(int i=0;i<vector.size();i++) {
				bwriter.write(String.format("%s\n",vector.get(i)));
				
			}
			System.out.println("Result.txt saved.");
			bwriter.close();
				//result.close();
		
		}catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
		
	}
	
	public static void DisplayInput(File file,String option,String searchWord) {
		String dir=file.getAbsolutePath();
		System.out.println("----------------------------------------------------");
		System.out.printf(" Working dir: %s\n",dir);
		System.out.printf( " Search Result: option: %s, keyword: %s\n",option,searchWord);
		System.out.println("----------------------------------------------------");
		
	}
	public static void main(String[] args) {
		
		if(args.length!=3) {
			System.out.println("Usage: SimpleGrep [option] [searchword] [dir]");
			System.exit(0);
		}
		
			String option =args[0];
			String searchWord= args[1];
			String dir = args[2];
			File fin = new File(dir);
			File[] file = fin.listFiles();
			Arrays.sort(file);
		
			switch(option) {
				case "-c":
					DisplayInput(fin,option,searchWord);
					optionC(file,searchWord);
					break;
				
				case "-n":
					DisplayInput(fin,option,searchWord);
					optionN(file,searchWord);
					break;
				
				case "-i":
					DisplayInput(fin,option,searchWord);
					optionI(file,searchWord);
					break;
			
				
		
			}
		
	}
}