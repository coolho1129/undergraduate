#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int n;
	char o;
	int m;

	for (;;)
	{
		scanf("%d", &n);
		scanf("%c", &o);
		scanf("%d", &m);
		if (o == '/')
			if (m == 0)
			{
				printf("Error\n");
			}
			else
			{
				printf("%d/%d=%0.2lf\n", n, m, ((double)n / m));
			}
		else if (o == '+')
			printf("%d+%d=%d\n", n, m, (n + m));
		else if (o == '-')
			printf("%d-%d=%d\n", n, m, (n - m));
		else if (o == '*')
			printf("%d*%d=%d\n", n, m, (n * m));
		else if (o == '!')
			break;
	}

	return 0;
}
