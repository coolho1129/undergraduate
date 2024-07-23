#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 6번
int main()
{
	int i, j;
	char input[100][100] = {0};
	int count = 0;
	char tmp[100] = {0};
	char output[100][100] = {0};
	for (i = 0;; i++)
	{
		scanf("%s", input[i]);
		count++;
		if (strcmp(input[i], "quit") == 0)
		{
			break;
		}
	}
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count - 1; j++)
		{
			if (strcmp(input[i], input[j]) > 0)
			{
				strcpy(tmp, input[i]);
				strcpy(input[i], input[j]);
				strcpy(input[j], tmp);
			}
		}
	}
	for (i = 0; i < count - 1; i++)
	{
		printf("%s\n", input[i]);
	}

	return 0;
}