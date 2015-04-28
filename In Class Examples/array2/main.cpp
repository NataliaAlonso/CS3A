#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

void welcome(int &qty, int &maxNum);
void initialize(int *numbers, int qty, int maxNum);
void sort(int numbers[], int qty);
void print(int numbers[], char *s, int qty, int maxNum);
void statistics(int numbers[], int qty);
double average(int *numbers, int qty);
double median(int numbers[], int qty);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int qty, maxNum, *numbers;
    srand(time(NULL)); // Seed the random number generator
    welcome(qty, maxNum);
    //numbers = (int *)malloc(qty*sizeof(int));
    numbers = new int[qty];
    //int numbers[qty];
    initialize(numbers, qty, maxNum);
   // print(numbers, "unsorted",qty, maxNum);
    sort(numbers,qty);
   // print(numbers, "sorted", qty, maxNum);
    statistics(numbers, qty);
    //free(numbers); -> if you used malloc
    delete [] numbers;// if you used new
    //Nothing needed -- done automatically when program ends
    return a.exec();
}


void welcome(int &qty, int &maxNum)
{
    cout<<"This program will generate a user specified amount of random numbers"<<endl
        <<"and then compute some basic statistics on that set of numbers"<<endl<<endl
        <<endl
       <<"How many random numbers do you wish: ";
    cin>>qty;
    cout<<"What is the largest random number you wish to see: ";
    cin>>maxNum;
}

void initialize(int *numbers, int qty, int maxNum)
{
    for(int i = 0; i < qty; i++)
        numbers[i] = rand()%(maxNum + 1);
}

void sort(int numbers[], int qty)
{
    for(int i = 0; i < qty; i++)
      for(int j = 0; j < qty; j++)
          if(*(numbers + i) < numbers[j])
          {
              int temp = numbers[j];
              *(numbers + j) = *(numbers + i);
              numbers[i] = temp;
          }
}

void print(int numbers[], char *s, int qty, int maxNum)
{
    int colWidth = (int)(log10((double)maxNum) + 1) + 2,
        numCol = 80 / colWidth,
        i = 0;
  //int colWidth = static_cast<int>(log10(qty) + 1) + 2);
    cout<<"The "<<s<<" numbers of numbers is:";
    for(; i < qty; i++)
    {
        if(!(i%numCol))
            cout<<endl;
        /*The above is the same as
          if(i%numCol == 0)
            cout<<endl;
        */
        cout<<setw(colWidth)<<*(numbers+i);
    }
    if((i%numCol))
        cout<<endl<<endl;
    else
        cout<<endl;
}

void statistics(int numbers[], int qty)
{
    cout<<"Statistics:"<<endl
        <<setw(9)<<right<<"Max: "<<numbers[qty-1]<<endl
        <<setw(9)<<right<<"Min: "<<numbers[0]<<endl
        <<setw(9)<<right<<"Average: "<<setprecision(3)<<average(numbers, qty)<<endl
       <<setw(9)<<right<<"Median: "<<median(numbers, qty)<<endl;
}

double average(int *numbers, int qty)
{
    double sum = 0;
    for(int i = 0; i < qty; i ++)
        sum += numbers[i];
    return sum / qty;
}

double median(int numbers[], int qty)
{
    return (qty%2) ?
                (numbers[qty/2-1] + numbers[qty/2])/2.
                    :
                numbers[qty/2];
    /*
      The above is the same as
      if(qty%2)
         return (numbers[qty/2-1] + numbers[qty/2])/2.;
      else
         return numbers[qty/2];
    */
}
