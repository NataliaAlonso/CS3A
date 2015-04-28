#include "counter.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Create a counter object that can count up to user defined amount
counter::counter(int x)
{
    counterMax=x;
    total = 0;
    overFlow = 0;
    cout <<"New counter has total: "<< total << endl;
    cout <<"New counter max is: " << counterMax << endl;
}
// Default counter object will count up to 9999
counter::counter()
{
    counterMax = 9999;
    total = 0;
    cout <<"New counter has total: "<< total << endl;
    cout <<"New counter max is: " << counterMax << endl;
}
// Set the counter's number to 0
void counter::reset()
{
    total = 0;
    overFlow=0;
    cout << "Counter's total reset to " << total << "."<<endl;
}
// Increments the units digit by 1
void counter::incr1(int x)
{
    total += x;
    overFlow += overflow() ? 100 : 0;
    total -= overflow() ? 10000 : 0;
}
// Increments the tens digit by 1
void counter::incr10(int x)
{
    total += (x*10);
    overFlow += overflow() ? 100 : 0;
    total -= overflow() ? 10000 : 0;
}
// Increments the hundreds digit by 1
void counter::incr100(int x)
{
    total += (x*100);
    overFlow += overflow() ? 100 : 0;
    total -= overflow() ? 10000 : 0;
}
// Increments the thousands digit by 1
void counter::incr1000(int x)
{
    total += (x*1000);
    overFlow += overflow() ? 100 : 0;
    total -= overflow() ? 10000 : 0;
}
// Detects overflow{} needs to check after each increment
bool counter::overflow()
{
    return (total > counterMax);
}

void counter::display()
{
    cout << "Current total is "<< total << ", and ";
    if (overFlow == 0)
        cout << "there is no overflow." << endl;
    else
        cout << "overflow is $"<< overFlow << endl;
}

int counter::getOverflow()
{
    cout << "Overflow is: $" << overFlow <<  endl;
}

void counter::getFunction(char s, int x)
{
    if( s == 'a')
        incr1(x);
    if( s == 'A')
        incr1(x);
    if( s == 's')
        incr10(x);
    if( s == 'S')
        incr10(x);
    if( s == 'd')
        incr100(x);
    if( s == 'D')
        incr100(x);
    if( s == 'f')
        incr1000(x);
    if( s == 'F')
        incr1000(x);
    if( s == 'o')
        getOverflow();
    if( s == 'O')
        getOverflow();
    if( s == 'r')
        reset();
    if( s == 'R')
        reset();

}


