#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "mixed.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


typedef void (*fptr)(mixed &x, mixed &y);

bool readInputLine(mixed& x, char &op, mixed& y);
void perform(mixed&x, char&op, mixed& y, fptr whatToDo[]);
void add(mixed &x, mixed &y);
void subtract(mixed &x, mixed &y);
void multiply(mixed &x, mixed &y);
void divide(mixed &x, mixed &y);
void badOp(mixed &x, mixed &y);
void initialize(fptr whatToDo[]);
void sterilize(string& line);
void convert(string oper, char &op);
void lessThan(mixed &x, mixed &y);
void greaterThan(mixed &x, mixed &y);
void equal(mixed &x, mixed &y);
void notEqual(mixed &x, mixed &y);
void lessThanEqual(mixed &x, mixed &y);
void greaterThanEqual(mixed &x, mixed &y);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mixed x,y;
    fptr whatToDo[128];
    initialize(whatToDo);
    char op;
    while(readInputLine(x,op,y))
        perform(x,op,y, whatToDo);
    return a.exec();
}


void lessThan(mixed &x, mixed &y)
{
    cout<<boolalpha<<(x<y)<<endl;
}

void greaterThan(mixed &x, mixed &y)
{
    cout<<boolalpha<<(x > y)<<endl;
}

void equal(mixed &x, mixed &y)
{
    cout<<boolalpha<<(x == y)<<endl;
}

void notEqual(mixed &x, mixed &y)
{
    cout<<boolalpha<<(x != y)<<endl;
}

void lessThanEqual(mixed &x, mixed &y)
{
    cout<<boolalpha<<(x <= y)<<endl;
}

void greaterThanEqual(mixed &x, mixed &y)
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

bool readInputLine(mixed& x, char &op, mixed& y)
{
    string line, oper;
    stringstream ss;
    cout<<"Equation: ";
    getline(cin, line);
    if(line == "")
        return false;
    ss<<line;
  //  sterilize(line);
    ss>>x>>oper>>y;
    convert(oper, op);
    cout<<"Equation is: "<<x<<" "<<oper<<" "<<y<<" = ";
    return true;
}

void perform(mixed&x, char&op, mixed& y, fptr whatToDo[])
{
    (whatToDo[op])(x,y);
}

void add(mixed &x, mixed &y)
{
    cout<<(x + y)<<endl;
}

void divide(mixed &x, mixed &y)
{
    cout<<(x/y)<<endl;
}

void subtract(mixed &x, mixed &y)
{
    cout<<(x - y)<<endl;
}

void multiply(mixed &x, mixed &y)
{
    cout<<(x*y)<<endl;
}

void badOp(mixed &x, mixed &y)
{
    cout<<"Bad operation. No solution"<<endl;
}
