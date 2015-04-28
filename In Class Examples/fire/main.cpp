#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>


using namespace std;

typedef void (*fptr)();

void initialize(fptr list[]);
char getInput();
void perform(char a, fptr list[]);
void nothing();
void doA();
void doB();
void doC();
void doD();
void doE();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    fptr whatToDo[128];
    initialize(whatToDo);
    while(1)
        perform(getInput(),whatToDo);
    return a.exec();
}


void initialize(fptr list[])
{
    for(int i = 0; i < 128; i++)
        list[i] = nothing;
    list[65] = doA;
    list[66] = doB;
    list[67] = doC;
    list[68] = doD;
    list[69] = doE;
}

void doA()
{
    cout<<"I am doing what A wants to do"<<endl;
}

void doB()
{
    cout<<"I am doing what B wants to do"<<endl;

}

void doC()
{
    cout<<"I am doing what C wants to do"<<endl;

}

void doD()
{
    cout<<"I am doing what D wants to do"<<endl;

}

void doE()
{
    exit(0);
}





getInput()
{
    char input;
    cout<<"Please give me a key: ";
    cin>>input;
    return input;
}

void perform(char a, fptr list[])
{
    (list[a])();
}

void nothing()
{

}
