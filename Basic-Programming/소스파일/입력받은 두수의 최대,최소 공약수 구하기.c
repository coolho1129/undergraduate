main()
{
	int i,a,b = 0;
	int max = 0;
	int MAX = 0;
	int min = 0;
	
	scanf("%d %d", &a,&b);
	

		if (a >= b)
		{
			max = a;
		}
		else;
		{
			max = b;
		}
		
		for (i = 1; i <= max; i++)//�ִ�����
			if (a % i == 0&&b % i == 0)
			{
				MAX = i;
				
			}
		for (i = max; ; i++)//�ּҰ����
		{
			if (i % a == 0 && i % b == 0)

			{
				min = i;
				break;
			}
		}
	
		printf("%d\n%d",MAX,min);

	}