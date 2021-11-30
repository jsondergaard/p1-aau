#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "defines.h"
#include "calendar.h"
#include "assignment.h"

#define kBUFFERSIZE 4096 // How many bytes to read at a time

void printMenu(void);
int assignmentList(void);
int callback(void *, int, char **, char **);
void PickDate(void);

int main(int argc, char **argv)
{
	char c;

	printf(YELLOW "Good day! What do you want to do?\n" RESET);
	do
	{
		printMenu();

		scanf(" %s", &c);

		if (c == 'c')
			viewCalendar();
		else if (c == 'a')
			assignmentMenu();
		else if (c == 't')
			assignmentList();
		else if (c == 'd')
			PickDate();
		else if (c == 'q')
			exit(1);
		else
			printf("Unknown command %s.\n", &c);
	} while (c != 'q');

	return 1;
}

void printMenu(void)
{
	printf("Press c to view your calendar.\n");
	printf("Press a to add a new assignment.\n");
	printf("Press q to quit.\n");
#ifndef NDEBUG
	printf("DEBUG: t – List of assigments.\n");
#endif
}

#ifndef NDEBUG
int assignmentList(void)
{
	sqlite3 *db;
	char *error = 0;

	int rc = sqlite3_open("../database.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	printf("List of assignments:\n");

	char *sql = "SELECT * FROM assignments";

	rc = sqlite3_exec(db, sql, callback, 0, &error);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", error);

		sqlite3_free(error);
		sqlite3_close(db);

		return 1;
	}

	sqlite3_close(db);

	return 1;
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

	return 0;
}
#endif
