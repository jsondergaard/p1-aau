#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "defines.h"
#include "assignment.h"
#include "sqlite3.h"

typedef struct {
	int day;
} Day;

int callback(void *, int, char **, char **);
void printCalendar(int month);
int printMonth(int numberOfDays,int month, Day * dueAtInfo);

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
		else if (c == 'c')
			printCalendar(1);
	} while (c != 'm');

	return 1;
}

void printCalendar(int month)
{
	int numberOfDays;
	int sqlYear;
	int sqlMonth;
	int sqlDay;

	printf("Which month would you like to view? (1, 2, 3, ...)\n");
	scanf(" %d", &month);

	if(month == 2)
		numberOfDays = 28;
	else if(month % 2 == 0)
		numberOfDays = 31;
	else
		numberOfDays = 30;

	printf(RED "%d\n" RESET, month);

	sqlite3 *db;
	sqlite3_stmt *res;
	char *error = 0;

	int rc = sqlite3_open(DBFILE, &db);

	ERRCHECK

	char *sql = "SELECT due_at FROM assignments WHERE due_at BETWEEN strftime('%Y', CURRENT_TIMESTAMP)-@month-01 AND strftime('%Y', CURRENT_TIMESTAMP)-@month-31";

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_int(res, sqlite3_bind_parameter_index(res, "@month"), month);
	}

	ERRCHECK

	Day dueAtInfo[31];
	char *sqlInfo;
	int i = 0;
	while (sqlite3_step(res) != SQLITE_DONE)
	{
		sqlInfo = sqlite3_column_text(res, 0);
		sscanf(sqlInfo, " %d-%d-%d",sqlYear, sqlMonth, sqlDay);
		dueAtInfo[i].day = sqlDay;
		i = i + 1;
	}

	sqlite3_finalize(res);

	switch (month){
		case 1: 
			printf(CYAN "JANUARY" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 2: 
			printf(CYAN "FEBRUARY" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 3: 
			printf(CYAN "MARCH" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 4: 
			printf(CYAN "APRIL" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 5: 
			printf(CYAN "MAY" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;
			
		case 6: 
			printf(CYAN "JUNE" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 7: 
			printf(CYAN "JULY" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 8: 
			printf(CYAN "AUGUST" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 9: 
			printf(CYAN "SEPTEMBER" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 10: 
			printf(CYAN "OCTOBER" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 11: 
			printf(CYAN "NOVEMBER" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		case 12: 
			printf(CYAN "DECEMBER" RESET);
			printMonth(numberOfDays, month, dueAtInfo);
			break;

		default:
			printf(RED "The entered month does not exist.\n" RESET);			
	}

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();
}

int printMonth(int numberOfDays, int month, Day * dueAtInfo){
	printf("\n_________________________________________________________\n");
	for (int i = 1; i < (numberOfDays + 1); i++)
	{	
		if (i == dueAtInfo[i].day){

			printf("|"RED"%d\t"RESET, i);
		}else {
			printf("|"GREEN"%d\t"RESET, i);
		}



		if(i % 7 == 0){
			printf("|\n");
			if (month == 2 && i == 28){
				printf("_________________________________________________________\n");
				return 0;
			}
			printf("_________________________________________________________\n");
		}
	}
	if ( month != 2){
		printf("|\n_________________\n");
	}else {
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