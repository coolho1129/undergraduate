#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
	int number;
	char gender;
	double height;
	double weight;
} student;

void main()
{
	int n, i;
	int mcnt = 0, wcnt = 0;
	double mhsum = 0, mwsum = 0, whsum = 0, wwsum = 0;

	scanf("%d", &n);

	student st;
	for (i = 0; i < n; i++)
	{
		scanf("%d %c %lf %lf", &st.number, &st.gender, &st.height, &st.weight);
		if (st.gender == 'M')
		{
			;
			mhsum += st.height;
			mwsum += st.weight;
			mcnt++;
		}
		else if (st.gender == 'W')
		{

			whsum += st.height;
			wwsum += st.weight;
			wcnt++;
		}
	}
	printf("M : %d %0.1lf %0.1lf\n", mcnt, (mhsum / mcnt), (mwsum / mcnt));
	printf("W : %d %0.1lf %0.1lf", wcnt, (whsum / wcnt), (wwsum / wcnt));
}