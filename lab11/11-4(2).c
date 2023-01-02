#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char input[1000][1000] = {0};
	char delimiter[1000] = ",";
	char *ptoken;
	double sum = 0.0;
	double avg = 0.0;
	int i, j;
	int cnt = 0;

	for (i = 0;; i++)
	{
		gets(input[i]);

		if (strcmp(input[i], "quit") == 0)
		{
			break;
		}
	}

	for (i = 0; i < strlen(input[i]); i++)
	{
		ptoken = strtok(input[i], delimiter);

		for (j = 1; ptoken != NULL; j++)
		{
			if (strcmp(ptoken, "quit") == 0)
			{
				break;
			}
			printf("%s", ptoken);

			if (j % 3 == 0)
			{

				sum += atoi(ptoken);
				cnt++;
				printf("\n");
			}
			else
			{
				printf("\t");
			}
			// printf("%s\n", ptoken);

			ptoken = strtok(NULL, delimiter);
		}

	} // printf("%d %d %d", cnt1, cnt2, cnt3);

	avg = sum / ((double)(cnt));

	printf("avg=%0.1lf", avg);

	return 0;
}
