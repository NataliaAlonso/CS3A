#include "counter.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Create a counter object that can count up to 9999
counter::counter(int x)
{
    counterMax=x;
    total = 0;
    cout <<"New counter has total: "<< total;
}
// Default counter object that can count up to 9999
counter::counter(){}
// Set the counter's number to 0
void counter::reset(){}
// Increments the units digit by 1
void counter::incr1(){}
// Increments the tens digit by 1
void counter::incr10(){}
// Increments the hundreds digit by 1
void counter::incr100(){}
// Increments the thousands digit by 1
void counter::incr1000(){}
// Detects overflow{} needs to check after each increment
bool counter::overflow(){}
