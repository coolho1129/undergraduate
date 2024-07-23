#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
	double x;
	double y;

} point;

typedef struct
{
	double slope;
	double yintcreccpt;

} line;

line slope_yintcreccpt(double x1, double y1, double x2, double y2)
{
	line a;

	a.slope = (y2 - y1) / (x2 - x1);
	a.yintcreccpt = y1 - a.slope * x1;

	return a;
}

void main()
{
	point a, b;
	line c;
	scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);

	c = slope_yintcreccpt(a.x, a.y, b.x, b.y);
	printf("%0.1lf %0.1lf", c.slope, c.yintcreccpt);
}