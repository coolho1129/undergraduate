#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct triangle
{

	int side[3];
	char name[30];

} triangle;

int checktri(int side[])
{
	if (side[2] < side[0] + side[1])
	{
		if (side[0] == side[1] || side[1] == side[2])
		{
			if (side[0] == side[2])
				return 1;
			else
				return 2;
		}
		else
			return 3;
	}

	else
		return 0;
}

void main()
{
	FILE *fp;
	triangle tri;
	char file[30] = {0}, name[4][30] = {"Not Triangle", "Regular Triangle", "Isosceles Triangle", "General Triangle"};
	int i = 0, j = 0, tmp;

	scanf("%s", file);
	for (;;)
	{
		scanf("%d %d %d", &tri.side[0], &tri.side[1], &tri.side[2]);
		if (tri.side[0] > 0 && tri.side[1] > 0 && tri.side[2] > 0)
			break;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (tri.side[i] > tri.side[j])
			{
				tmp = tri.side[i];
				tri.side[i] = tri.side[j];
				tri.side[j] = tmp;
			}
		}
	}

	fp = fopen(file, "w");

	fprintf(fp, "%s", name[checktri(tri.side)]);

	fclose(fp);
}
