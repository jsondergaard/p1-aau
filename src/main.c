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

	do
	{
		printMenu();

		fflush(stdin);
		c = getchar();

		if (c == 'c')
			viewCalendar();
		else if (c == 'a')
			assignmentMenu();
		else if (c == 'q')
			exit(1);
		else
			printf("Unknown command: %s\n", &c);
	} while (c != 'q');

	return 1;
}

void printMenu(void)
{
#if __APPLE__
	system("clear");
#endif
	printf(YELLOW "\tMain Menu\n" RESET);
	printf(RED "* " RESET "Press " RED "c" RESET " to view your calendar.\n");
	printf(RED "* " RESET "Press " RED "a" RESET " to manage assignments.\n");
	printf(RED "* " RESET "Press " RED "q" RESET " to quit.\n");
	printf(GREEN "> " RESET);
}
