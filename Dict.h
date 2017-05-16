//   File : Dict.h
// Author : 小C
#ifndef __DICT_H__
#define __DICT_H__

#include "Word.h"

void DictInit();
void DictInsert(char* pStr);
Word* DictSearch(char* pStr);
void DictSort();
void DictPrint();

#endif