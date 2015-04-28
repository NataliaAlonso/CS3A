#include "month.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void getMonth();

int main()
{
    while(cin)
    {
    getMonth();
    }
}


void getMonth()
{
    string line;
    month monthInput;
    cout << "How would you like to enter your month? Type 'name' or 'number'.\n";
    cin >> line;
    if (line=="name")
    {
        monthInput.readMonthByName();
    }
    else
    {
        monthInput.readMonthByNumber();
    }

    monthInput.outputMonthByName();
    monthInput.outputMonthByNumber();

    month nextMonth = monthInput.nextMonth();
    cout<< "And for the next month...";
    nextMonth.outputMonthByName();
    nextMonth.outputMonthByNumber();


    line = "";

}
