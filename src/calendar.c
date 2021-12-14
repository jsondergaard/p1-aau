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
int printMonth(int numberOfDays,int month);

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

	char *sql = "SELECT due_at,student_time FROM assignments WHERE due_at BETWEEN strftime('%Y', CURRENT_TIMESTAMP)-@month-01 AND strftime('%Y', CURRENT_TIMESTAMP)-@month-31";

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_int(res, sqlite3_bind_parameter_index(res, "@month"), month);
	}

	ERRCHECK

	while (sqlite3_step(res) != SQLITE_DONE)
	{

		printf(RED "%s: %d" RESET " student hours, don't pick this\n", sqlite3_column_text(res, 0), sqlite3_column_int(res, 1));
	}

	sqlite3_finalize(res);

	switch (month){
		case 1: 
			printf(CYAN "JANUARY" RESET);
			printMonth(numberOfDays, month);
			break;

		case 2: 
			printf(CYAN "FEBRUARY" RESET);
			printMonth(numberOfDays, month);
			break;

		case 3: 
			printf(CYAN "MARCH" RESET);
			printMonth(numberOfDays, month);
			break;

		case 4: 
			printf(CYAN "APRIL" RESET);
			printMonth(numberOfDays, month);
			break;

		case 5: 
			printf(CYAN "MAY" RESET);
			printMonth(numberOfDays, month);
			break;
			
		case 6: 
			printf(CYAN "JUNE" RESET);
			printMonth(numberOfDays, month);
			break;

		case 7: 
			printf(CYAN "JULY" RESET);
			printMonth(numberOfDays, month);
			break;

		case 8: 
			printf(CYAN "AUGUST" RESET);
			printMonth(numberOfDays, month);
			break;

		case 9: 
			printf(CYAN "SEPTEMBER" RESET);
			printMonth(numberOfDays, month);
			break;

		case 10: 
			printf(CYAN "OCTOBER" RESET);
			printMonth(numberOfDays, month);
			break;

		case 11: 
			printf(CYAN "NOVEMBER" RESET);
			printMonth(numberOfDays, month);
			break;

		case 12: 
			printf(CYAN "DECEMBER" RESET);
			printMonth(numberOfDays, month);
			break;

		default:
			printf(RED "The entered month does not exist.\n" RESET);			
	}

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();
}

int printMonth(int numberOfDays, int month){
	printf("\n_________________________________________________________\n");
	for (int i = 1; i < (numberOfDays + 1); i++)
	{	
		if (i == 1){

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

int pullMonthFromDB(int month){

	sqlite3 *db;
	sqlite3_stmt *res;
	char *error = 0;

	int rc = sqlite3_open(DBFILE, &db);	
	ERRCHECK

	char * sql = "SELECT due_at FROM assignments WHERE due_at @start AND @end";	
}

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1; // It is a leap year and February has 29 days.
	else
		return 0; // It is not a leap year, so February has 28 days.
}