#include <QTCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include "node.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    node porsche, datsun;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        porsche.print();
        datsun.print();
        porsche.move();
        datsun.move();


    return a.exec();
}
