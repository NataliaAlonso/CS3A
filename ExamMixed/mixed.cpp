#include "mixed.h"
#include "fraction.h"

mixed::mixed()
{
    whole = 0;
}

mixed::mixed(int w, int n, int d)
{
    whole = w;
    fraction newFrac(n,d);
    frac = newFrac;
    setImproper();
    //cout << whole << endl; // this works
    //cout << frac << endl;
    //cout << improper << endl;
}

mixed::mixed(int w, fraction y)
{
    whole = w;
    fraction newFrac(y.numerator(),y.denominator());
    frac = newFrac;
    setImproper();
    //cout << whole << endl; // this works
    //cout << frac << endl;
    //cout << improper << endl;
}

mixed::~mixed()
{}

mixed::mixed(mixed &other) // removed const
{
    whole = other.whole;
    frac = other.frac;
    setImproper();
}

mixed::mixed(fraction &other) //removed const
{
    whole = 0;
    frac = other;
    //setImproper();
}

mixed& mixed::operator=(mixed &other)
{
    if(this != &other)
    {
        whole = other.whole;
        frac = other.frac;
        setImproper();
    }
    return *this;
}

mixed& mixed::operator=(fraction &other)
{
    frac = other;
    whole =abs(frac.numerator())/frac.denominator();
    whole *=(frac.numerator() < 0)? -1 : 1;
    frac.numerator() = abs(frac.numerator())%frac.denominator();
    frac.reduce();
    setImproper();
    return *this;
}


void mixed::setValue(int w, int n, int d)
{
    whole = w;
    fraction y(n,d);
    frac = y;
    //frac.setValue(n,d);
    setImproper();
}

void mixed::setValue(int w, fraction& y)
{
    whole = w;
    frac = y;
    setImproper();
}

fraction& mixed::getFraction()
{
    return improper;
}

void mixed::setImproper()
{
    int num = (abs(whole)*abs(frac.denominator())) + frac.numerator(); // changed from numerator() to num.
    num *= ((whole < 0) ? -1 : 1);
    fraction y(num, frac.denominator());
    improper = y;
    //cout << improper << "\n"; improper works correctly
    //improper.setValue(num, frac.denominator());
}

//I/O friends

istream& operator>>(istream &in, mixed &x)
{
    int w;
    fraction y;
    in>>w>>y;
    x.setValue(w,y);
    return in;
}


ostream& operator<<(ostream &out, mixed &x)
{
    out<<x.whole<<" "<<x.frac;
    return out;
}

//Friends that deal with two mixed numbers

mixed& operator+(mixed& x, mixed &y)
{
    mixed ans((x.improper + y.improper));
   // fraction ans = x.improper + y.improper;
    return ans;

}


mixed& operator/(mixed& x, mixed &y)
{
    mixed ans((x.improper / y.improper));
   // mixed ans = x.improper / y.improper;
   return ans;

}

mixed& operator*(mixed& x, mixed &y)
{
    mixed ans((x.improper * y.improper));
   //mixed ans = x.improper * y.improper;
   return ans;

}

mixed& operator-(mixed& x, mixed &y)
{
    mixed ans((x.improper - y.improper));
   // mixed ans = x.improper - y.improper;
   return ans;

}

bool operator<(mixed& x, mixed &y)
{
   return x.improper < y.improper;
}

bool operator>(mixed& x, mixed &y)
{
   return x.improper > y.improper;
}

bool operator!=(mixed& x, mixed &y)
{
   return  x.improper != y.improper;
}

bool operator==(mixed& x, mixed &y)
{
   return x.improper == y.improper;
}


bool operator>=(mixed& x, mixed &y)
{
   return x.improper >= y.improper;
}

bool operator<=(mixed& x, mixed &y)
{
   return x.improper <= y.improper;
}
//Friends that deal with a fraction and a mixed number

mixed& operator+(fraction &x, mixed &y)
{
    mixed ans((x + y.improper));
    // mixed ans = x + y.improper;
    return ans;
}


mixed& operator/(fraction &x, mixed &y)
{
    mixed ans((x / y.improper));
    // mixed ans = x / y.improper;
    return ans;
}

mixed& operator*(fraction &x, mixed &y)
{
    mixed ans((x * y.improper));
    // mixed ans = x * y.improper;
    return ans;
}

mixed& operator-(fraction &x, mixed &y)
{
    mixed ans((x - y.improper));
    //mixed ans = x - y.improper;
    return ans;
}

bool operator<(fraction &x, mixed &y)
{
    return x < y.improper;
}


bool operator>(fraction &x, mixed &y)
{
    return x > y.improper;
}


bool operator!=(fraction &x, mixed &y)
{
    return x != y.improper;
}


bool operator==(fraction &x, mixed &y)
{
    return x == y.improper;
}



bool operator>=(fraction &x, mixed &y)
{
    return x >= y.improper;
}



bool operator<=(fraction &x, mixed &y)
{
    return x <= y.improper;
}



//Friendss that deal with a mixed and a fraction

mixed& operator+(mixed& x, fraction &y)
{
    mixed ans((x.improper + y));
    //mixed ans = x.improper + y;
    return ans;
}


mixed& operator/(mixed& x, fraction &y)
{
    mixed ans((x.improper + y));
    //mixed ans = x.improper / y;
    return ans;
}


mixed& operator*(mixed& x, fraction &y)
{
    mixed ans((x.improper * y));
    //mixed ans = x.improper * y;
    return ans;
}


mixed& operator-(mixed& x, fraction &y)
{
    mixed ans((x.improper + y ));
    //mixed ans = x.improper - y;
    return ans;
}


bool operator<(mixed& x, fraction &y)
{
    return x.improper < y;
}


bool operator>(mixed& x, fraction &y)
{
    return x.improper > y;
}


bool operator!=(mixed& x, fraction &y)
{
    return x.improper != y;
}

bool operator==(mixed& x, fraction &y)
{
    return x.improper == y;
}
bool operator>=(mixed& x, fraction &y)
{
    return x.improper >= y;
}
bool operator<=(mixed& x, fraction &y)
{
    return x.improper <= y;
}
