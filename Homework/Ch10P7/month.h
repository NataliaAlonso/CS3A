#ifndef MONTH_H
#define MONTH_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Define a class called Month that is an abstract data type for a month
// Your class will have one member variable of type int to represent a month
// ( 1 for January, 2 for February, and so forth )

class month
{
public:

    //Constructor to set the month using the first three letters in the name of the month as three arguments, and store them in member char variables
    month(char x, char y, char z);

    // Constructor to set the month using an integer as an argument, and set three char member variables with the first three letters of the month
    month(int monthNumber);

    // Default constructor
    month();

    // Destructor
    ~month();

    // Input function that reads the month as an integer
    void readMonthByNumber();

    // Input function that reads the month as the first three letters in the name of the month
    void readMonthByName();

    // Output function that outputs the month as an integer
    void outputMonthByNumber();

    // Output function that outputs that month as the first three letters in the name of themonth
    void outputMonthByName();

    // Member function that returns the next month as a value of type Month
    month nextMonth();

    // Assigns month number from 3-letter strings
    int assignMonthNumber(string str);

    // Gets 3-letter month name
    string getMonth(int x);

    //Check if date number is valid
    void checkDate(int x);

private:
    // Member variable of type int to represent a month
    //( 1 for January, 2 for February, and so forth )
    int monthNum;
    char char1,char2,char3;

};

#endif // MONTH_H
