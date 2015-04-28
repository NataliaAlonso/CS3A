#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <string>
#include "stack.h"
#include "perform.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    stack<char> characters(256);
    perform(characters);
    return a.exec();
}
