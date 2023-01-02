#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a == 0)
		printf("%lf\n", (double) -c / (double) b);

	else
	{
		if (sqrt(pow(b, 2) - 4 * a * c) > 0)

			printf("%lf, %lf\n", ((-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a)), (-b - sqrt(pow(b, 2 )- 4 * a * c)) / (2 * a));



		else if ((sqrt(pow(b, 2) - 4 * a * c) == 0))
				printf("%lf\n", (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
		else
					printf("허근입니다");
	}


	
}