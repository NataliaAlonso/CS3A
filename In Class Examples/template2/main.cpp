#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;


template<typename T>
void execute(T func);

void hello();
void goodbye();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    execute(hello);
    execute(goodbye);
    return a.exec();
}

void hello()
{
    cout<<"Hello!"<<endl;
}

void goodbye()
{
    cout<<"Goodbye"<<endl;
}

template<typename T>
void execute(T func)
{
    func();
}
