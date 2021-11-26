#include <stdio.h>
#include <stdlib.h>
#include "d_string.h"
#include "calendar.h"
#include <sqlite3.h>
#include "defines.h"

#define kBUFFERSIZE 4096 // How many bytes to read at a time

void printMenu(void);
void assignmentList(void);

int main(int argc, char **argv)
{
	int c;

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
	printf("List of assignments:\n");
}
