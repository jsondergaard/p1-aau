#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "calendar.h"
#include "assignment.h"

#define kBUFFERSIZE 4096 // How many bytes to read at a time

void printMenu(void);

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
	printf("Press a to manage assignments.\n");
	printf("Press q to quit.\n");
}
