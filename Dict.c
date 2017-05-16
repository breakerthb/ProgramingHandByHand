//   File : Dict.c
// Author : 小C/小D/小E
#include "Dict.h"

#include <string.h>

#define SIZE 200

Word g_arrWords[200];
int g_index;

void DictInit()
{
	g_index = 0;
}

void DictInsert(char* pStr)
{
	WordSet(&g_arrWords[g_index], pStr, 1);
	g_index++;
}

Word* DictSearch(char* pStr)
{
	int i;
	for (i = 0; i < g_index; i++)
	{
		if (strcmp(g_arrWords[i].m_arr, pStr) == 0)
		{
			return &g_arrWords[i];
		}
	}

	return NULL;
}

void DictSort()
{
	int i, j;
	Word wordT;
	for (i = 0; i < g_index - 1; i++)
	{
		for (j = i + 1; j < g_index; j++)
		{
			if (strcmp(g_arrWords[i].m_arr, g_arrWords[j].m_arr) > 0)
			{
				WordCpy(&wordT, &g_arrWords[i]);
				WordCpy(&g_arrWords[i], &g_arrWords[j]);
				WordCpy(&g_arrWords[j], &wordT);
			}
		}
	}
}

void DictPrint()
{
	int i;
	for (i = 0; i < g_index; i++)
	{
		printf("%12s - %d\n", g_arrWords[i].m_arr, g_arrWords[i].m_cnt);
	}
}