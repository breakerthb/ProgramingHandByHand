#include <stdio.h>

#include "FileOper.h"
#include "Filter.h"
#include "Dict.h"

#define MAX_SIZE 50

int main()
{
	char str[MAX_SIZE];
	Word* pWord;

	FileInit();
	DictInit();
	while (FileGetString(str) == 1)
	{
		Filter(str);

		if ((pWord = DictSearch(str)) == NULL)
		{
			DictInsert(str);
		}
		else
		{
			pWord->m_cnt++;
		}

		//printf("%s\n", str);
	}

	DictSort();
	DictPrint();

	FileDispose();
}