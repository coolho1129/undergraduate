#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct club
{

	char name[100];
	char country[100];

} club;

struct player
{
	char name[100];
	int age;
	club clubname;
};

void main()
{
	int n, i;
	struct player player[100];
	struct club club;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s %d %s %s", &player[i].name, &player[i].age, &player[i].clubname.name, &player[i].clubname.country);
	}

	for (;;)
	{
		scanf("%s", &club.name);
		for (i = 0; i < n; i++)
		{
			if (strcmp(club.name, player[i].clubname.name) == 0)
			{

				printf("%s %d\n", player[i].name, player[i].age);
			}
		}

		if (strcmp(club.name, "exit") == 0)
			break;
	}
}