#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int i;
	int grade = 0;
	int sum = 0;
	float mean = 0.0;

	for (i = 1;; i++)
	{
		scanf("%d", &grade);
		if (grade >= 0)
		{
			sum += grade;
		}

		else
		{
			break;
		}

		mean = ((float)sum / i);
	}
	printf("%0.2f", mean);

	return 0;
}
