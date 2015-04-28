#include "calculator.h"
#include "mixed.h"
#include "fraction.h"
#include "parser.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

calculator::calculator()
{
    numberStack;
    operatorStack;
    outputStack;
}

calculator::~calculator()
{
    //dtor
}

calculator::calculator(const calculator& other)
{
    //copy ctor
}

calculator& calculator::operator=(const calculator& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
