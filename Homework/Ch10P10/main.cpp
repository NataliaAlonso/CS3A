// A rational number is composed of two integers with division indicated.
// It is not carried out, only indicated, as in 1/2, 2/3, 15/32, etc.
// You should represent rational numbrs by two int values, numerator, and denominator.

#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

class rational
{
    public:
        // Constructor to create a rational number out of two integers, numerator and denominator.
        rational(int x, int y);
        // Contructor to create a rational number out of one integer, the numerator, and the denominator is equal to 1. (E.g.: 2/1)
        rational(int x);
        // Member function to fetch rational number in the form 2/3 to from the keyboard or from a file
        void input();
        // Member function to write rational number in the form 2/3 to from the keyboard or from a file
        void output();
        // Adds rational and returns value
        rational add(rational x);
        // Subtracts rationals and returns value
        rational sub(rational x);
        // Multiplies rationals and returns value
        rational mul(rational x);
        // Divides rationals and returns value
        rational div(rational x);
        // Returns negative
        rational neg();
        // Less than operator, returns bool value
        bool less(rational x);

    private:
        int num, denom;
};

void getInput();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    while(cin)
    {
        getInput();
    }

    return a.exec();
}

// Constructor to create a rational number out of two integers, numerator and denominator.
rational::rational(int x, int y)
{
    num = x;
    denom = y;
}

// Contructor to create a rational number out of one integer, the numerator, and the denominator is equal to 1. (E.g.: 2/1)
rational::rational(int x)
{
    num=x;
    denom=1;
}

// Member function to fetch rational number in the form 2/3 from the keyboard or from a file
void rational::input()
{
    char op;
    string line;
    int x;
    int y;
    cout << "\n\nPlease enter a rational number in the form x/y.\n";
    getline(cin,line);
    const char * cs = line.c_str ();
    int pos = 0;
    pos = line.find_first_of('/',0);
    if( pos == -1 )
    {
        sscanf(cs,"%d",&x);
        num = x;
        denom = 1;
        op = '/';
    }
    else
    {
       sscanf(cs,"%d %c %d",&x,&op,&y);
       num = x;
       denom = y;
    }

    cout << "You keyed in " << num << op << denom <<".\n";

}

// Member function to write rational number in the form 2/3 to the keyboard or to a file
void rational::output()
{
    cout << num << "/" << denom;
}

// Adds rational and returns value
rational rational::add(rational x)
{
    rational y(num,denom);
    num = x.num*y.denom + y.num*x.denom;
    denom = x.denom*y.denom;
    rational z(num, denom);
    y.output();
    cout << " + ";
    x.output();
    cout << " = ";
    z.output();
    cout << "\n";
    return z;
}

// Subtracts rationals and returns value
rational rational::sub(rational x)
{
    rational y(num,denom);
    num = x.num*y.denom - y.num*x.denom;
    denom = x.denom*y.denom;
    rational z(num, denom);
    y.output();
    cout << " - ";
    x.output();
    cout << " = ";
    z.output();
    cout << "\n";
    return z;

}

// Multiplies rationals and returns value
rational rational::mul(rational x)
{
    rational y(num,denom);
    num = x.num*y.num;
    denom = x.denom*y.denom;
    rational z(num, denom);
    y.output();
    cout << " * ";
    x.output();
    cout << " = ";
    z.output();
    cout << "\n";
    return z;

}

// Divides rationals and returns value
rational rational::div(rational x)
{
    rational y(num,denom);
    num = x.num*y.denom;
    denom = x.denom*y.num;
    rational z(num, denom);
    y.output();
    cout << " / ";
    x.output();
    cout << " = ";
    z.output();
    cout << "\n";
    return z;

}

// Returns negative
rational rational::neg()
{
    num = 0-num;
    rational z(num,denom);
    return z;
}

// Less than operator, returns bool value
bool rational::less(rational x)
{
    rational y(num,denom);
    return (y.num*x.denom) < (y.denom*x.num);
}

void getInput()
{
    rational one(1);
    rational two(1);
           one.input();
           two.input();
           cout << "\n";
           if(one.less(two))
           {
               one.output();
               cout << " is less than ";
               two.output();
               cout<<".\n";
           }
           else
           {
               two.output();
               cout << "is less than";
               one.output();
               cout<< "\n";
           }
           rational temp1 = one;
           rational temp2 = two;
           one.add(two);
           one = temp1;
           two = temp2;
           one.sub(two);
           one = temp1;
           two = temp2;
           one.mul(two);
           one = temp1;
           two = temp2;
           one.div(two);
           one = temp1;
           two = temp2;
           one.neg();
           cout << "First fraction is now negative: ";
           one.output();
           two.neg();
           cout << "\nSecond fraction is now negative: ";
           two.output();
 }

