#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "defines.h"

int addAssignment(void);
time_t string_to_seconds(const char *);

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
	printf("Due date unix time: %d\n", string_to_seconds(&dueDate));
#endif
}

time_t string_to_seconds(const char *timestamp_str)
{
	struct tm tm;
	time_t seconds;
	int r;

	if (timestamp_str == NULL)
	{
		printf("null argument\n");
		return (time_t)-1;
	}
	r = sscanf(timestamp_str, "%d-%d-%d %d:%d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
	if (r != 6)
	{
		printf("expected %d numbers scanned in %s\n", r, timestamp_str);
		return (time_t)-1;
	}

	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	tm.tm_isdst = 0;
	seconds = mktime(&tm);
	if (seconds == (time_t)-1)
	{
		printf("reading time from %s failed\n", timestamp_str);
	}

	return seconds;
}
