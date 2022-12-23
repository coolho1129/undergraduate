#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//3번

int main()
{
	int a[100] = { 0 };
	int i, j, total = 0, count = 0;
	double avg = 0;
	int tmp = 0;
	for (i = 0;; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			break;
		else
		{
			total += a[i];
			count++;
		}
	}

	avg = (double)total / count;

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	int max2 = a[1];
	for (i =1;i<count;i++ )
	{
		if (a[0] != a[i])
		{
			max2 = a[i];
			printf("sum = %d, Avg=%0.2lf, second Max = %d", total, avg, max2);
			break;
		}
		else  if (a[0] == a[count - 1])
		{
			printf("sum = %d, Avg=%0.2lf, second Max = %s", total, avg, "None");
			break;
		}
	}
	
	
		

}