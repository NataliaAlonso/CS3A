#include "dayofyear.h"
#include "month.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void DayOfYear::input()
{
    month1.readMonthByNumber();
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date();
}

void DayOfYear::output()
{
    cout << "month = ";
    month1.outputMonthByName();
    cout << " , day = " << day <<endl;

}

void DayOfYear::set(int x, int y)
{
    month1.setMonth(x);
    day = y;
    check_date();
}

int DayOfYear::getMonth()
{
    return month1.outputMonthByNumber();

}

int DayOfYear::getDay()
{
    return day;
}

void DayOfYear::check_date()
{
    if( ( day < 1 )|| ( day > 31) )
    {
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}
