#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
 1학기 족보에서 A B C D E 학점 출력에서 1 2 3 4 5 등수 출력으로 바꿔서 출제됨(문자 -> 정수)
*/

typedef struct student
{
	char name[100];
	int score[2];
	int sum;
	int grade;
} student;

void sort(student arry[]);

void main()
{
	struct student stu[6] = {-1};

	FILE *fp;
	char ch, file[100];
	int i = 0, cnt = 0, k = 0;
	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	for (i = 0; fscanf(fp, "%s %d %d", stu[i].name, &stu[i].score[0], &stu[i].score[1]) != EOF; i++)
	{
		stu[i].sum = stu[i].score[0] + stu[i].score[1];
	}
	sort(stu);

	for (i = 0; i < 5; i++)
	{
		if (i == 0)
			stu[i].grade = 1;

		else if (stu[i].sum == stu[i - 1].sum)
		{
			stu[i].grade = stu[i - 1].grade;
		}
		else
		{
			stu[i].grade = 1 + i;
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s %d %d %d %d\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].sum, stu[i].grade);
	}

	fclose(fp);
}

void sort(student arry[])
{
	student tmp;
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (arry[i].sum < arry[j].sum)
			{
				tmp = arry[i];
				arry[i] = arry[j];
				arry[j] = tmp;
			}
		}
	}
}