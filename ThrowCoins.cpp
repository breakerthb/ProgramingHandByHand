#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_THROW_TIME 5

int g_arr[MAX_THROW_TIME];

void Throw(int face, int cnt)
{
	int i;

	g_arr[cnt] = face;
	cnt++;

	if (cnt >= MAX_THROW_TIME)
	{
		for (i = 0; i < MAX_THROW_TIME; i++)
		{
			printf("%d ", g_arr[i]);
		}
		printf("\n");
	}
	else
	{
		Throw(0, cnt);
		Throw(1, cnt);
	}
}

void main()
{
	Throw(0, 0);
	Throw(1, 0);
}

