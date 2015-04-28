#include "Fraction.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void getFraction(char *s, fraction& x);

int main()
{
    fraction x, y, z;
    getFraction("First", x);
    getFraction("Second", y);
    z.add(x,y);
    cout << "The result of ";
    x.display();
    cout << " + ";
    y.display();
    cout << "is ";
    z.display();
    cout << endl;



}

void getFraction(char *s, fraction& x)
{
    cout << "Please enter the following for your " << s << " fraction." << endl;
    cout << "Numerator: ";
    cin >> x.numerator();
    cout << "\nDenominator: ";
    cin >> x.denominator();
}
