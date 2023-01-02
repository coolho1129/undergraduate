#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct student
{
	char name[100];
	int grade[3];
	double avg;
};

void main()
{
	struct student stu;

	FILE *fp;
	char ch, file[100];

	scanf("%s", file);
	// printf("%s\n", name);

	fp = fopen(file, "r");

	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while (fscanf(fp, "%s %d %d %d", stu.name, &stu.grade[0], &stu.grade[1], &stu.grade[2]) != EOF)
	{
		printf("%s\t%d\t%d\t%d\t%0.2lf\n", stu.name, stu.grade[0], stu.grade[1], stu.grade[2], (double)(stu.grade[0] + stu.grade[1] + stu.grade[2]) / 3);
	}

	fclose(fp);
}