#include <stdio.h>

int add (int, int);
int multiply (int, int);

int main (){

  	int (*fptr) (int, int);
  	//void (*vptr) (int);
  	int a;

  	//vptr = printData;
  	fptr = add;

  	a = fptr (4, 5);
	printf("fptr save add\n"); 
	printf ("a = %d \n", a);
	

 	fptr = multiply;
 	a = fptr (4, 5);
  	printf("fptr save multiply\n");
	printf ("a = %d \n", a);
}

int add (int a, int b){
  
	int result;
  	result = a + b;
  	return result;
}

int multiply (int a, int b){
  	
	int result;
  	result = a * b;
  	return result;
}
