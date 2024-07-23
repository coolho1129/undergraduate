// 문제1 변수의 범위
// 학번 2021114818
// 이름 김찬호
package hw1;

public class VarRange {

	
	public static void main(String[] args) {
		
		short a =Short.MAX_VALUE;
		int b =Integer.MAX_VALUE;
		long c =Long.MAX_VALUE;
		long hour,day,year;
		
		System.out.println("short max:"+Short.MAX_VALUE);
		year=(((a/3600)/24)/365);
		day=(((a/3600)/24)%365);
		hour=(a/3600)%24;
		
		System.out.println("short 변수 사용: "+year+"년 "+day+"일 "+hour+"시간");
		
		System.out.println("int max:"+Integer.MAX_VALUE);
		
		year=(((b/3600)/24)/365);
		day=(((b/3600)/24)%365);
		hour=(b/3600)%24;
		System.out.println("int 변수 사용: "+year+"년 "+day+"일 "+hour+"시간");
		
		System.out.println("long:"+Long.MAX_VALUE);
		year=(((c/3600)/24)/365);
		day=(((c/3600)/24)%365);
		hour=(c/3600)%24;
		
		
		System.out.println("long 변수 사용: "+year+"년 "+day+"일 "+hour+"시간");


	}

}
