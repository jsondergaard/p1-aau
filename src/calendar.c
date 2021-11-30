#include <stdio.h>
#include "defines.h"
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
		printf("Press c to print calendar again\n");
		printf("Press t to test output\n");
		printf("Press m to return to menu\n");

		scanf(" %s", &c);

		if (c == 't')
			printf(RED "Test output\n" RESET);
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

	printf(RED "                \t JANUAR \t " RESET "\n");
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
}

void PickDate(void)
{
	/*sqlite3 *db;
	char *error = 0;

	int rc = sqlite3_open("../database.db", &db);
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
	scanf("%c",date);*/
	printf("\n_________________\n");
	for (int i = 0; i < 24; ++i)
	{
		printf("%d: |\t'Empty'\t|\n", i);
		printf("_________________\n");
	}
	/*sqlite3_close(db);
}
int callback(void *nil, int argc, char **argv,
			 char **column)
{

	nil = 0;

	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", column[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;*/
}

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