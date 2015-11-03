#include <stdio.h>
#include "year.h"
#include "wkd.h"
#include "lpyear.h"
#include "days.h"
main()
{
	int y;
	printf("Enter the year: ");
	scanf(" %d", &y);
	char* day=week(days(year(y),lpyear(y)));
	//printf("The number of leap-years in/bw is: %d.\n", lpyear(y));
	printf("The first day of the year %d is %s.\n", y, day);
}
