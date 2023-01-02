#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Complex
{
	int real;
	int img;
}Complex;


void MultComplex(Complex input1,Complex input2,Complex *target)
{
	
	target->real=(input1.real) * (input2.real)+(input1.img)* (input2.img)* (-1);//실수부분
	target->img = (input1.real) * (input2.img) + (input1.img) * (input2.real);//허수 부분
	
}


main()
{
	struct Complex input1;
	struct Complex input2;
	struct Complex target;
	char a;//i저장
	scanf("%d %d %c", &input1.real, &input1.img,&a);
	scanf("%d %d %c", &input2.real, &input2.img, &a);
	
	MultComplex(input1, input2, &target);
	
	if(target.img>=0)
		printf("%d%c%d%c",target.real,'+',target.img,a);
	else
		printf("%d%d%c", target.real, target.img, a);

}