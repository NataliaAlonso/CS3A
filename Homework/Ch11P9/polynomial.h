#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cstdlib>

using namespace std;

typedef double* ArrayPtr;

class polynomial
{
public:
    // Default constructor
    polynomial();

    // Copy constructor
    polynomial(const polynomial &other);

    // A parameterized constructor that enables an arbitrary polynomial to be constructed
    // Creates a polynomial x^deg, with the coefficient at value ArrayPtr[deg];
    polynomial(ArrayPtr coef, int deg);

    // Destructor
    ~polynomial();

    // Assignment operator
    polynomial& operator=(const polynomial &other);

    // friends to operate on two polynomials
    friend
    polynomial operator+(polynomial& p1,polynomial& p2);

    friend
    polynomial operator-(polynomial& p1,polynomial& p2);

    friend
    polynomial operator*(polynomial& p1,polynomial& p2);

    // friends to operate on one polynomial and one constant
    friend
    polynomial operator+(polynomial& p,double c);

    friend
    polynomial operator-(polynomial& p,double c);

    friend
    polynomial operator*(polynomial& p,double c);

    // friends to operate on one constant and one polynomial
    friend
    polynomial operator+(double c,polynomial& p);

    friend
    polynomial operator-(double c,polynomial& p);

    friend
    polynomial operator*(double c,polynomial& p);

    void display();


private:

    // coefficient[i] is the coefficient of x^i;
    ArrayPtr coefficient;

    // Degree of the polynomial
    int degree;
};

#endif // POLYNOMIAL_H
