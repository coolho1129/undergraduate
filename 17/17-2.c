#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct emplyee
{
	int number;
	char name[100];
	char address[100];
	int money;
	double incentive;
};

void main()
{
	struct emplyee emplyee;
	int i;

	for (i = 0; i < 3; i++)
	{
		scanf("%d\n", &emplyee.number);
		gets(emplyee.name);
		gets(emplyee.address);
		scanf("%d", &emplyee.money);
		scanf("%lf", &emplyee.incentive);
		printf("%d\t%s\t%s\t%d\t%d%c\t%0.1lf\n", emplyee.number, emplyee.name, emplyee.address, emplyee.money, (int)((emplyee.incentive) * 100), '%', (emplyee.money) * (12 + emplyee.incentive));
	}
}