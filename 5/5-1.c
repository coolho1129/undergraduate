#include <stdio.h>
void main()
{
	int n ,i= 0;
	scanf("%d", &n);

	for (i = 0; i <= n; i++)
		if (i % 3 != 0)
		{
			if (i % 2 != 0)
				printf("%d ",i );
		}




}