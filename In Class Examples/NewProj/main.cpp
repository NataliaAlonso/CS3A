#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

void display(int a, int b, int *ptrA, int *ptrB);

int main(int argc, char *argv[])
{
    QCoreApplication a1(argc, argv);
    int a = 4, b = 5, *ptrA, *ptrB;
    ptrA = &a;
    ptrB = &b;
    display(a, b, ptrA, ptrB);
    display(*ptrA, *ptrB, ptrA, ptrB);
    *ptrA=23;
    *ptrB=*ptrA % a; /* % gives remaining integer in division (mod) */
    display(a, b, ptrA, ptrB);
    ptrB++;
    *ptrB=3;
    ptrB--;
    display(a, b, ptrA, ptrB);

    return a1.exec();
}


void display(int a, int b, int *ptrA, int *ptrB)
{
printf(" a=%d b=%d ptrA=%p ptrB=%p\n", a, b, ptrA, ptrB); /*look up display commands*/
}
