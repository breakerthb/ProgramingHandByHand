//   File : Word.h
// Author : 小C
#ifndef __WORD_H__
#define __WORD_H__

#define CHAR_SIZE 50

typedef struct _tagWord
{
	char m_arr[CHAR_SIZE];
	int m_cnt;
}Word;

void WordSet(Word* pWord, char* pStr, int cnt);
void WordCpy(Word* pDest, Word* pSrc);

#endif