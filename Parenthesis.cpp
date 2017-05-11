#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

char g_arr[MAX_SIZE];
int g_index;

int CheckChar(char ch)
{
	if (ch == '(')
	{
		g_arr[g_index++] = ch;
	}
	else if (ch == '[')
	{
		g_arr[g_index++] = ch;
	}
	else if (ch == ')')
	{
		if (g_arr[g_index - 1] == '(')
		{
			g_index--;
		}
		else
		{
			return 0;
		}
	}
	else if (ch == ']')
	{
		if (g_arr[g_index - 1] == '[')
		{
			g_index--;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		// Do nothing
	}

	return 1;
}

int Check(char* pStr)
{
	g_index = 0;

	int i;
	for (i = 0; pStr[i] != '\0'; i++)
	{
		if (CheckChar(pStr[i]) == 0)
		{
			return 0;
		}
	}

	if (g_index == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n, i;
	int ret;
	char str[50];
	FILE* fp;
	freopen_s(&fp, "input.txt", "r+", stdin);
	if (fp == NULL)
	{
		ret = 0;
	}

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		ret = Check(str);
		printf("%d\n", ret);
	}
}