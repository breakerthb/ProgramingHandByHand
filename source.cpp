int IsPrimeNum1(int num)
{
    int i;

    if (num == 1)
    {
        return 0;
    }

    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int IsPrimeNum2(int num)
{
    int i, k;

    if (num == 1)
    {
        return 0;
    }

    k = (int)sqrt((double)num);

    for (i = 2; i <= k; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int num, i;
    int isPrimeNum;
    for (num = 1; num <= 100; num++)
    {
        if (IsPrimeNum1(num) == 1)
        //if (IsPrimeNum2(num) == 1)
        {
            printf("%d\n", num);
        }
        else
        {
            printf("%d ", num);
        }
    }
    printf("\n");
}