int isLeapYear(int year) {
    if(year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
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
