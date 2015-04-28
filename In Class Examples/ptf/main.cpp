#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int* intPtr;

typedef void (*fptr)();

void one();
void two();
void execute(fptr what);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    fptr first, second;
    first = one;
    second = two;
    execute(first);
    execute(second);
    return a.exec();
}


void one()
{
    cout<<"This is function one"<<endl;
}

void two()
{
    cout<<"This is function two"<<endl;
}
\
void execute(fptr what)
{
    what();
}
