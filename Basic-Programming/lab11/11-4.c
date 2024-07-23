#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char input[1000];
	char name[100][1000] = {0};
	char subject[100][1000] = {0};
	char grade[100][1000] = {0};
	char delimiter[1000] = ",";
	char *ptoken;
	double sum = 0.0;
	double avg = 0.0;
	int i;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;

	for (;;)
	{
		gets(input);

		if (strcmp(input, "quit") == 0)
		{
			break;
		}

		ptoken = strtok(input, delimiter);

		for (i = 1; ptoken != NULL; i++)
		{
			if (i % 3 == 1)
			{

				strcpy(name[cnt1], ptoken);
				cnt1++;
			}

			else if (i % 3 == 2)
			{

				strcpy(subject[cnt2], ptoken);
				cnt2++;
			}

			else if (i % 3 == 0)
			{

				strcpy(grade[cnt3], ptoken);
				cnt3++;
			}

			// printf("%s\n", ptoken);

			ptoken = strtok(NULL, delimiter);
		}

	} // printf("%d %d %d", cnt1, cnt2, cnt3);

	for (i = 0; i < cnt3; i++)
	{
		sum += atoi(grade[i]);
		printf("%s\t%s\t%s\n", name[i], subject[i], grade[i]);
	}
	avg = sum / ((double)(cnt3));

	printf("avg=%0.1lf", avg);

	return 0;
}
