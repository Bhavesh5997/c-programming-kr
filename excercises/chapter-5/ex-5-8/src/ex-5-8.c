/*
 * Exercise-8: There is no error checking in day_of_year or month_day. Remedy
 *	       this defect.
 */

#include <stdio.h>

static char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
			    };

/* day_of_year: set day of year from month & day */
static int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (day <= 0 || month <= 0 || year <= 0)
		return -1;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (daytab[leap][month] < day)
		return -1;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}

/* month_day: set month, day from day of year */
static void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year <= 0 || year <= 0) {
		*pmonth = 0;
		*pday = 0;

		return;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if ((leap == 1 && ((yearday >= 1 && yearday <= 366) != 1)) ||
	    (leap == 0 && ((yearday >= 1 && yearday <= 365) != 1))) {
		*pmonth = 0;
		*pday = 0;
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;
}

int main(void)
{
	int year, month, day, year_day;
	int result;

	printf("To find year day from the year, month and day:\n");
	printf("Enter your year: ");
	scanf("%d", &year);
	printf("Enter your month: ");
	scanf("%d", &month);
	printf("Enter your month day: ");
	scanf("%d", &day);

	result = day_of_year(year, month, day);

	if (result == -1)
		printf("Invalid input\n\n");
	else
		printf("day of year: %d\n\n", result);

	printf("To find month and day from the year and day of year:\n");
	printf("Enter your year: ");
	scanf("%d", &year);
	printf("Enter your day of year: ");
	scanf("%d", &year_day);

	month_day(year, year_day, &month, &day);

	if (month == 0 && day == 0) {
		printf("Invalid input\n");
		return -1;
	}

	printf("month = %d day = %d\n", month, day);

	return 0;
}
