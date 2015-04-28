#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

//template<class T>
template<typename T>
T maxOf(T a, T b);

template<typename T, typename U>
void maximumOf(T a, U b);

template<typename T, typename U, typename V>
void maxiOf(T a, U b, V c);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"The maximum of A and B is: "<<maxOf('A','B')<<endl;
    cout<<"The maximum of 3 and 4 is: "<<maxOf(3,4)<<endl;
    cout<<"The maximum of 3.2 and 2.3 is: "<<maxOf(3.2,2.3)<<endl;
    maximumOf(3,4);
    maximumOf(2.3, 3);
    maximumOf('A',3);
    maximumOf(66,'A');
    maximumOf('A','v');
    maximumOf('A',3.2);
    maxiOf(1,2,3);
    maxiOf('A',55,66.7);
    maxiOf(3.2,2.3,1.2);
    maxiOf(65,'C',67);

    return a.exec();
}



template<typename T>
T maxOf(T a, T b)
{
    return (a > b) ? a : b;
}


template<typename T, typename U>
void maximumOf(T a, U b)
{
    cout<<"The max of "<<a<<" and "<<b<<" is ";
    if(a > b)
        cout<<a<<endl;
    else
        cout<<b<<endl;
}


template<typename T, typename U, typename V>
void maxiOf(T a, U b, V c)
{
    cout<<"The maximum of "<<a<<", "<<b<<" and "<<c<<" is: ";
    if(a > b)
        if(a > c)
            cout<<a<<endl;
        else
            if(b>c)
                cout<<b<<endl;
            else
                cout<<c<<endl;
    else
        if(b > c)
            cout<<b<<endl;
        else
            if(a > c)
                cout<<a<<endl;
            else
                cout<<c<<endl;
}
