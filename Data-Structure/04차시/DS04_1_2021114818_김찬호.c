#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void reverse(char a[], int len)
{
	for (int i = len; i > 0; i--)
	{
		if ('1' <= a[i] && a[i] <= '9')
			break;
		else
			a[i] = 'a';
	}
	for (int i = len; i >= 0; i--)
	{
		if (a[i] != 'a')
			printf("%c", a[i]);
	}
}

int main()
{
	FILE *f1, *f2;
	f1 = fopen("a.txt", "r");
	f2 = fopen("b.txt", "r");
	char num1[10001] = {0};
	char num2[10001] = {0};
	char addition[10001] = {0};
	char subtraction[10001] = {0};
	int len1 = 0, len2 = 0, carry = 0, sum = 0, sub = 0;
	;

	while (fscanf(f1, "%s", num1) != EOF)
		len1 = strlen(num1);

	while (fscanf(f2, "%s", num2) != EOF)
		len2 = strlen(num2);

	for (int i = 0; i <= len1; i++)
	{

		if (len2 - i - 1 >= 0)
			sum = (num1[len1 - i - 1] - '0') + (num2[len2 - i - 1] - '0') + carry;

		else if (len1 - i - 1 >= 0)
			sum = (num1[len1 - i - 1] - '0') + carry;

		else if (((len1 - 1 - i) < 0))
			sum = carry;

		if (sum > 9)
		{
			carry = 1;
		}

		else
			carry = 0;

		addition[i] = (sum % 10) + '0';
	}

	carry = 0;

	for (int i = 0; i <= len1; i++)
	{

		if (len2 - i - 1 >= 0)
			sub = (num1[len1 - i - 1] - '0') - (num2[len2 - i - 1] - '0');

		else if (len1 - i - 1 >= 0)
			sub = (num1[len1 - i - 1] - '0') - carry;

		if (sub < 0)
		{
			carry = 1;
			sub += (carry * 10);
		}

		else
			carry = 0;

		subtraction[i] = sub + '0';
	}

	int addlen = strlen(addition);
	int sublen = strlen(subtraction);
	// printf("%d %d %d %d\n", len1, len2,addlen,sublen);
	printf("Addition: ");
	reverse(addition, addlen);
	printf("\nSubtraction: ");
	reverse(subtraction, sublen);

	fclose(f1);
	fclose(f2);
}