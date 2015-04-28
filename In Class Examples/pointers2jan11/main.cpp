
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip> // manipulations

using namespace std;

typedef int* intPtr;

typedef void (*fptr)();

void one();
void two();
void execute(fptr what);

int main()
{
    execute(one);
    execute(two);

}

void one()
{
    cout << "This is function one" << endl;
}


void two()
 {
     cout << "This is function two" << endl;
 }

void execute(fptr what)
{

}
