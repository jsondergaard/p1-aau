#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "defines.h"

int addAssignment(void);

int assignmentMenu(void)
{
	char c;

	addAssignment();

	do
	{
		printf("Press " RED "a" RESET " to add another assignment\n");
		printf("Press " RED "m" RESET " to return to menu\n");

		scanf(" %s", &c);

		if (c == 'a')
			addAssignment();
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
