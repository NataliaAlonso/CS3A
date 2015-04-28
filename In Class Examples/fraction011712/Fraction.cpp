#include "Fraction.h"
#include <iostream>
#include <cstdlib>

using namespace std;

fraction::fraction(int n, int d)
{
    num = n;
    denom = d;
    while(1) // do forever
    {
        if(denom == 0)
        {
            cout << "Zero denominator found. Illegal fraction. Please reenter."<<endl;
                    cout << "Numerator: ";
                    cin >> num;
            cout << "Denominator: ";
                    cin >> denom;
        }
        else
            break; // end forever
    }
    reduce();
}

fraction::~fraction()
{}

int& fraction::numerator()
{
    return num;
}

int& fraction::denominator()
{
    return denom;
}

void fraction::add(fraction &x, fraction& y)
{
    // fix
    num = x.num*y.denom+x.denom*y.num;
    denom = x.denom*y.num + x.num*y.denom;
    reduce();
}

void fraction::display()
{
    cout << num << "/" << denom;
}

fraction::fraction(const fraction& other)
{

}

fraction& fraction::operator=(fraction other)
{
    if(this != &other)
    {
        num = other.num;
        denom = other.denom;
        reduce();
    }
    return *this;
}

int fraction::gcd(int p, int d)
    {
     return d == 0 ? p : gcd(d, p%d);
    }

void fraction::reduce()
    {
        int div = gcd(num, denom);
        num /= div;
        denom /= div;
        if(denom < 0)
            num *= -1;
            denom *= -1;
    }

void fraction::addToMe(fraction &other)
{
    //copy this from Prof file
    num = num*other.denom + other.num*denom;
    denom = other.denom;

}

void fraction::operator+=(fraction &other)
{
    addToMe(other);
}

// input stream, not a member of the function
friend istream& operator >>(isteam &in, fraction& x)
{
    char junk;
    in >> x.num >> junk >> x.denom;
    //    number   slash   number
    x.reduce();
    return in;
}

// output stream, not a member of the function
friend ostream& operator << (ostream &out, fraction& x)
{
    out << x.num << "/" << x.denom;
    return out;
}

// results go in new place
friend fraction& operator+(fraction& x, fraction &y)
{
    int num = x.num * y.denom + y.num * x.denom;
    int denom = x.denom * y.denom;
    return fraction(num, denom);
}
