#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int i, j, n = 0;
	int array[100] = {0};
	int count = 0;
	int isNonValuable = 0;

	for (;;)
	{
		scanf("%d", &n);
		if (n > 0)
		{
			for (i = 0; array[i]; i++)
			{
				isNonValuable = 0;
				if (array[i] == n)
				{
					isNonValuable = 1;
					break;
				}
			}
			if (!isNonValuable)
			{
				array[count] = n;
				count++;
			}
		}
		else if (n < 0)
		{
			for (i = 0; array[i]; i++)
			{
				if (array[i] == -1 * n)
				{
					for (j = i; j < count; j++)
					{
						array[j] = array[j + 1];
					}
					count--;
					break;
				}
			}
		}
		else
		{
			break;
		}

		printf("array[%d] = {", count);

		for (i = 0; i < count; i++)
		{
			printf(" %d", array[i]);
		}
		printf(" }\n");
	}

	return 0;
}