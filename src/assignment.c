#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "defines.h"

int addAssignment(void);
int listAssignments(void);
int callback(void *, int, char **, char **);

int assignmentMenu(void)
{
	char c;

	do
	{
		printf("Press " RED "a" RESET " to add an assignment\n");
		printf("Press " RED "l" RESET " to list all assignments\n");
		printf("Press " RED "m" RESET " to return to menu\n");

		scanf(" %s", &c);

		if (c == 'a')
			addAssignment();
		else if (c == 'l')
			listAssignments();
	} while (c != 'm');

	return 1;
}

int addAssignment(void)
{
	char title[256];
	char dueDate[256];

	printf(YELLOW "Add assignment\n" RESET);

	printf("What do you want the assignment to be called? > ");
	scanf(" %s", &title);
	printf("\n");

#ifndef NDEBUG
	printf("Assignment name: %s\n", title);
#endif

	printf("When is the assignment due? (YYYY-MM-DD HH:SS) > ");
	scanf(" %s", &dueDate);
	printf("\n");

#ifndef NDEBUG
	printf("Due date: %s\n", dueDate);
#endif
}

int listAssignments(void)
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