#include "polynomial.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Default constructor
polynomial::polynomial()
{
    degree=0;
    coefficient = new double[degree+1];
    coefficient[0] = 0;
}

// Copy constructor
polynomial::polynomial(const polynomial &other)
{
    degree = other.degree;
    coefficient = new double[degree+1];
    for(int i=0; i < degree+1;i++)
        coefficient[i] = other.coefficient[i];
}

// A parameterized constructor that enables an arbitrary polynomial to be constructed
// Creates a polynomial x^deg, with the coefficient at value ArrayPtr[deg]{}
polynomial::polynomial(ArrayPtr coef, int deg)
{
    degree = deg;
    coefficient = new double[degree+1];
    for(int i=0; i < degree+1;i++)
        coefficient[i] = coef[i];
}

// Destructor
polynomial::~polynomial()
{
    delete [] coefficient;
}

// Assignment operator
polynomial& polynomial::operator=(const polynomial &other)
{
    degree = other.degree;
    coefficient = new double[degree+1];
    for(int i=0; i < degree+1;i++)
        coefficient[i] = other.coefficient[i];
    return *this;
}

// Friends to operate on two polynomials

polynomial operator+(polynomial& p1,polynomial& p2)
{
    int operDegree = 0;

    // Find highest degree in equation
    if( p1.degree >= p2.degree )
    {
        operDegree = p1.degree;
    }
    else
    {
        operDegree = p2.degree;
    }

    // New coefficient array to accomodate highest degree
    ArrayPtr operCoef = new double[operDegree+1];

    // Adding coefficients and inserting into array
    for ( int i = 0; i < operDegree+1; i++ )
    {
        operCoef[i] = p1.coefficient[i]+p2.coefficient[i];
    }

    // Creating new polynomial with added coefficients and highest degree
    polynomial z(operCoef,operDegree);
    return z;
}


polynomial operator-(polynomial& p1,polynomial& p2)
{
    int operDegree = 0;

    // Find highest degree in equation
    if(p1.degree >= p2.degree)
        operDegree = p1.degree;
    else
        operDegree = p2.degree;

    // New coefficient array to accomodate highest degree
    ArrayPtr operCoef = new double[operDegree+1];

    // Subtracting coefficients and inserting into array
    for ( int i = 0; i < operDegree+1; i++ )
    {
        operCoef[i] = p1.coefficient[i]-p2.coefficient[i];
    }

    // Creating new polynomial with subtracted coefficients and highest degree
    polynomial z(operCoef,operDegree);
    return z;
}


polynomial operator*(polynomial& p1, polynomial& p2)
{
    // Find highest degree in equation
    int arrayDegree = p1.degree + p2.degree;
    ArrayPtr operCoef = new double[arrayDegree+1];
    for(int i = 0; i < p1.degree+1; i++)
            for(int j = 0; j < p2.degree+1; j++)
                operCoef[i+j] += (p1.coefficient[i] * p2.coefficient[j]);
    // Creating new polynomial with multiplied coefficients and highest degree
    polynomial z(operCoef,arrayDegree);
    return z;
}

// Friends to operate on one polynomial and one constant

polynomial operator+(polynomial& p,double c)
{
    polynomial z(p.coefficient,p.degree);
    z.coefficient[0]+=c;
    return z;
}


polynomial operator-(polynomial& p,double c)
{
    polynomial z(p.coefficient,p.degree);
    z.coefficient[0] = z.coefficient[0] - c;
    return z;
}


polynomial operator*(polynomial& p,double c)
{
    polynomial z(p.coefficient,p.degree);
    int operDegree = p.degree;
    for (int i = 0; i < operDegree+1; i++)
        z.coefficient[i]*=c;
    return z;
}

// Friends to operate on one constant and one polynomial

polynomial operator+(double c,polynomial& p)
{
    polynomial z(p.coefficient,p.degree);
    z.coefficient[0]+=c;
    return z;
}


polynomial operator-(double c,polynomial& p)
{
    polynomial z(p.coefficient,p.degree);
    int operDegree = p.degree;
    z.coefficient[0] = c - z.coefficient[0];
    for ( int i = 1; i < operDegree+1; i++)
        z.coefficient[i] = 0 - z.coefficient[i];
    return z;
}


polynomial operator*(double c,polynomial& p)
{
    polynomial z(p.coefficient,p.degree);
    int operDegree = p.degree;
    for (int i = 0; i < operDegree+1; i++)
       z.coefficient[i]*=c;

    return z;
}

void polynomial::display()
{
        int n = degree;
        double c;  // coefficient
// Print the highest degree term if the polynomial is not constant
        if (n > 0)
                cout << coefficient[n] << "x^" << n;

// Print the remaining non-constant terms
        for (int i = n - 1; i > 0; i--)
        {
                c = coefficient[i];
                if (c > 0)
                        cout << " + " << c << "x^" << i;
                else if (c < 0)
                        cout << " - " << -1*c << "x^" << i;
        }

// Print the constant term
        c = coefficient[0];
        if (n == 0)
                cout << c;
        else if (c > 0)
                cout << " + " << c;
             else if (c < 0)
                cout << " - " << -1*c;
}
