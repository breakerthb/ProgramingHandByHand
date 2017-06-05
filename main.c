#pragma warning(disable:4996)

#include <time.h>
#include <stdio.h>

#include <windows.h>

void Timer(int nSec)
{
	printf("Start Timer:\n");
	while (nSec > 0)
	{
		Sleep(1000);
		nSec--;
		printf("%3d s\r", nSec);
	}

	printf("\nTime is Up!\n");
}

void PrintTime(int nSec)
{
	int min, sec;
	min = nSec / 60;
	sec = nSec % 60;

	printf("%02d:%02d\r", min, sec);
}

void MinuteTimer(int nMin)
{
	int nSec = nMin;// *60;
	printf("Start Timer:\n");
	while (nSec > 0)
	{
		Sleep(1000);
		nSec--;
		PrintTime(nSec);
	}

	printf("\nTime is Up!\n");
}

void Alarm(int tag)
{
	switch (tag)
	{
	case 0:
		printf("----- ----- ----- ----- ----- ----- ----- ----- ----- -----");
		break;
	case 1:
		printf("///// ///// ///// ///// ///// ///// ///// ///// ///// /////");
		break;
	case 2:
		printf("||||| ||||| ||||| ||||| ||||| ||||| ||||| ||||| ||||| |||||");
		break;
	case 3:
		printf("\\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\ \\\\\\\\\\");
		break;
	default:
		break;
	}

	printf("\r");
}

#define LOG_FILE "alarm.log"
int main()
{
	int min;
	char cmd[100];

	while (1)
	{
		printf("Please input minutes : ");
		scanf("%d", &min);

		sprintf(cmd, "echo %%date%% %%time%% >> %s", LOG_FILE);
		system(cmd);

		MinuteTimer(min);

		printf("Press Esc to stop \n");
		int cnt = 1;
		while (cnt++)
		{
			Alarm(cnt % 4);

			if (kbhit())
			{
				int key = getch();
				switch (key)
				{
					// Esc
				case 27:
					cnt = 0;
					break;
				default:
					break;
				}
			}

			Sleep(500);
		}
		
		sprintf(cmd, "echo You have worked %d minutes >> %s", min, LOG_FILE);
		system(cmd);
		sprintf(cmd, "echo ----- ----- ----- ----- >> %s", LOG_FILE);
		system(cmd);
		
		printf("\n ***** ***** ***** ***** ***** \n");

	}
	
	return 0;
}


