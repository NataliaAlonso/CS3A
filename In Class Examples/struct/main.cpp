#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));
    node *list[3];
    list[0] = new node("911");
    list[1] = new node("280Z");
    list[2] = new node("F250");
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 3; j++)
          if(list[j] != NULL)
            list[j]->print(); // same as (*list[j]).print();
        int bye = rand()%15;
        if( 0 <= bye && bye < 3)
        {
            delete list[bye];
            list[bye] = NULL;
        }
    }
    return a.exec();
}
