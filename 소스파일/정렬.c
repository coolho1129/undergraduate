//오름차순 정렬
for (i = 0; i < n; i++)
{
	for (j = i + 1; j < n; j++)
	{
		if (a[i] > a[j])
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

//내림차순 정렬
for (i = 0; i < n; i++)
{
	for (j = i + 1; j < n; j++)
	{
		if (a[i] < a[j])
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

//문자열 오름차순 정렬
for(i = 0; i < n; i++)
{
	for (j = i + 1; j < n; j++)
	{
		if (strcmp(a[i], a[j]) > 0)
		{
			strcpy(tmp, a[i]);
			strcpy(a[i], a[j]);
			strcpy(a[j], tmp);
		}
	}
}

//문자열 내림차순 정렬
for (i = 0; i < n; i++)
{
	for (j = i + 1; j < n; j++)
	{
		if (strcmp(a[i], a[j]) < 0)
		{
			strcpy(tmp, a[i]);
			strcpy(a[i], a[j]);
			strcpy(a[j], tmp);
		}
	}
}