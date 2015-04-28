#include "fraction.h"

fraction::fraction(int n, int d)
{
    num = n;
    denom = d;
    while(1)
        if(denom == 0)
        {
            cout<<"Zero denominator found. Illegal fraction. Please re-enter.";
            cout<<"Numerator: ";
            cin>>num;
            cout<<"Denominator: ";
            cin>>denom;
        }
        else
            break;
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

void fraction::setValue(int n, int d)
{
    num = n;
    denom = d;
    reduce();
}

fraction::fraction(const fraction& other)
{
    num = other.num;
    denom = other.denom;
}

void fraction::getValue()
{
    cin>>num;
    cout<<"Denominator: ";
    cin>>denom;
    reduce();
}

fraction& fraction::operator=(const fraction &other)
{
    if(this != &other)
    {
        num = other.num;
        denom = other.denom;
        reduce();
    }
    return *this;
}

fraction fraction::operator-()
{
    fraction z = fraction(-num,denom);
    return z;
}

void fraction::add(fraction &x, fraction &y)
{
    num = x.num*y.denom + x.denom*y.num;
    denom = x.denom*y.denom;
    reduce();
}

void fraction::display()
{
    cout<<num<<"/"<<denom;
}

void fraction::reduce()
{
    int div = gcd(num, denom);
    num /= div;
    denom /= div;
    if(denom < 0)
    {
        num *= -1;
        denom *= -1;
    }
}


void fraction::addToMe(fraction &other)
{
    num = num*other.denom + other.num*denom;
    denom = denom *
            other.denom;
    reduce();
}

void fraction::operator+=(fraction &other)
{
    addToMe(other);
}

int fraction::gcd(int p, int q)
{
    return (q == 0) ? p : gcd(q, p%q);
}



istream& operator>>(istream &in, fraction& x)
{
    char junk;
    in>>x.num>>junk>>x.denom;
    //   3     /      4
    x.reduce();
    return in;
}


ostream& operator<<(ostream& out, fraction& x)
{
    out<<x.num<<"/"<<x.denom;
    return out;
}


fraction& operator+(fraction& x, fraction &y)
{
   int num = x.num * y.denom + y.num*x.denom,
       denom = x.denom * y.denom;
   fraction z = fraction(num, denom);
   return z;
}

fraction& operator-(fraction& x, fraction &y)
{
    int num = x.num * y.denom - y.num*x.denom,
        denom = x.denom * y.denom;
    fraction z = fraction(num, denom);
    return z;
}


fraction& operator*(fraction& x, fraction &y)
{
    int num = x.num * y.num,
        denom = y.denom * x.denom;
    fraction z = fraction(num, denom);
    return z;

}


fraction& operator/(fraction& x, fraction &y)
{
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    fraction z = fraction(num, denom);
    return z;

}



bool operator==(fraction& x, fraction &y)
{
    return x.num * y.denom == x.denom*y.num;
}


bool operator>(fraction& x, fraction &y)
{
    return x.num * y.denom > x.denom*y.num;
}



bool operator<(fraction& x, fraction &y)
{
    return x.num * y.denom < x.denom*y.num;
}



bool operator!=(fraction& x, fraction &y)
{
    return !(x == y);
}



bool operator>=(fraction& x, fraction &y)
{
    return !(x < y);
}

bool operator<=(fraction& x, fraction &y)
{
    return !(x > y);
}


