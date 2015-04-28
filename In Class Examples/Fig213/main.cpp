#include <iostream>
#include <QtCore/QCoreApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int number1, number2;

    cout << "Enter two intergers to compare: ";
    cin >> number1 >> number2;

    if ( number1 == number2 )
        cout << number1 << " == " << number2 << endl;
    if ( number1 != number2 )
        cout << number1 << " != " << number2 << endl;
    if ( number1 < number2 )
        cout << number1 << " < " << number2 << endl;
    if (number1 > number2 )
        cout << number1 << " > " << number2 << endl;
    if ( number1 <= number2 )
        cout << number1 << " <= " << number2 << endl;
    if ( number1 >= number2 )
        cout << number1 << " >= " << number2 << endl;

}
