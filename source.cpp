#include <stdio.h>

#define SIZE 3

int g_arr[SIZE][SIZE] = 
    {    3, 4, 9,
        6, 2, 7,
        5, 1, 8
    };
    
void PrintfMatrix(int arr[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void Sort(int* pArr, int num)
{
    int t;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (pArr[i] > pArr[j])
            {
                t = pArr[i];
                pArr[i] = pArr[j];
                pArr[j] = t;
            }

        }
    }
}

int CalculateSum(int arr[][SIZE])
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i][i];
        arr[i][i] = 0;

        sum += arr[i][SIZE - 1 - i];
    }

    return sum;
}

int main()
{
    int ret;

    printf("原始矩阵：\n");
    PrintfMatrix(g_arr);

    Sort((int*)g_arr, SIZE * SIZE);
    printf("排序后矩阵：\n");
    PrintfMatrix(g_arr);

    printf("对角线之和：\n");
    ret = CalculateSum(g_arr);
    printf("%d\n", ret);
}