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


Complex MultComplex(Complex input1, Complex input2)
{
	int tmp1 = 0;
	int tmp2 = 0;

	tmp1 = (input1.real) * (input2.real) + (input1.img) * (input2.img) * (-1);//실수부분
	tmp2 = (input1.real) * (input2.img) + (input1.img) * (input2.real);//허수 부분

	input1.real = tmp1;
	input1.img = tmp2;

	return input1;

}


main()
{
	struct Complex input1;
	struct Complex input2;
	char a;//i저장
	int i = 0;

	for (i = 0;; i++)
	{
		if (i == 0)
		{
			scanf("%d %d %c", &input1.real, &input1.img, &a);
		}
		scanf("%d %d %c", &input2.real, &input2.img, &a);

		if ((input2.real == 0) && (input2.img == 0))
			break;


		input1 = MultComplex(input1, input2);



	}



	if (input1.img >= 0)
		printf("%d%c%d%c", input1.real, '+', input1.img, a);
	else
		printf("%d%d%c", input1.real, input1.img, a);
}