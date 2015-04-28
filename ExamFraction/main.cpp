#include <iostream>
#include <cstdlib>
#include "fraction.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef void (*fptr)(fraction &x, fraction &y);

bool readInputLine(fraction& x, char &op, fraction& y);
void perform(fraction&x, char&op, fraction& y, fptr whatToDo[]);
void add(fraction &x, fraction &y);
void subtract(fraction &x, fraction &y);
void multiply(fraction &x, fraction &y);
void divide(fraction &x, fraction &y);
void badOp(fraction &x, fraction &y);
void initialize(fptr whatToDo[]);
void sterilize(string& line);
void convert(string oper, char &op);
void lessThan(fraction &x, fraction &y);
void greaterThan(fraction &x, fraction &y);
void equal(fraction &x, fraction &y);
void notEqual(fraction &x, fraction &y);
void lessThanEqual(fraction &x, fraction &y);
void greaterThanEqual(fraction &x, fraction &y);

int main()
{

    fraction x,y;
    fptr whatToDo[128];
    initialize(whatToDo);
    char op;
    while(readInputLine(x,op,y))
        perform(x,op,y, whatToDo);

}


void lessThan(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x<y)<<endl;
}

void greaterThan(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x > y)<<endl;
}

void equal(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x == y)<<endl;
}

void notEqual(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x != y)<<endl;
}

void lessThanEqual(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x <= y)<<endl;
}

void greaterThanEqual(fraction &x, fraction &y)
{
    cout<<boolalpha<<(x >= y)<<endl;
}


void sterilize(string& line)
{
    int pos;
    while((pos = line.find(' ')) != string::npos)
          line.erase(pos,1);
    pos = line.find('/');
    pos = line.find_first_of("!><=+-*/", pos+1);
    line.insert(pos," ");
    pos = line.find_first_of("0123456789", pos);
    line.insert(pos," ");
}


void convert(string oper, char &op)
{
    if(oper.size() == 1)
        op = oper[0];
    else
        if(oper == "<=")
            op = (char)1;
        else
          if(oper == ">=")
            op = (char)2;
          else
            if(oper == "!=")
              op = (char)3;
            else
             if(oper == "==")
                op = (char)4;
             else
                 op = (char)5;
}

void initialize(fptr whatToDo[])
{
    for(int i = 0; i < 128; i++)
        whatToDo[i] = badOp;
    whatToDo['+'] = add;
    whatToDo['-'] = subtract;
    whatToDo['*'] = multiply;
    whatToDo['/'] = divide;
    whatToDo['>'] = greaterThan;
    whatToDo['<'] = lessThan;
    whatToDo['='] = equal;
    whatToDo[1] = lessThanEqual;
    whatToDo[2] = greaterThanEqual;
    whatToDo[3] = notEqual;
    whatToDo[4] = equal;
}

bool readInputLine(fraction& x, char &op, fraction& y)
{
    string line, oper;
    stringstream ss;
    cout<<"Equation: ";
    getline(cin, line);
    if(line == "")
        return false;
    ss<<line;
    sterilize(line);
    ss>>x>>oper>>y;
    convert(oper, op);
    cout<<"Equation is: "<<x<<" "<<oper<<" "<<y<<" = ";
    return true;
}

void perform(fraction&x, char&op, fraction& y, fptr whatToDo[])
{
    (whatToDo[op])(x,y);
}

void add(fraction &x, fraction &y)
{
    cout<<(x + y)<<endl;
}

void divide(fraction &x, fraction &y)
{
    cout<<(x/y)<<endl;
}

void subtract(fraction &x, fraction &y)
{
    cout<<(x - y)<<endl;
}

void multiply(fraction &x, fraction &y)
{

    cout<<(x*y)<<endl;
}

void badOp(fraction &x, fraction &y)
{
    cout<<"Bad operation. No solution"<<endl;
}
