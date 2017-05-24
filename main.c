#pragma warning(disable:4996)
#include <stdio.h>

#define MAX 15

char g_arr[MAX];

// 判断闰年，是闰年返回1，是平年返回0
int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

// 返回输入年份的1月1日是周几
int GetFirstWeek(int year)
{
	return (35 + year + year / 4 - year / 100 + year / 400) % 7;
}

int g_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 返回输入的年份中输入的月份天数
int GetDays(int year, int month)
{
	if (month == 2 && IsLeapYear(year))
	{
		return g_days[month - 1] + 1;
	}
	else
	{
		return g_days[month - 1];
	}
}

// 得到字符串中的第一组数字
int GetNextNum(char** ppStr)
{
	int ret = 0;
	int num;
	char* pStr = *ppStr;
	while (1)
	{
		if (*pStr < '0' || *pStr > '9')
		{
			break;
		}

		num = *pStr - '0';
		ret = ret * 10 + num;

		pStr++;
	}
	pStr++;
	*ppStr = pStr;

	return ret;
}

int GetWeek(int year, int month, int day)
{
	int i;
	int week = GetFirstWeek(year);
	for (i = 1; i < month; i++)
	{
		week += GetDays(year, i);
	}

	week--;

	week += day;
	week = week % 7;

	return week;
}

int Process()
{
	int ret, answer;
	int year, month, day;
	int week;
	char* pStr = g_arr;

	scanf("%s", pStr);
	scanf("%d", &answer);

	year = GetNextNum(&pStr);
	month = GetNextNum(&pStr);
	day = GetNextNum(&pStr);

	week = GetWeek(year, month, day);

	if (week == answer)
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
	int i, cnt;

	freopen("input.txt", "r", stdin);
	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("#%d : ", i + 1);
		if (Process() == 1)
		{
			printf("Right\n");
		}
		else
		{
			printf("Wrong\n");
		}
	}

	return 1;
}
