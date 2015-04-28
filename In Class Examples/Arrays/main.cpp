// Create an array with 100 random numbers
// Sort random numbers
// Print before and after sort
// Find mean, std. dev., min, max, etc.

#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime> // To generate random numbers
#include <cmath> // Include math operations
#include <iomanip>
#include <sstream> // String Stream, converts sig. figs. quickly

#define QTY 100 // Wherever I see "QTY", replace with 100

/*
#define PI 4*atan(1.); // "." after integer means floating point, ensures integer value
*/

using namespace std;

void welcome();
void intialize(int *list); // Pointers and arrays are the same
void sort( int list[]);
void print(int list[], char *s); //When you pass a string through a pointer, it gives address
void statistics(int numbers[]); //Because it is 1 dimensional, does not need size
double average(int *list);
double median(int list[]);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int numbers[QTY]; // Creates integer array with QTY amount of numbers
    srand(time(NULL)); // Seed the random generator
    welcome();
    intialize(numbers);
        print(numbers,"unsorted");
    sort(numbers);
        print(numbers,"sorted");
    statistics(numbers);
    return a.exec();
}

void welcome()
{
    cout<<"This program will generate "<<QTY<<" random numbers"<<endl
        <<"and then compute some basic statistics on that set."<<endl<<endl;
}

void intialize(int *list) // Pointers and arrays are the same
{
    for(int i = 0; i < QTY; i++)
        list[i] = rand()%(QTY + 1);
}

void sort( int list[])
{
    for(int i = 0; i < QTY; i++ )
    for(int j = 0; j < QTY; j++ )
        if(*(list+i) < list[j] ) // Both mean the same thing with different variables.
        {
             int temp = list[j];
             *(list+j) = *(list+i);
             list[i] = temp;
        }
}
void print(int list[], char* s) //Will print until reaches nullspace
{
    int colWidth = (int)(log10(QTY) + 1 )+ 2,
        numCol = 80 / colWidth; // It is an int because it can't be fractional.
        int i = 0;
    //int colWidth = static_cast<int>(log10(QTY) + 1) + 2; This is the older method.
    cout<<"The "<<s<<" list of numbers is:"<<endl;
    for(; i < QTY; i++)
    {
        if(!(i%numCol))
            cout<<endl; //If not 0, then end line.
        /*The above line is the same as
          if(i%numCol == 0)
          cout<<endl;*/
        // Skips comparison step, more efficient
        cout<<setw(colWidth)<<*(list+i);
    }
    if((i%numCol)) // Checks where reached end of window.
        cout<<endl<<endl;
    else
        cout<<endl;
}

void statistics(int numbers[]) //Because it is 1 dimensional, does not need size
{
    cout<<"Statistics"<<endl
        <<setw(9)<<right<<"Max: "<<numbers[QTY-1]<<endl
        <<setw(9)<<right<<"Min: "<<numbers[0]<<endl
        <<setw(9)<<right<<"Average: "<<setprecision(3)<<average(numbers)<<endl
        <<setw(9)<<right<<"Median: "<<median(numbers)<<endl;
}

double average(int *list)
{
    double sum=0;
    for(int i = 0; i < QTY; i++)
        sum += list [i];
    return sum / QTY;
}

double median(int list[])
{
    return (QTY%2) ?
            list[QTY/2] + list[(QTY/2)-1]/2.
                :
            list [QTY/2];

    /*
        The above is the same as
        if (
        */
}
