#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int a = x / 10000;
	int b = (x%10000)/5000;
	int c = (x% 5000)/1000;
	int d = (x % 1000)/500;
	int e = (x % 500)/100;
	int f = (x % 100)/50;
	int g = (x % 50)/10;
	int h = (x % 10)/5;
	int i = (x % 5);
	
	printf("10000:%d\n",a);
	printf("5000:%d\n", b);
	printf("1000:%d\n", c);
	printf("500:%d\n", d);
	printf("100:%d\n", e);
	printf("50:%d\n", f);
	printf("10:%d\n", g);
	printf("5:%d\n", h);
	printf("1:%d\n", i);
}