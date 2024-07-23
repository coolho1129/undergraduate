//합집합
	for (i = 0; i < asize; i++)
	{
		c[cnt] = a[i];
		cnt++;
	}

	for (i = 0; i < bsize; i++)
	{
		for (j = 0; j < aszie; j++)
		{
			if (b[i] == a[j])
				break;

			if (j == asize-1)
			{
				c[cnt] = b[i];
				cnt++;
			}
		}
	}

//교집합
for (i = 0; i < asize; i++)
{	for(j=0;j<bsize;j++)
	if (a[i] == b[j])
	{
		c[cnt] =a[i]
			cnt++;
	}
	
}

//차집합
for (i = 0; i < asize; i++)
{
	same = 0;
	for (j = 0; j < bsize; j++)
	{
		if (b[i] == a[j])
		{
			same = 1;
			break;
		}
	}
	if (!same)
	{

		c[cnt++] = a[i];
		//Ccnt++;
	}
}
