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
	char ch, file[2][100], name[100];
	student stu[100] = {
		0,
	};
	double s[3];
	int i = 0, j;

	scanf("%s %s", file[0], file[1]);
	scanf("%s", name);
	scanf("%lf", &s[0]);
	scanf("%lf", &s[1]);
	scanf("%lf", &s[2]);

	fp1 = fopen(file[0], "rb");
	fp2 = fopen(file[1], "wb");
	if (fp1 == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	while (fread(&stu[i], sizeof(student), 1, fp1) != 0)
		i++;

	for (j = 0; j < i; j++)
	{
		if (strcmp(name, stu[j].name) == 0)
		{
			printf("%d\t%s\t%0.1lf\t%0.1lf\t%0.1lf\t%0.1lf\n", stu[j].id, stu[j].name, stu[j].score[0], stu[j].score[1], stu[j].score[2], stu[j].total);
			stu[j].score[0] = s[0], stu[j].score[1] = s[1], stu[j].score[2] = s[2], stu[j].total = s[0] + s[1] + s[2];
		}

		fseek(fp2, sizeof(student) * j, SEEK_SET);
		fwrite(&stu[j], sizeof(student), 1, fp2);
		rewind(fp2);
	}

	for (int j = 0; j < i; j++)
		printf("%d\t%s\t%0.1lf\t%0.1lf\t%0.1lf\t%0.1lf\n", stu[j].id, stu[j].name, stu[j].score[0], stu[j].score[1], stu[j].score[2], stu[j].total);

	fclose(fp1);
	fclose(fp2);
}