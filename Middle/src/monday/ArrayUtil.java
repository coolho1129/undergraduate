//2021114818
//김찬호
package monday;

public class ArrayUtil {

	
	int c[]= new int[20],max;
	void fill (int [] a) {
		
		for(int i=0;i<a.length;i++)
			a[i]= (int)(Math.random()*100+1);
		
		
	}

	int[] concat(int[] a, int[] b) {
		
		for(int i=0;i<10;i++) {
			c[i]=a[i];
			c[i+10]=b[i];
		}		
		
		return c;
	}

	int compare(int[] a, int[] b) {
		int amax,bmax;
		
		amax=getMax(a);
		bmax=getMax(b);
		
		
		if(amax>bmax)
			return 1;
		else if(amax==bmax)
			return 0;
		else 
			return -1;
	
	
	}
	
	void print(int[] a) {
		
		for(int i=0;i<a.length; i++)
			System.out.printf("%2d ",i);
		
		System.out.println("");
		System.out.print("[");
		for(int i=0;i<a.length; i++) {
			System.out.printf("%2d",a[i]);
			if(i!=a.length-1)
				System.out.print(", ");
		
		}
		System.out.println("]");
		
	}
	
	int getMax(int a[]) {
		int max=a[0];
		
		for (int i=0;i<a.length;i++) {
			if(a[i]>max) {
				max=a[i];
			}
		}
		this.max=max;
		return this.max;
		
	}

}
