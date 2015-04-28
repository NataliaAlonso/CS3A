#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "month.h"

class DayOfYear
{
public:
    void input();
    void output();
    void set(int x, int y);
    int getMonth();
    int getDay();

private:
    void check_date();
    month month1;
    int day;
};

#endif // DAYOFYEAR_H
