#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void getSize(int &row, int & col);
void tossCoin(int row, int col, int* table[]);
void print(int row, int col, int* table[]);
void statistics(int row, int col, int** table);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));
    int row, col;
    getSize(row, col);
 //   int table[row][col];

    int** table = new int* [row];
    for(int i = 0; i < row; i++)
        table[i] = new int[col];

    tossCoin(row, col, table);
 //   print( row, col, table);
    statistics(row, col, table);

//    If used the double pointer must
//    do the following:

    for(int i = 0; i < row; i++)
       delete [] table[i];
    delete [] table;

    return a.exec();
}

void getSize(int &row, int & col)
{
    cout<<"How many time do wish to roll a coin per set: ";
    cin>>col;
    cout<<"How many sets do you want: ";
    cin>>row;
}

void tossCoin(int row, int col, int* table[])
{
    for(int i = 0; i < row; i ++)
        for(int j = 0; j < col; j++)
            table[i][j] = rand()%2;
}

void print(int row, int col, int* table[])
{
    cout<<"The results:"<<endl;
    for(int i = 0; i < row; i++)
    {
        cout<<"Set "<<i<<": ";
        for(int j = 0; j < col; j++)
        {
            char result = table[i][j] ? 'H' : 'T';
            cout<<result;
        }
        cout<<endl;
    }
}

void statistics(int row, int col, int** table)
{
    int result[2] = {0,0};
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result[table[i][j]]++;
    cout<<endl
        <<"For your experiment, you had: "<<endl
       <<result[0]<<" tails ("
       <<fixed<<setprecision(6)
       <<(100.*result[0])/(row*col)<<"%)"<<endl
       <<setprecision(6)
       <<result[1]<<" heads ("
       <<(100.*result[1])/(row*col)<<"%)"<<endl;
}
