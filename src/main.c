#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "defines.h"
#include "d_string.h"
#include "calendar.h"

#define kBUFFERSIZE 4096 // How many bytes to read at a time

void printMenu(void);
int assignmentList(void);
int callback(void *, int, char **, char **);

int main(int argc, char **argv)
{
	int c;

	printf(YELLOW "Good day! What do you want to do?\n" RESET);

	do
	{
		printMenu();

		c = getchar();
		getchar(); // consume newline

		switch (c)
		{
		case 'c':
			viewCalendar();
			break;

		case 'a':
			printf("Add new assignment\n");
			break;

		case 't':
			assignmentList();
			break;

		case 'q':
			break;

		default:
			printf("Unrecognized command.\n");
			break;
		}
	} while (c != 'q');

	return 0;
}

void printMenu(void)
{
	printf("Press c to view your calendar.\n");
	printf("Press a to add a new assignment.\n");
#ifndef NDEBUG
	printf("DEBUG: t – List of assigments.\n");
#endif
	printf("Press q to quit.\n");
}

int assignmentList(void)
{
	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("database.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	printf("List of assignments:\n");

	char *sql = "SELECT * FROM assignments";

	rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", err_msg);

		sqlite3_free(err_msg);
		sqlite3_close(db);

		return 1;
	}

	sqlite3_close(db);

	return 1;
}

int callback(void *NotUsed, int argc, char **argv,
			 char **azColName)
{

	NotUsed = 0;

	for (int i = 0; i < argc; i++)
	{

		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;
}
