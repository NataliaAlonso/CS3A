#ifndef FRACTION_H
#define FRACTION_H


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class fraction
{
  public:
//      fraction();
      fraction(int n = 0, int d = 1);
      ~fraction();
      fraction(const fraction& other);
      fraction& operator=(fraction &other);

      void getValue();
      int& numerator();
      int& denominator();

      void display();
      void add(fraction &x, fraction &y);
      void addToMe(fraction &other);
      void operator+=(fraction &other);//x.addToMe(y);
      fraction operator-();

      friend
      istream& operator>>(istream &in, fraction& x);

      friend
      ostream& operator<<(ostream& out, fraction& x);

      friend
      fraction& operator+(fraction& x, fraction &y);

      friend
      fraction& operator-(fraction& x, fraction &y);

      friend
      fraction& operator*(fraction& x, fraction &y);

      friend
      fraction& operator/(fraction& x, fraction &y);

      friend
      bool operator==(fraction& x, fraction &y);

      friend
      bool operator>(fraction& x, fraction &y);

      friend
      bool operator<(fraction& x, fraction &y);

      friend
      bool operator!=(fraction& x, fraction &y);

      friend
      bool operator>=(fraction& x, fraction &y);

      friend
      bool operator<=(fraction& x, fraction &y);


private:
      int num, denom;

      void reduce();
      int gcd(int p, int q);
};

#endif // FRACTION_H
