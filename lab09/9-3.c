#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int kineticEnergy(int weight, int velocity)
{
	int KE = 0;
	KE = 0.5 * weight * velocity * velocity;

	return KE;
}

int main()
{

	int m, v;
	scanf("%d", &m);
	scanf("%d", &v);

	printf("%d\n", kineticEnergy(m, v));
	return 0;
}