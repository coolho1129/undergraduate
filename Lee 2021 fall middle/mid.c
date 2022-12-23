// 1번
int main()
{
	int i;
	double a;
	double sum = 0;
	int cnt = 0;

	for (;;)
	{
		scanf("%lf", &a);

		if (a < 0)
			continue;
		else
		{
			sum += a;
			cnt++;
		}
		if (cnt == 3)
			break;
	}

	printf("avg = %0.2lf", sum / 3);

	return 0;
}