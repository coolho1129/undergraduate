#include <stdio.h>
#include <math.h>

int main()
{
	unsigned char CHAR_MAX =pow(2,8)-1 ;
	unsigned char CHAR_MIN = 0;
	unsigned short SHORT_MAX = pow(2,16)-1;
	unsigned short SHORT_MIN = 0;
	unsigned int INT_MAX= pow(2,32)-1  ;
	unsigned int INT_MIN= 0;



	printf("UNSIGNED_CHAR_MAX : %d\n", CHAR_MAX);
	printf("UNSIGNED_CHAR_MIN : %d\n", CHAR_MIN);
	printf("UNSIGNED_SHORT_MAX : %d\n", SHORT_MAX);
	printf("UNSIGNED_SHORT_MIN : %d\n", SHORT_MIN);
	printf("UNSIGNED_INT_MAX : %u\n", INT_MAX);
	printf("UNSIGNED_INT_MIN : %d\n", INT_MIN);
}