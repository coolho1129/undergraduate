#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Moviedata
{
	char title[100];
	char Director[100];
	int year;
	int runtime;
};

int main()
{
	struct Moviedata movie;
	gets(movie.title);
	gets(movie.Director);
	scanf("%d %d", &movie.year, &movie.runtime);

	printf("Title : %s\nDirector : %s\nYear : %d\nRunningTime : %d", movie.title, movie.Director, movie.year, movie.runtime);

	return 0;
}
