#include <QtCore/QCoreApplication>
// using stringstream constructors.
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int val;
    stringstream ss (stringstream::in | stringstream::out);

    ss << "120 42 377 6 5 2000";

    for (int n=0; n<6; n++)
    {
      ss >> val;
      cout << val*2 << endl;
    }
    return a.exec();
}
