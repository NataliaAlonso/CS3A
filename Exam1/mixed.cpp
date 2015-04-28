#include "mixed.h"
#include "fraction.h"
#include <cmath>

mixed::mixed()
{
    whole = 0;
    frac.numerator() = 0;
    frac.denominator() = 1;
}

mixed::mixed(string &x)
{
        whole = 0;
        improper = 0;
        int pos;
        int pos2;
        int numerator=0;
        int denominator=1;
        pos = x.find(" ",0);
        pos2 = x.find("/",0);
        string subs;
        //cout << pos << "\n";
        //cout << pos2 << "\n";
        if (pos == 0 && pos2 == 0)
        {
        whole = atoi(x.c_str());
        //cout << whole << "\n";
        }
        else
            if( pos == -1)
            {
                subs = x.substr(pos+1,pos2);
                numerator = atoi(subs.c_str());
                subs = x.substr(pos2+1,x.length());
                denominator = atoi(subs.c_str());
            }
            else
            {
                subs = x.substr(0,pos);
                whole = atoi(subs.c_str());
                //cout << whole << "\n";
                subs = x.substr(pos+1,pos2);
                numerator = atoi(subs.c_str());
                subs = x.substr(pos2+1,x.length());
                denominator = atoi(subs.c_str());
            }
	fraction newFrac(numerator,denominator);
	frac = newFrac;
	setImproper();
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

mixed::mixed(const mixed &other) // removed const
{
    whole = other.whole;
    fraction x = other.frac;
    frac.numerator() = x.numerator();
    frac.denominator() = x.denominator();
    setImproper();
}

mixed::mixed(const fraction &other) //removed const
{
    whole = 0;
    frac = other;
    setImproper();
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
    whole = abs(frac.numerator())/frac.denominator();
    whole *= (frac.numerator() < 0)? -1 : 1;
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

void mixed::setValue(string x)
{
 whole = 0;
        improper = 0;
        int pos;
        int pos2;
        int numerator=0;
        int denominator=1;
        pos = x.find(" ",0);
        pos2 = x.find("/",0);
        string subs;
        //cout << pos << "\n";
        //cout << pos2 << "\n";
        if (pos == 0 && pos2 == 0)
        {
        whole = atoi(x.c_str());
        //cout << whole << "\n";
        }
        else
            if( pos == -1)
            {
                subs = x.substr(pos+1,pos2);
                numerator = atoi(subs.c_str());
                subs = x.substr(pos2+1,x.length());
                denominator = atoi(subs.c_str());
            }
            else
            {
                subs = x.substr(0,pos);
                whole = atoi(subs.c_str());
                //cout << whole << "\n";
                subs = x.substr(pos+1,pos2);
                numerator = atoi(subs.c_str());
                subs = x.substr(pos2+1,x.length());
                denominator = atoi(subs.c_str());
            }
	fraction newFrac(numerator,denominator);
	frac = newFrac;
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
    //cout << improper << "\n";
    //improper works correctly
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
    out << x.improper << endl;


    //out << x.whole << " " << x.frac;
    //return out;

    /*
    if ( x.whole != 0 && x.frac.denominator() != 1 && x.frac.numerator() != x.frac.denominator())
        out<<x.whole<<" "<<x.frac;
    else if ( x.whole == 0 && x.frac.denominator() != x.frac.numerator() )
	out << x.frac;
    else if ( x.frac.numerator() == x.frac.denominator() && x.frac.denominator() != 1)
        out << (x.whole+1);
    else if ( x.frac.denominator() == 1 )
        out << (x.frac.numerator() + x.whole);
    return out;
    */

    /*if( abs(x.improper.numerator()) > x.improper.denominator() && x.improper.denominator() == 1)
    out << x.improper.numerator();

    else if( abs(x.improper.numerator()) > x.improper.denominator() && x.improper.denominator()!= 1)
        out << x.improper.numerator()/x.improper.denominator() << " " << x.improper.numerator()%x.improper.denominator() << "/" << x.improper.denominator();

        else if (  abs(x.improper.numerator()) == x.improper.denominator() )
        out << x.improper.numerator()/x.improper.denominator();

            else if ( abs(x.improper.numerator()) < x.improper.denominator() )
            out << x.improper.numerator() << "/" << x.improper.denominator(); */

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
