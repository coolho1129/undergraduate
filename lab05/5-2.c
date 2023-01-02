#include <stdio.h>
int main()
{
	int n, i, m = 0;
	scanf("%d", &n);
	int sum = 0;
	i = 0;
	int max = 0;
	while (i < n)
	{
		scanf("%d", &m);
		if (m > max)
		{
			max = m;
		}
		sum = sum + m;
		i++;
	}
	printf("%d\n", sum);
	printf("%d\n", max);
	return 0;
}
