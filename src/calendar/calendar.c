int isLeapYear(int year) {
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
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
