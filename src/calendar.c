#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "sqlite3.h"

#define ROWS 5
#define COLUMNS 7

int callback(void *, int, char **, char **);
void printCalendar(int);
int viewDate(void);

int viewCalendar(void)
{
	char c;

	do
	{
#if __APPLE__
		system("clear");
#endif
		printf(YELLOW "\tCalendar\n" RESET);
		printf(RED "* " RESET "Press " RED "c" RESET " to print calendar\n");
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
			printCalendar(1);
	} while (c != 'm');

	return 1;
}

void printCalendar(int month)
{
	int numberOfDays;

	if(month == 2)
		numberOfDays = 28;
	else if(month % 2 == 0)
		numberOfDays = 30;
	else
		numberOfDays = 31;

	printf(RED "%d\n" RESET, month);

	for (int i = 1; i < (numberOfDays / 7); i++)
	{
		printf("\n_________________________________________________________\n");
		for (int j = 1; j < 7; j++)
		{
			printf("|  %d\t|", j);
		}
	}
	printf("\n_________________________________________________________\n");

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();
}

int viewDate(void)
{
	sqlite3 *db;
	char *error = 0;

	int rc = sqlite3_open(DBFILE, &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}
	char *sql = "SELECT * FROM assignments";
	rc = sqlite3_exec(db, sql, callback, 0, &error);

	char date;
	scanf("%c",date);
	printf("\n_________________\n");
	for (int i = 0; i < 24; ++i)
	{
		printf("%d: |\t'Empty'\t|\n", i);
		printf("_________________\n");
	}
	sqlite3_close(db);
}

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1; // It is a leap year and February has 29 days.
	else
		return 0; // It is not a leap year, so February has 28 days.
}