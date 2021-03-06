#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "assignment.h"
#include "sqlite3.h"

typedef struct
{
	int year;
	int month;
	int day;
	int match;
} Day;

int callback(void *, int, char **, char **);
void printCalendar(void);
void printMonth(int numberOfDays, int month, Day *dueAtInfo);

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
		printf(RED "* " RESET "Press " RED "m" RESET " to return to menu\n");
		printf(GREEN "> " RESET);

		scanf(" %s", &c);

		if (c == 'c')
			printCalendar();
	} while (c != 'm');

	return 1;
}

void printCalendar(void)
{
	int numberOfDays, month;
	Day dueAtInfo[128];

	printf("Which month would you like to view? (1, 2, 3, ...)\n");

	printf(GREEN "> " RESET);
	scanf(" %d", &month);

	if (month == 2)
		numberOfDays = 28;
	else if (month % 2 == 0)
		numberOfDays = 30;
	else
		numberOfDays = 31;

	sqlite3 *db;
	sqlite3_stmt *res;


	int rc = sqlite3_open(DBFILE, &db);

	ERRCHECK

	char *sql = "SELECT due_at FROM assignments WHERE due_at BETWEEN strftime('%Y', CURRENT_TIMESTAMP) || '-0' || @month || '-01' AND strftime('%Y', CURRENT_TIMESTAMP) || '-0' || @month || '-31'";

	printf(RED "%d\n" RESET, month);

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_int(res, 0, month);
		sqlite3_bind_int(res, 1, month);
	}

	for (int i = 0; i <= 31; i++)
	{
		dueAtInfo[i].match = 0;
	}

	ERRCHECK

	int i = 0;
	while (sqlite3_step(res) != SQLITE_DONE)
	{
		sscanf(sqlite3_column_text(res, 0), "%d-%d-%d", &dueAtInfo[i].year, &dueAtInfo[i].month, &dueAtInfo[i].day);
		dueAtInfo[dueAtInfo[i].day].match = 1;
		i++;
	}

	sqlite3_finalize(res);

	switch (month)
	{
	case 1:
		printf(YELLOW "\t\tJANUARY" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 2:
		printf(YELLOW "\t\tFEBRUARY" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 3:
		printf(YELLOW "\t\tMARCH" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 4:
		printf(YELLOW "\t\tAPRIL" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 5:
		printf(YELLOW "\t\tMAY" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 6:
		printf(YELLOW "\t\tJUNE" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 7:
		printf(YELLOW "\t\tJULY" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 8:
		printf(YELLOW "\t\tAUGUST" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 9:
		printf(YELLOW "\t\tSEPTEMBER" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 10:
		printf(YELLOW "\t\tOCTOBER" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 11:
		printf(YELLOW "\t\tNOVEMBER" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	case 12:
		printf(YELLOW "\t\tDECEMBER" RESET);
		printMonth(numberOfDays, month, dueAtInfo);
		break;

	default:
		printf(RED "The entered month does not exist.\n" RESET);
	}

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();
}

void printMonth(int numberOfDays, int month, Day *dueAtInfo)
{
	printf("\n_________________________________________________________\n");

	for (int i = 1; i < (numberOfDays + 1); i++)
	{
		if (dueAtInfo[i].match)
			printf("|" RED "   %d\t" RESET, i);
		else
			printf("|" GREEN "   %d\t" RESET, i);

		if (i % 7 == 0)
		{
			if(month == 2 && i == 28)
				break;

			printf("|\n_________________________________________________________\n");
		}
	}

	if (month != 2)
	{
		printf("|\n_________________\n");
	}
	else
	{
		printf("|\n_________________________________________________________\n");
	}
}

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1; // It is a leap year and February has 29 days.
	else
		return 0; // It is not a leap year, so February has 28 days.
}