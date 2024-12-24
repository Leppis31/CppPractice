#include "Date.h"
#include <iostream>

Date::Date(int d, int m, int y)
{
    if (!setValues(d, m, y)) {
        setValues(1, 1, 2022);
    }
}

bool Date::setValues(int d, int m, int y)
{
    if (m < 1 || m > 12) {
        return false;
    }

    if (y < 1900 || y > 2030) {
        return false;
    }

    int maxDays = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        maxDays = 30;
    }
    else if (m == 2) {
        maxDays = (y % 4 == 0) ? 29 : 28;
    }

    if (d < 1 || d > maxDays) {
        return false;
    }

    this->d = d;
    this->m = m;
    this->y = y;
    return true;
}
