#include "month.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Constructor to set the month using the first three letters in the name of the month as three arguments

month::month(char x, char y, char z)
{
    char charArray[3]= {x,y,z};
    string monthArray[12]={"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    string monthString;
    int pos=0;
    monthString.insert(pos,charArray,3);
    for(int i=0; i < 12; i++)
    {
        if( monthString == monthArray[i] )
            monthNum = i+1;
    }

}

// Constructor to set the month using an integer as an argument

month::month(int monthNumber)
{
    monthNum = monthNumber;
}

// Default constructor

month::month()
{
    monthNum=1;
}
// Destructor

month::~month()
{

}


// Input function that reads the month as an integer
void month::readMonthByNumber()
{
    cout << "Please enter the month as a number: " << endl;
    cin >> monthNum;
    checkDate(monthNum);
}

// Input function that reads the month as the first three letters in the name of the month

void month::readMonthByName()
{
    string str;
    cout << "Please enter the name of your month: " << endl;
    cin >> str;
    string shortNameIn  = str.substr(0,3);
    monthNum = assignMonthNumber(shortNameIn);
}

// Output function that outputs the month as an integer

void month::outputMonthByNumber()
{
    cout << "Your month is number " << monthNum << "." << endl;
}

// Output function that outputs that month as the first three letters in the name of the month

void month::outputMonthByName()
{
    string getMonthName = getMonth(monthNum);
    cout << "The three-letter month name for your month is " << getMonthName << "." << endl;
}


// Member function that returns the next month as a value of type Month
month month::nextMonth()
{
    month jan(1);
    month next(monthNum+1);
    if (monthNum != 12)
        return next;
    else
        return jan;
}

// Assigns month number from 3-letter strings
int month::assignMonthNumber(string str)
{
    int assignMonth;
    string monthArray[12]={"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        for(int i=0; i < 12; i++)
        {
            if( str == monthArray[i] )
            assignMonth = i+1;
    }
        checkDate(assignMonth);
return assignMonth;
}

// Gets 3-letter month name
string month::getMonth(int x)
{
    string monthArray[12]={"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    return monthArray[x-1];
}

void month::checkDate(int x)
{
    if((x<1) || (x>12))
    {
        cout << "Illegal month. Aborting program.\n";
        exit(1);
    }
}
