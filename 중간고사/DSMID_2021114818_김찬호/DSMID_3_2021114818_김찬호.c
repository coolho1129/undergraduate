#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void printResult(char result[]) {

	int len = strlen(result);


	for (int i = len-1;i >= 0;i--){
		if (result[len-1] == '0'&&i==len-1)
			continue;
		printf("%c", result[i]);
	}

}


void main() {
	FILE* f1,*f2;
	char num1[1001] = { 0 }, num2[1001] = { 0 }, result[102] = {0};

	f1 = fopen("a.txt", "r");
	f2 = fopen("b.txt", "r");
	
	fscanf(f1, "%s", num1);
	fscanf(f2, "%s", num2);


	int len1 = strlen(num1), mult = 0,cnt=0,carry=0;

	for (int i = 0;i < len1+1;i++) {
		if (i < len1) {
			mult = (num1[len1 - i - 1] - '0') * (num2[0] - '0') + carry;
			//printf("1");
		}
			if (i == len1) {
			mult = carry;
			//printf("2");
		}
		result[cnt++] = (mult % 10)+'0';
		carry = mult / 10;
	
	
	
	}
	
	printResult(result);

	fclose(f1);
	fclose(f2);
	

	

}










