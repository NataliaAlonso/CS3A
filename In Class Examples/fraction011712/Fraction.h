#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstdlib>
#include <fstream>

class fraction
{
public:
    //fraction();
    fraction(int n, int d);
    ~fraction();

    int& numerator();
    int& denominator();

    // add two fractions and return result
    // member method
    void add(fraction &x, fraction& y);

    fraction(const fraction& other);
    fraction& operator=(fraction other);

    void display();
    void addToMe(fraction &other);
    void operator+=(fraction &other);

    // someone who is not a memeber of the class, but has access to private data
    // input stream
    friend istream& operator<<(isteam &in, fraction& x);

    // output stream
    friend ostream& operator>>(ostream &out, fraction& x);

    friend fraction& operator+(fraction& x, fraction &y);

private:
    int num, denom;

    void reduce();
    int gcd(int p, int d);

};

#endif //FRACTION_H
