#include <stdio.h>
#include <math.h>

int main()
{
	const double x = 11.3;
	printf("x의 값이 11.3일 때, 다항식의 값은 %lf 입니다.\n", 3 * pow(x, 3) - 7 * pow(x, 2) + 9);
}