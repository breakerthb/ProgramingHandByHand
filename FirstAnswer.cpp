#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 3

int g_arr[MAX_SIZE][MAX_SIZE] = { 0 };

int Calculate()
{
	int i, j;
	int sumLine, sumCol, sumDL1, sumDL2;
	sumDL1 = 0;
	sumDL2 = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		sumLine = 0;
		sumCol = 0;

		for (j = 0; j < MAX_SIZE; j++)
		{
			sumLine += g_arr[i][j];
			sumCol += g_arr[j][i];
		}

		if (sumLine != 15 || sumCol != 15)
		{
			return 0;
		}

		sumDL1 += g_arr[i][i];
		sumDL2 += g_arr[i][MAX_SIZE - 1 - i];
	}

	if (sumDL1 != 15 || sumDL2 != 15)
	{
		return 0;
	}

	return 1;
}

void PrintMap()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			printf("%3d ", g_arr[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}

int g_cnt = 0;
int g_return = 0;
void FillBlank(int num)
{
	int i;
	int nBak;
	int* pArr = (int*)g_arr;

	if (g_return == 1)
	{
		return;
	}

	if (num <= 0)
	{
		if (Calculate() == 1)
		{
			PrintMap();
			g_return = 1;
		}

		printf("%d\r", g_cnt++);

		return;
	}

	for (i = 0; i < MAX_SIZE * MAX_SIZE; i++)
	{
		if (num >= pArr[i])
		{
			nBak = pArr[i];
			pArr[i] = num;
			FillBlank(num - 1);
			pArr[i] = nBak;
		}
	}
}

int main()
{

	FillBlank(9);

	return 0;
}

