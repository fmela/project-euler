#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

enum Month {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12,
};

enum Day {
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
};

struct Date {
    int year;
    enum Month month;
    int day_of_month;

    enum Day day_of_week;
};

bool is_leap_year(int year)
{
    if (year % 4)
	return false;
    if (year % 100)
	return true;
    return year % 400 == 0;
}

int days_in_month(enum Month month, int year) {
    switch (month) {
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER:
	    return 31;

	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
	    return 30;

	case FEBRUARY:
	    return is_leap_year(year) ? 29 : 28;
    }
    fprintf(stderr, "Bad month given: %d\n", month);
    abort();
}

void next_day(struct Date *d) {
    if (++d->day_of_month > days_in_month(d->month, d->year)) {
	d->day_of_month = 1;
	if (d->month == DECEMBER) {
	    d->month = JANUARY;
	    ++d->year;
	} else {
	    ++d->month;
	}
    }
    if (d->day_of_week == SATURDAY) {
	d->day_of_week = SUNDAY;
    } else {
	++d->day_of_week;
    }
}

int
main()
{
    assert(is_leap_year(1904));
    assert(!is_leap_year(1900));
    assert(is_leap_year(2000));

    struct Date d;
    d.year = 1900;
    d.month = JANUARY;
    d.day_of_month = 1;
    d.day_of_week = MONDAY;

    int num_firsts_on_sunday = 0;
    while (d.year < 1901)
	next_day(&d);

    while (d.year <= 2000) {
	if (d.day_of_month == 1 && d.day_of_week == SUNDAY) {
	    printf("%d/%d/%d is a first on a Sunday.\n",
		   d.month, d.day_of_month, d.year);
	    ++num_firsts_on_sunday;
	}
	next_day(&d);
    }
    printf("Number of firsts on Sunday: %d\n", num_firsts_on_sunday);
    return 0;
}
