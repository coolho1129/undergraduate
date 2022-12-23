#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct customer
{
	char name[100];
	char hp_num[100];
	char p_num[100];
};

void main()
{
	int n, i;
	struct customer customer[100];
	struct customer name;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s %s %s", &customer[i].name, &customer[i].hp_num, &customer[i].p_num);
	}

	for (;;)
	{
		scanf("%s", &name.name);

		for (i = 0; i < n; i++)
		{
			if (strcmp(name.name, customer[i].name) == 0)
			{

				if (strcmp("NA", customer[i].hp_num) == 0)
					printf("%s\n", customer[i].p_num);

				else
					printf("%s\n", customer[i].hp_num);

				break;
			}
		}

		if (strcmp(name.name, "exit") == 0)
			break;

		if (i == n)
			printf("Search Fail\n");
	}
}