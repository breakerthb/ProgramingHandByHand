#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PRINT_CNT 10

int Fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

void main()
{
	int i;
	for (i = 1; i <= PRINT_CNT; i++)
	{
		printf("%d ", Fib(i));
	}
}

