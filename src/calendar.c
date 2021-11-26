
#include <stdio.h>
#define ROWS 5
#define COLUMNS 7
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		// It is a leap year and February has 29 days.
		return 1;
	}
	else
	{
		// It is not a leap year, so February has 28 days.
		return 0;
	}
}

void viewCalendar(void)
{

	int calendar[ROWS][COLUMNS] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0}};
	printf(ANSI_COLOR_RED "                \txX JANUAR Xx\t " ANSI_COLOR_RESET "\n");
	printf(" ");
	for (int i = 0; i < ROWS; i++)
	{
		printf("\n_________________________________________________________\n");
		for (int j = 0; j < COLUMNS; j++)
		{

			printf("|  %d\t|", calander[i][j]);
		}
	}
	printf("\n_________________________________________________________\n");
}