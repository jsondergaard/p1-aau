#include <stdio.h>
#include "defines.h"

int addAssignment(void)
{
	int c;

	do
	{
		printf("... add assignment ...\n");

		printf("Press " RED "m" RESET " to return to menu\n");

		c = getchar();
		getchar();

		return 0;
	} while (c != 'q');
}
