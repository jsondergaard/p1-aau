#include <stdio.h>
#include <stdlib.h>
#include "d_string.h"
#include "calendar.h"
#include <sqlite3.h>

#define kBUFFERSIZE 4096 // How many bytes to read at a time

// Pretty colors
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"

void printMenu(void);
void assignmentList(void);

int main(int argc, char **argv)
{
	int c;

	sqlite3 *db;

	if (sqlite3_open("database.db", &db))
	{
		printf("Error initializing database.\n");
		exit(-1);
	}

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

		default:
			printf("Unrecognized command.\n");
			break;
		}
	} while (c != 'q');

	sqlite3_close(db);

	return 0;
}

void printMenu(void)
{
	printf(YELLOW "Good day! What do you want to do?\n" RESET);
	printf("Press c to view your calendar.\n");
	printf("Press a to add a new assignment.\n");
#ifndef NDEBUG
	printf("DEBUG: t – List of assigments.\n");
#endif
	printf("Press q to quit.\n");
}

void assigmentList(void)
{
	char *sql;

	printf("List of assignments:\n");
}
