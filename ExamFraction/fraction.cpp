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

fraction::fraction(const fraction& other)
{
    num = other.num;
    denom = other.denom;
}

void fraction::getValue()
{
    cout<<"Numerator: ";
    cin>>num;
    cout<<"Denominator: ";
    cin>>denom;
    reduce();
}

fraction& fraction::operator=(fraction &other)
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
    num = 0-num;
    return fraction(num,denom);
}

void fraction::add(fraction &x, fraction &y)
{
    num = x.num*y.denom + x.denom*y.num;
    denom = x.denom*y.denom;
    reduce();
}

void fraction::display()
{
    if ( num == denom && denom != 1)
        cout << "1";
    if ( denom = 1 )
        cout << num;
    if ( denom != 1 && num!=denom)
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
    if ( x.denom != 1 && x.num!=x.denom)
        out<<x.num<<"/"<<x.denom;
    else if ( x.num == x.denom && x.denom != 1)
        out << "1";
    else if ( x.denom = 1 )
        out << x.num;

    return out;
}


fraction& operator+(fraction& x, fraction &y)
{
   int num = x.num * y.denom + y.num*x.denom,
       denom = x.denom * y.denom;
   fraction z(num, denom);
   return z;
}

fraction& operator-(fraction& x, fraction &y)
{
   int num = x.num * y.denom - y.num*x.denom,
       denom = x.denom * y.denom;
   fraction z(num, denom);
   return z;
}


fraction& operator*(fraction& x, fraction &y)
{
    int num = x.num * y.num,
        denom = y.denom * x.denom;
    fraction z(num, denom);
   return z;

}


fraction& operator/(fraction& x, fraction &y)
{
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    fraction z(num, denom);
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

