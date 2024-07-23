*
**
*** 이런 별 출력하기




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main()
{
	int input;
	int i, j;
	
	scanf("%d", &input);

	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

}
