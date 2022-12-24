package monday;
//2021114818
//김찬호
public class ArrayUtilApp {

	public static void main(String[] args) {
		int a []=new int [10];
		int b[]=new int [10];
		ArrayUtil arrayutil = new ArrayUtil(); 
	
		System.out.println("fill(a) 수행");
		arrayutil.fill(a);
		System.out.println("< 배열 a 인덱스 및 내용 출력 >");
		arrayutil.print(a);
		System.out.println("");
	
		System.out.println("fill(b) 수행");
		arrayutil.fill(b);
		System.out.println("< 배열 b 인덱스 및 내용 출력 >");
		arrayutil.print(b);
		System.out.println("");
		
		System.out.println("concat(a, b) 수행 및 배열 c 생성");
		System.out.println("< 배열 c 인덱스 및 내용 출력 >");
		arrayutil.print(arrayutil.concat(a, b));
		System.out.println("");
	
		System.out.println("compare(a, b) 수행");
		System.out.printf("a의 최댓값:%2d , b의 최댓값:%2d\n",arrayutil.getMax(a),arrayutil.getMax(b));
		if(arrayutil.compare(a,b)==1)
			System.out.println("a > b");
		else if(arrayutil.compare(a,b)==0)
			System.out.println("a = b");
			
		else
			System.out.println("a < b");
	
	
	}

}
