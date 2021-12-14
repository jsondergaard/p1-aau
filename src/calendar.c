#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "assignment.h"
#include "sqlite3.h"
#define ROWS 5
#define COLUMNS 7

int callback(void *, int, char **, char **);
void printCalendar(void);

int viewCalendar(void)
{
	char c;

	printCalendar();

	do
	{
#if __APPLE__
		system("clear");
#endif
		printf(YELLOW "\tCalendar\n" RESET);
		printf(RED "* " RESET "Press " RED "c" RESET " to print calendar again\n");
		printf(RED "* " RESET "Press " RED "d" RESET " to view a specific date\n");
		printf(RED "* " RESET "Press " RED "t" RESET " to test output\n");
		printf(RED "* " RESET "Press " RED "m" RESET " to return to menu\n");
		printf(GREEN "> " RESET);

		scanf(" %s", &c);

		if (c == 't')
			printf(RED "Test output\n" RESET);
		else if (c == 'd')
			viewDate();
		else if (c == 'c')
			printCalendar();
	} while (c != 'm');

	return 1;
}

void printCalendar(void)
{
	int calendar[ROWS][COLUMNS] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0}};

	printf(RED "                \t JANUARY \t " RESET "\n");
	printf(" ");

	for (int i = 0; i < ROWS; i++)
	{
		printf("\n_________________________________________________________\n");
		for (int j = 0; j < COLUMNS; j++)
		{
			printf("|  %d\t|", calendar[i][j]);
		}
	}
	printf("\n_________________________________________________________\n");

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();
}

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1; // It is a leap year and February has 29 days.
	else
		return 0; // It is not a leap year, so February has 28 days.
}