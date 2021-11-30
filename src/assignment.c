#include <stdio.h>
#include "defines.h"

int addAssignment(void)
{
	int c;
	char *title;

	do
	{
		printf(YELLOW "Add assignment\n" RESET);

		printf("What do you want the assignment to be called? > ");
		scanf("%s", &title);
		printf("\n");

#ifndef NDEBUG
		printf("Assignment name: %s\n", &title);
#endif

		printf("Press " RED "m" RESET " to return to menu\n");

		c = getchar();
		getchar();

		return 1;
	} while (c != 'm');

	return 0;
}
