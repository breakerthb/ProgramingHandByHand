#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  

#define MAX_SIZE 8

void Copy(int* pDest, int* pSrc, int cnt)
{
	while (cnt--)
	{
		*pDest++ = *pSrc++;
	}
}

int CountPath(int maze[][MAX_SIZE], int i, int j)
{
	int cnt = 0;
	// Up Point
	if (maze[i - 1][j] == 0 || maze[i - 1][j] == 2)
	{
		cnt++;
	}

	// Down Point
	if (maze[i + 1][j] == 0 || maze[i + 1][j] == 2)
	{
		cnt++;
	}

	// Left Point
	if (maze[i][j - 1] == 0 || maze[i][j - 1] == 2)
	{
		cnt++;
	}

	// Right Point
	if (maze[i][j + 1] == 0 || maze[i][j + 1] == 2)
	{
		cnt++;
	}

	return cnt;
}

void FindNext(int maze[][MAX_SIZE], int i, int j)
{
	int cnt;
	int line, colum;
	// Up Point
	line = i - 1;
	colum = j;

	if (maze[line][colum] == 0)
	{
		if (CountPath(maze, line, colum) == 1)
		{
			maze[line][colum] = 1;
			FindNext(maze, line, colum);
		}
	}

	// Down Point
	line = i + 1;
	colum = j;

	if (maze[line][colum] == 0)
	{
		if (CountPath(maze, line, colum) == 1)
		{
			maze[line][colum] = 1;
			FindNext(maze, line, colum);
		}
	}

	// Left Point
	line = i;
	colum = j - 1;

	if (maze[line][colum] == 0)
	{
		if (CountPath(maze, line, colum) == 1)
		{
			maze[line][colum] = 1;
			FindNext(maze, line, colum);
		}
	}

	// Right Point
	line = i;
	colum = j + 1;

	if (maze[line][colum] == 0)
	{
		if (CountPath(maze, line, colum) == 1)
		{
			maze[line][colum] = 1;
			FindNext(maze, line, colum);
		}
	}
}

void CutBranch(int arrMaze[][MAX_SIZE])
{
	int i, j;

	arrMaze[1][1] = 2; // entry
	arrMaze[MAX_SIZE - 2][MAX_SIZE - 2] = 2; // exit
	for (i = 1; i < MAX_SIZE - 1; i++)
	{
		for (j = 1; j < MAX_SIZE - 1; j++)
		{
			if (arrMaze[i][j] != 0)
			{
				continue;
			}
			
			if (CountPath(arrMaze, i, j) <= 1)
			{
				arrMaze[i][j] = 1;
				FindNext(arrMaze, i, j);
			}
		}
	}
}

void PrintMaze(int arrMaze[][MAX_SIZE])
{ 
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			printf("%3d", arrMaze[i][j]);
		}
		
		printf("\n");
	}
}

void MarkMaze(int srcMaze[][MAX_SIZE], int MarkMaze[][MAX_SIZE])
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			if (MarkMaze[i][j] == 0)
			{
				srcMaze[i][j] = 9;
			}
		}
	}
}

void main()
{
	int i, j, k;
	//int maze[MAX_SIZE][MAX_SIZE] =
	//{
	//	{ 0, 1, 0, 1, 1, 1 },
	//	{ 0, 0, 0, 1, 0, 1 },
	//	{ 0, 1, 1, 0, 0, 0 },
	//	{ 0, 1, 1, 0, 1, 0 },
	//	{ 0, 0, 0, 0, 1, 0 },
	//	{ 0, 1, 1, 1, 1, 0 }
	//};
	int maze[MAX_SIZE][MAX_SIZE] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	int mazeCpy[MAX_SIZE][MAX_SIZE];

	// 打印原始迷宫
	printf("原始迷宫：\n");
	PrintMaze(maze);

	// 迷宫剪支
	Copy((int*)mazeCpy, (int*)maze, MAX_SIZE * MAX_SIZE );

	CutBranch(mazeCpy);

	// 打印剪支后的迷宫
	printf("\n剪支后的迷宫：\n");
	PrintMaze(mazeCpy);
	
	// 打印带正确路线的迷宫
	MarkMaze(maze, mazeCpy);

	printf("\n标记迷宫路线：\n");
	PrintMaze(maze);
}
