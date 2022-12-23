#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct student
{
	char name[20];
	double midterm;
	double final;
	double quiz;
} student;
struct score
{
	char name[20];
	double midterm;
	double final;
	double quiz;
	double total;
};

void main()
{
	FILE *fp1, *fp2;
	struct student *stu;
	struct score sco;
	char file[2][100];
	int n, i = 0;

	scanf("%s %s", file[0], file[1]);

	fp1 = fopen(file[0], "rb");
	fp2 = fopen(file[1], "w");

	fread(&n, sizeof(int), 1, fp1);
	stu = (student *)malloc(sizeof(student) * n);

	fread(stu, sizeof(student), n, fp1);

	for (i = 0; i < n; i++)
	{
		sco.total = stu[i].midterm + stu[i].final + stu[i].quiz;
		fprintf(fp2, "%d %s %0.1lf %0.1lf %0.1lf %0.1lf\n", i + 1, stu[i].name, stu[i].midterm, stu[i].final, stu[i].quiz, sco.total);
	}

	fclose(fp1);
	fclose(fp2);
}
