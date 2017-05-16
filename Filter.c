//   File : Filter.c
// Author : 小B 
#include "Filter.h"

void ToLower(char* pBuf)
{
	int i;
	for (i = 0; pBuf[i] != 0; i++)
	{
		if (pBuf[i] >= 'A' && pBuf[i] <= 'Z')
		{
			pBuf[i] += 32;
		}
	}
}

void Remove(char* pBuf, int index)
{
	int i;
	for (i = index; pBuf[i] != 0; i++)
	{
		pBuf[i] = pBuf[i + 1];
	}
}

void FiltSymbols(char* pBuf)
{
	int i;
	for (i = 0; pBuf[i] != 0; i++)
	{
		switch (pBuf[i])
		{
		case '(':
			// go to next
		case ')':
			// go to next
		case ',':
			// go to next
		case '.':
			Remove(pBuf, i);
			i--;
			break;
		default:
			// Do nothing
			break;
		}
	}
}

void Filter(char* pBuf)
{
	ToLower(pBuf);
	FiltSymbols(pBuf);
}