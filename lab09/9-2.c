#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char scoreTOGrade(int score)
{
	char c;
	if (score >= 90)
		c = 'A';
	else if (score >= 80)
		c = 'B';
	else if (score >= 70)
		c = 'C';
	else if (score >= 60)
		c = 'D';
	else if (score < 60)
		c = 'F';
	return c;
}

int main()
{
	for (;;)
	{
		int score;
		scanf("%d", &score);

		if (score == -1)
		{
			break;
		}
		else
			printf("%c\n", scoreTOGrade(score));
	}
	return 0;
}