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
	int studentTime = 0, bufferTime = 0;

	time(&rawtime);
	strftime(timeString, 64, "%Y-%m-%d %H:%M:%S", localtime(&rawtime));

	sqlite3 *db;
	sqlite3_stmt *res;
	char *error = 0;

	int rc = sqlite3_open(DBFILE, &db);

	ERRCHECK

	printf(YELLOW "Add assignment\n" RESET);

	printf("What do you want the assignment to be called?\n> ");
	scanf(" %s", &title[0]);
	printf("\n");
	fflush(stdin);

	printf("When is the assignment due? (YYYY-MM-DD HH:MM:SS)\n> ");
	scanf(" %[^\n]", &dueDate[0]);
	printf("\n");

	printf("How much buffer time should there be? (in hours)\n> ");
	scanf(" %d", &bufferTime);
	printf("\n");

	printf("What's the estimated scope of the assignment? (in hours)\n> ");
	scanf(" %d", &studentTime);
	printf("\n");

	char *sql = "INSERT INTO assignments(title, due_at, buffer_time, student_time, created_at, updated_at) VALUES(@title, @dueDate, @bufferTime, @studentTime, @createdAt, @updatedAt);";
	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@title"), title, sizeof(title), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@dueDate"), dueDate, sizeof(dueDate), SQLITE_STATIC);
		sqlite3_bind_int(res, sqlite3_bind_parameter_index(res, "@bufferTime"), bufferTime);
		sqlite3_bind_int(res, sqlite3_bind_parameter_index(res, "@studentTime"), studentTime);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@createdAt"), timeString, sizeof(timeString), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@updatedAt"), timeString, sizeof(timeString), SQLITE_STATIC);
	}

	ERRCHECK

	rc = sqlite3_step(res);
	if (rc == SQLITE_DONE)
		printf(GREEN "Successfully created assignment.\n" RESET);
	else if (rc != SQLITE_DONE)
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

	ERRCHECK

	printf("List of assignments:\n");

	char *sql = "SELECT * FROM assignments ORDER BY due_at";

	rc = sqlite3_exec(db, sql, callback, 0, &error);

	ERRCHECK

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

	for (int i = 1; i < argc; i++)
		printf("%s = %s\n", column[i], argv[i] ? argv[i] : "NULL");

	printf("\n");

	return 0;
}