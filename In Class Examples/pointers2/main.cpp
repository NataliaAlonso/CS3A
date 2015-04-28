#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

void swap1(int* &a, int* &b); // pass a pointer by reference
void swap2(int** a, int **b); //"old school pass a pointer by reference
void swap3(int** a, int** b);

void print(char *s, int a, int b, int* ptrA, int* ptrB);

int main(int argc, char *argv[])
{
    QCoreApplication a1(argc, argv);
    int a = 3, b = 4, *ptrA = &a, *ptrB = &b;
    print("Original data",a,b,ptrA,ptrB);
    swap1(ptrA, ptrB);
    print("after swap1 and before swap2",a,b,ptrA,ptrB);
    swap2(&ptrA, &ptrB);
    print("after swap2 and before swap3",a,b,ptrA,ptrB);
    swap3(&ptrA, &ptrB);
    print("after swap3", a,b,ptrA,ptrB);
    return a1.exec();
}

void swap1(int* &a, int* &b) // pass a pointer by reference
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int** a, int **b) // pass a pointer by value
{
    cout<<"starting swap2: **a = "<<a<<" **b = "<<b<<endl;
    int** temp = a;
    a = b;
    b = temp;
    cout<<"ending swap2: **a = "<<a<<" **b = "<<b<<endl;
}

//"old school pass a pointer by reference
void swap3(int** a, int** b)
{
    int** temp = a;
    a = b;
    b = temp;
}

void print(char *s,int a, int b, int* ptrA, int* ptrB)
{
    cout<<s<<":\n"<<" a= "<<a<<" b = "<<b
        <<" ptrA = "<<ptrA<<" ptrB = "<<ptrB
        <<" *ptrA = "<<*ptrA<<" *ptrB = "<<*ptrB<<endl;
}
