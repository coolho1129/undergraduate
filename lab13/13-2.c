#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


#include <stdio.h>


static int sum = 0;

void resetAcuumulateSum() {
	
	sum = 0;
}

int accumulateSum(int num) {

	
	sum += num;
	return sum;

}

int main()
{
	int value;

	while (1) {

		scanf("%d", &value);

		if (value == 0)
			break;

		if (value < 0)
		{
			printf("Total sum : %d\n", accumulateSum(0));
			resetAcuumulateSum();
		}
		else
			accumulateSum(value);
	}
	return 0;
}