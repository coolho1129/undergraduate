#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int C, i;
	int E = 0;
	scanf("%d", &C);

	int F = round(((double)9 / 5) * C + 32);

	for (i = 1;; i++)
	{
		scanf("%d", &E);
		if (E > F)
		{
			printf("large\n");
		}
		else if (E < F)
		{
			printf("small\n");
		}
		else
		{
			printf("correct %d\n", i);
			break;
		}
	}
	return 0;
}
