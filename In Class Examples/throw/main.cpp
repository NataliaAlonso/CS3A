#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

void zero();
void one();
void two();
void three();
void four();

typedef void (*fptr)();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));
    fptr list[5];
    list[0] = zero;
    list[1] = one;
    list[2] = two;
    list[3] = three;
    list[4] = four;
    for(int i = 0; i < 10; i++)
    try
    {
        list[rand()%5]();
    }
    catch(int j)
    {
        cout<<"Error "<<j<<" occurred"<<endl;
    }
    catch(char c)
    {
        cout<<"Caught a character, now rolling the dice";
        try
        {
            list[rand()%5]();
        }
        catch(double d)
        {
            cout<<"Rolled a double"<<endl;
        }
        catch(int i)
        {
            cout<<"Rolled an int"<<endl;
        }
    }
    catch(double d)
    {
        cout<<"Error "<<d<<" occurred"<<endl;
    }
    catch(char *c)
    {
        cout<<"Error "<<c<<" occurred"<<endl;
    }
    catch(...)
    {
        cout<<"An unknown error occurred"<<endl;
    }

    return a.exec();
}

void zero()
{
    string zebra;
    throw zebra;
}

void one()
{
    throw 6;
}

void two()
{
    throw 'C';
}

void three()
{
    throw 3.4;
}

void four()
{
    throw "ERROR";
}

