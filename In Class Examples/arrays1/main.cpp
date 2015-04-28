#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

#define QTY 100

using namespace std;

void welcome();
void initialize(int *list);
void sort(int list[]);
void print(int list[], char *s);
void statistics(int numbers[]);
double average(int *list);
double median(int list[]);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int numbers[QTY];
    srand(time(NULL)); // Seed the random number generator
    welcome();
    initialize(numbers);
    print(numbers, "unsorted");
    sort(numbers);
    print(numbers, "sorted");
    statistics(numbers);
    return a.exec();
}

void welcome()
{
    cout<<"This program will generate "<<QTY<<" random numbers"<<endl
        <<"and then compute some basic statistics on that set of numbers"<<endl<<endl;
}

void initialize(int *list)
{
    for(int i = 0; i < QTY; i++)
        list[i] = rand()%(QTY + 1);
}

void sort(int list[])
{
    for(int i = 0; i < QTY; i++)
      for(int j = 0; j < QTY; j++)
          if(*(list + i) < list[j])
          {
              int temp = list[j];
              *(list + j) = *(list + i);
              list[i] = temp;
          }
}

void print(int list[], char *s)
{
    int colWidth = (int)(log10((double)QTY) + 1) + 2,
        numCol = 80 / colWidth,
        i = 0;
  //int colWidth = static_cast<int>(log10(QTY) + 1) + 2);
    cout<<"The "<<s<<" list of numbers is:";
    for(; i < QTY; i++)
    {
        if(!(i%numCol))
            cout<<endl;
        /*The above is the same as
          if(i%numCol == 0)
            cout<<endl;
        */
        cout<<setw(colWidth)<<*(list+i);
    }
    if((i%numCol))
        cout<<endl<<endl;
    else
        cout<<endl;
}

void statistics(int numbers[])
{
    cout<<"Statistics:"<<endl
        <<setw(9)<<right<<"Max: "<<numbers[QTY-1]<<endl
        <<setw(9)<<right<<"Min: "<<numbers[0]<<endl
        <<setw(9)<<right<<"Average: "<<setprecision(3)<<average(numbers)<<endl
       <<setw(9)<<right<<"Median: "<<median(numbers)<<endl;
}

double average(int *list)\
{
    double sum = 0;
    for(int i = 0; i < QTY; i ++)
        sum += list[i];
    return sum / QTY;
}

double median(int list[])
{
    return (QTY%2) ?
                (list[QTY/2-1] + list[QTY/2])/2.
                    :
                list[QTY/2];
    /*
      The above is the same as
      if(QTY%2)
         return (list[QTY/2-1] + list[QTY/2])/2.;
      else
         return list[QTY/2];
    */
}
