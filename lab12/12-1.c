#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 1번

int main()
{
	char code1[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char code2[26] = "hknopijxyzqfgmvwulastbcrde";
	int i, j;

	char input[1000] = {0};
	gets(input);

	for (i = 0; i < strlen(input); i++)
	{
		if (input[i] == 32) // 공백 아스키코드==32
		{
			printf(" ");
		}
		else
		{
			for (j = 0; j < 26; j++)
			{
				if (input[i] == code1[j])
				{
					printf("%c", code2[j]);
				}
			}
		}
	}
	return 0;
}
