
#include <iostream>
#include <cstdlib>
#include "polynomial.h"

using namespace std;

int main()
{
    // Coefficient array
    ArrayPtr coef1;
    ArrayPtr coef2;

    // Placeholder polynomial to display results
    polynomial result;
    polynomial p1;
    polynomial p2;

    // Degree of the polynomial
    int deg;

    // Index representing the exponent in a term of the polynomial
    int index;

    // Double constants
    double one = 0;
    double two = 0;

    // Coefficient value
    double c;

    cout << "Entering first polynomial. What is the degree of the polynomial? ";
    cin >> deg;

    if ( deg == 0 )
    {
        cout << "Enter constant value.";
        cin >> one;
    }
    else
    {
        coef1 = new double[deg+1];

        cout << "\nEnter the coefficients of the polynomial from highest degree to lowest.\n"
             << "Hit enter after each value, and key in 0 if x^n is missing. " << endl;
        for ( int i = deg; i >=0; i--)
            cin >> coef1[i];

        polynomial one(coef1,deg);
        p1 = one;
        cout << "\nThe first polynomial is: ";
        one.display();
    }

    cout << "\nEntering second polynomial. What is the degree of the polynomial? ";
    cin >> deg;

    if ( deg == 0 )
    {
        cout << "What is constant value? ";
        cin >> two;
    }
    else
    {
        coef2 = new double[deg+1];

        cout << "Enter the coefficients of the polynomial from highest degree to lowest.\n"
             << "Hit enter after each value, and key in 0 if polynomial is missing. " << endl;
        for (  int i = deg; i >=0; i--)
            cin >> coef2[i];

        polynomial two(coef2,deg);
        p2 = two;
        cout << "\nThe second polynomial is: ";
        two.display();
    }

    cout << "\nAdding both entries.\n";

    if( one == 0 && two == 0)
    {
        result = p1 + p2;
        result.display();
    }
    if( one !=0 )
    {
        result = one + p2;
        result.display();
    }
    if( two != 0 )
    {
        result = p1 + two;
        result.display();
    }

    cout << "\nSubtracting both entries.\n";
    if( one == 0 && two == 0)
    {
        result = p1 - p2;
        result.display();
    }
    if( one !=0 )
    {
        result = one - p2;
        result.display();
    }
    if( two != 0 )
    {
        result = p1 - two;
        result.display();
    }

    cout << "\nMultiplying both entries.\n";
    if( one == 0 && two == 0)
    {
        result = p1 * p2;
        result.display();
    }
    if( one !=0 )
    {
        result = one * p2;
        result.display();
    }
    if( two != 0 )
    {
        result = p1 * two;
        result.display();
    }


}




