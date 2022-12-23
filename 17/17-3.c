#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct rationalnum
{
	int deno;
	char div;
	int numer;
};
void main()
{
	struct rationalnum ration1;
	scanf("%d%c%d\n", &ration1.numer, &ration1.div, &ration1.deno);

	struct rationalnum ration2;
	scanf("%d%c%d", &ration2.numer, &ration2.div, &ration2.deno);

	if (((double)ration1.numer / ration1.deno) == ((double)ration2.numer / ration2.deno))
	{
		printf("%d", 0);
	}
	else if (((double)ration1.numer / ration1.deno) > ((double)ration2.numer / ration2.deno))
	{
		printf("%d", -1);
	}
	else
		printf("%d", 1);
}