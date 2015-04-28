#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "mystuff.h"

using namespace std;
using namespace french;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    hello();
    english::slang::goodbye();
    return a.exec();
}
