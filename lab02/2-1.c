#include <stdio.h>
#include <math.h>

int main()
{
	char CHAR_MAX =pow(2,7)-1 ;
	char CHAR_MIN = -pow(2, 7);
	short SHORT_MAX = pow(2,15)-1;
	short SHORT_MIN = -pow(2, 15);
	int INT_MAX= pow(2,31)-1  ;
	int INT_MIN= -pow(2,31);



	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("SHORT_MAX : %d\n", SHORT_MAX);
	printf("SHORT_MIN : %d\n", SHORT_MIN);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("INT_MIN : %d\n", INT_MIN);
}