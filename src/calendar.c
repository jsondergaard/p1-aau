#include <stdio.h>
#include "defines.h"

#define ROWS 5
#define COLUMNS 7

int isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		// It is a leap year and February has 29 days.
		return 1;
	}
	else
	{
		// It is not a leap year, so February has 28 days.
		return 0;
	}
}

void viewCalendar(void)
{
	int calendar[ROWS][COLUMNS] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 0, 0, 0, 0}};

	printf(RED "                \t JANUAR \t " RESET "\n");
	printf(" ");

	for (int i = 0; i < ROWS; i++)
	{
		printf("\n_________________________________________________________\n");
		for (int j = 0; j < COLUMNS; j++)
		{
			printf("|  %d\t|", calendar[i][j]);
		}
	}
	printf("\n_________________________________________________________\n");
}

void PickDate (void){

    printf("\n_________________\n");
    for (int i = 0; i < 24; ++i) {
        printf("%d: |\t'Empty'\t|\n",i);
        printf("_________________\n");
    }

}
