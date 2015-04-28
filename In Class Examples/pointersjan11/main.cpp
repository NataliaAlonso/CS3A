#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip> // manipulations

using namespace std;

void swap1(int* &a, int* &b); //pass a pointer by reference
void swap2(int ** a, int ** b); //old school pass a pointer by pointer
// above can be written as " int** a ", pointer to a pointer
void swap3(int ** a, int ** b);
void print(char *s,int a, int b, int* ptrA, int* ptrB);


int main()
{
   int a = 3, b = 4, *ptrA = &a, *ptrB = &b;
   print("before swap 1",a,b,ptrA,ptrB);
   swap1(ptrA,ptrB);
   print("after swap 1",a,b,ptrA,ptrB);
   swap2(&ptrB,&ptrA); //data types must correspond; address of a pointer
   print("after swap 2",a,b,ptrA,ptrB);
   swap3(&ptrA,&ptrB);
   print("after swap 3",a,b,ptrA,ptrB);
}

void swap1(int* &a, int* &b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int ** a, int ** b)
{
    int * temp = *a;
    *a = *b;
    *b = temp;
}

void swap3( int** a, int** b )
{
    int * temp = *a;
    *a = *b;
    *b = temp;
}

void print (char *s, int a, int b, int *ptrA, int *ptrB)
{
    cout << s << " a= " << a << " b= " << b
         << " ptrA= " << ptrA << " ptrB= " << ptrB << endl;
}
