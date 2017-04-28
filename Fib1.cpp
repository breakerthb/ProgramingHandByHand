#define PRINT_CNT 10
void main()
{
	int i;
	int arr[PRINT_CNT];
	for (i = 0; i < PRINT_CNT; i++)
	{
		if (i == 0 || i == 1)
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}

		printf("%d ", arr[i]);
	}
}