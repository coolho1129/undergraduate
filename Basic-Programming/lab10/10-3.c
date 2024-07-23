#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char str1[1000];
	char str2[1000];

	for (;;)
	{
		gets(str1);

		if ((5 <= strlen(str1) && strlen(str1) <= 10))
		{
			gets(str2);

			if ((5 <= strlen(str2) && strlen(str2) <= 10))
			{
				{

					if (strcmp(str1, str2) == 0)
					{
						printf("Done\n");
						break;
					}
					else
						printf("Retry\n");
				}
			}
			else
				printf("Retry\n");
		}
		else
			printf("Retry\n");
	}
	return 0;
}