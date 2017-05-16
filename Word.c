//   File : Word.c
// Author : 小C
#define _CRT_SECURE_NO_WARNINGS
#include "Word.h"
#include <string.h>

void WordSet(Word* pWord, char* pStr, int cnt)
{
	strcpy(pWord->m_arr, pStr);
	pWord->m_cnt = cnt;
}

void WordCpy(Word* pDest, Word* pSrc)
{
	strcpy(pDest->m_arr, pSrc->m_arr);
	pDest->m_cnt = pSrc->m_cnt;
}