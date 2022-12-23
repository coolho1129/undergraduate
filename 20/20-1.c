#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct student
{
	int id;
	char name[30];
	double score[3];
	double total;

} student;

void main()
{
	FILE *fp1, *fp2;
	char ch, file[2][100];
	student stu[100] = {
		0,
	};
	int i = 0;
	scanf("%s %s", file[0], file[1]);
	// printf("%s\n", name);

	fp1 = fopen(file[0], "r");
	fp2 = fopen(file[1], "wb");
	if (fp1 == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while (fscanf(fp1, "%d %s %lf %lf %lf", &stu[i].id, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]) != EOF)
	{
		stu[i].total = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		printf("%d\t%s\t%0.1lf\t%0.1lf\t%0.1lf\t%0.1lf\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].total);
		i++;
	}
	fwrite(stu, sizeof(student), i, fp2);

	fclose(fp1);
	fclose(fp2);
}