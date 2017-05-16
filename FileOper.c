//   File : FileOper.c
// Author : 小A 
#define _CRT_SECURE_NO_WARNINGS
#include "FileOper.h"

void FileInit()
{
	freopen("input.txt", "r", stdin);
}

int FileGetString(char* pBuf)
{
	pBuf[0] = 0;

	scanf("%s", pBuf);

	if (pBuf[0] == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void FileDispose()
{
	fclose(stdin);
}