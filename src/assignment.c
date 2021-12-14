#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <sqlite3.h>
#include "defines.h"

typedef struct{

	int day;
	int studentTime;

}Day;

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

	Day day[31];

	char title[128];
	char rangeStart[64];
	char rangeEnd[64];
	char dueDateTime[64];

	time_t rawtime;
	struct tm *info;
	char timeString[64];
	int studentTime = 0;

	for (int i = 1; i <= 31; i++)
	{
		day[i].day = i;
		day[i].studentTime = 0;
	}

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

	printf("When shall the assignment be released? (YYYY-MM-DD)\n> ");
	scanf(" %[^\n]", &rangeStart[0]);
	printf("\n");

	printf("When is the assignment due? (YYYY-MM-DD)\n> ");
	scanf(" %[^\n]", &rangeEnd[0]);
	printf("\n");

	printf("When is the assignment due at the specific day? (HH:MM:SS)\n> ");
	scanf(" %[^\n]", &dueDateTime[0]);
	printf("\n");

	printf("What's the estimated scope of the assignment? (in hours)\n> ");
	scanf(" %d", &studentTime);
	printf("\n");

	char *sql = "SELECT due_at,student_time FROM assignments WHERE due_at BETWEEN @start AND @end";

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@start"), rangeStart, sizeof(rangeStart), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@end"), rangeEnd, sizeof(rangeEnd), SQLITE_STATIC);
	}
	ERRCHECK

	while (sqlite3_step(res) != SQLITE_DONE)
	{
		int dayGet, dummy;
		sscanf(sqlite3_column_text(res,0), "%d-%d-%d", &dummy, &dummy, &dayGet);
		day[dayGet].studentTime+=sqlite3_column_int(res,1);
	}

	for (int i = 1; i <= 31; i++)
	{
		if(day[i].studentTime > 0){
			printf("%d: %d\n", i, day[i].studentTime);
		}
	}

	/*char *sql = "INSERT INTO assignments(title, original_due_at, due_at, buffer_time, student_time, created_at, updated_at) VALUES(@title, @dueDate, @dueDate, @bufferTime, @studentTime, @createdAt, @updatedAt);";
	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@title"), title, sizeof(title), SQLITE_STATIC);
		sqlite3_bind_text(res, sqlite3_bind_parameter_index(res, "@dueDate"), dueDate, sizeof(dueDate), SQLITE_STATIC);
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
		printf(RED "Failed to create assignment.\n" RESET); */

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