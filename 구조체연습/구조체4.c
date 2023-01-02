#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct information{

	char name[100];
	int age;
	int height;



}information;
void printInform(information input[])
{
	
	int i, j, tmp;
	for (i = 0; i < 4; i++)
	{
		printf("%s\t%d\t%d\n", input[i].name, input[i].age, input[i].height);
	
	}
	
	
	
	

}
main()
{
	struct information input[4];
	int i, j;
	struct information tmp;

	for (i = 0; i < 4; i++)
	{
		scanf("%s %d %d", &input[i].name, &input[i].age, &input[i].height);

	}
	printInform(input);
	printf("\n");

	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (strcmp(input[i].name, input[j].name) < 0)
			{
				tmp = input[i];
				input[i] = input[j];
				input[j] = tmp;
			}
		}

		printInform(input);
		printf("\n");
		
		
		for (i = 0; i < 4; i++)
		{
			for (j = i + 1; j < 4; j++)
			{
				if (input[i].age > input[j].age)
				{
					tmp = input[i];
					input[i] = input[j];
					input[j] = tmp;
				}
			}
		}

		printInform(input);
		printf("\n");

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (input[i].height > input[j].height)
				{
					tmp = input[i];
					input[i] = input[j];
					input[j] = tmp;
				}
			}
		}

		printInform(input);
		printf("\n");
	}

}