#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <sqlite3.h>
#include "defines.h"

int addAssignment(void);
int listAssignments(void);
int callback(void *, int, char **, char **);

int assignmentMenu(void)
{
	char c;

	do
	{
#if __APPLE__
		system("clear");
#endif
		printf(YELLOW "\tAssignments\n" RESET);
		printf(RED "* " RESET "Press " RED "a" RESET " to add an assignment\n");
		printf(RED "* " RESET "Press " RED "l" RESET " to list all assignments\n");
		printf(RED "* " RESET "Press " RED "m" RESET " to return to menu\n");
		printf(GREEN "> " RESET);

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
	char title[128];
	char dueDate[64];

	time_t rawtime;
	struct tm *info;
	char timeString[64];

	time(&rawtime);
	strftime(timeString, 64, "%Y-%m-%d %H:%M:%S", localtime(&rawtime));

	sqlite3 *db;
	sqlite3_stmt *res;
	char *error = 0;

	int rc = sqlite3_open(DBFILE, &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	printf(YELLOW "Add assignment\n" RESET);

	printf("What do you want the assignment to be called?\n> ");
	scanf(" %s", &title[0]);
	printf("\n");

	printf("When is the assignment due? (YYYY-MM-DD HH:MM:SS)\n> ");
	scanf(" %[^\n]", &dueDate[0]);
	printf("\n");

	printf("Inserting: %s (due at %s, created at %s)\n", title, dueDate, timeString);

	char *sql = "INSERT INTO assignments(name, due_at, created_at) VALUES(@title, @dueDate, @timeNow);";
	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@title"), title, strlen(title), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@dueDate"), dueDate, strlen(title), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@timeNow"), timeString, strlen(title), SQLITE_STATIC);
	}

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Failed to create assignment\n");
		fprintf(stderr, "SQL error: %s\n", error);

		sqlite3_free(error);
		sqlite3_close(db);

		return 1;
	}

	rc = sqlite3_step(res);
	if (rc == SQLITE_OK)
		printf(GREEN "Successfully created assignment.\n" RESET);
	else if (rc != SQLITE_OK)
		printf(RED "Failed to create assignment.\n" RESET);

	sqlite3_finalize(res);
	sqlite3_close(db);

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();

	return 1;
}

int listAssignments(void)
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

	printf("Press ENTER to continue..\n");
	fflush(stdin);
	getchar();

	return 1;
}

int callback(void *nil, int argc, char **argv,
			 char **column)
{
	nil = 0;

	for (int i = 0; i < argc; i++)
		printf("%s = %s\n", column[i], argv[i] ? argv[i] : "NULL");

	printf("\n");

	return 0;
}