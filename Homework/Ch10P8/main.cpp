#include <QtCore/QCoreApplication>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <dayofyear.h>
#include <month.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DayOfYear today, bachBirthday;

    cout << "Enter today's date: \n";
    today.input();

    cout << "Today's date is ";
    today.output();

    bachBirthday.set(3,21);

    cout << "J.S. Bach's birthday is ";
    bachBirthday.output();

    if( today.getMonth() == bachBirthday.getMonth() && today.getDay() == bachBirthday.getDay() )
        cout<< "Happy Birthday Johann Sebastian!!";
    else
        cout << "Happy UnBirthday Johann Sebastian!!";

    return a.exec();
}
