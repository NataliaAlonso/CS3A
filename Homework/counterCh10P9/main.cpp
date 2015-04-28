#include <QtCore/QCoreApplication>
#include "counter.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Receives one character and one integer as arguments; char denotes incr1, incr10, incr100, or incr1000. int is multiplier
void getFunction(counter c, char s, int x);

int main()
{
    cout << "Creating a new counter named counter1 with max 9999." << endl;
    char s;
    int n;
    counter counter1(9999);

    cout << "\n\nIn order to increment by x amount, please key in:\n"
         << "Ax for cents, Sx for dimes, Dx for dollars, or Fx for tens of dollars.\n"
         << "Overflow will be displayed after each entry.\n"
         << "You can request overflow by keying in Ox, or reset the counter by keying in Rx.\n" << endl;

    while(cin)
    {
        cout << "\nPlease key in increment: "<<endl;
        cin >> s >> n;
        counter1.getFunction(s,n);
        counter1.display();
    }
}


