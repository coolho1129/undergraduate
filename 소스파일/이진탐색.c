#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int main()
{
	int key, low, high, middle, index = -1;
	int grade[16] = { 2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };

	printf("탐색할 값을 입력하시오:");
	scanf("%d", &key);

	/*binary search*/
	low = 0;
	high = 15;
	while (low <= high)
	{
		printf("[%d %d]\n", low, high);
		middle = (low + high) / 2;
		
		if (key == grade[middle])
		{
			index = middle;
			break;
		}
		else if (key > grade[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	printf("탐색 결과=%d\n", index);
}
