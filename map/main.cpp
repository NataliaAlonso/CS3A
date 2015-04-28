#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "map.h"

using namespace std;

void display(map<string, int> myMap[], int current);
void pick(int &current);
void check(int current);
void insert(map<string, int> myMap[], int current);
void swap(map<string, int> myMap[]);
void find(map<string, int> myMap[],  int current);
void clear(map<string, int> myMap[], int current);
void erase(map<string, int> myMap[], int current);
char menu();
void changeValue(map<string, int> myMap, int current);
void perform(map<string, int> myMap[], char item, int &current);
void replace(map<string, int> myMap[], int current);

int main()
{

    map<string, int> myMap[2];
    int current = 0;//Current array index
    while(1)
        perform(myMap, menu(), current);
}

void display(map<string, int> myMap[], int current)
{
    cout<<"Current map is Map "<<current+1<<endl
        <<"Values are: "<<endl;
    cout<<myMap[current]<<endl;

}

void replace(map<string, int> myMap[], int current)
{
   myMap[current] = myMap[(current+1)%2];
}

void pick(int &current)
{
    while(1)
        try
        {
          cout<<"Was using map "<<current+1<<endl;
          cout<<"Which map do you wish to use (1 or 2): ";
          cin>>current;
          check(current--);
          cout<<" Now using map "<<current+1<<endl;
          return;
        }
        catch(int e)
        {
            cout<<"Invalid list selected. Please try again"<<endl;
        }
}

void check(int current)
{
    if(current < 1 || current > 2)
        throw current;
}

void insert(map<string, int> myMap[], int current)
{
    string index;
    int value;
    cout<<"New index: ";
    cin>>index;
    cout<<"New value: ";
    cin>>value;
    myMap[current].insert(index,value);
}

void changeValue(map<string, int> myMap[], int current)
{
    string index;
    cout<<"Which index's value do you wish to change: ";
    cin>>index;
    if(myMap[current].find(index))
    {
        cout<<"Please enter a new value: ";
        cin>>myMap[current][index];
    }
    else
        cout<<"That index was not found"<<endl;
}

void swap(map<string, int> myMap[])
{
    myMap[1].swap(myMap[2]);
}

void find(map<string, int> myMap[],  int current)
{
    string index;
    cout<<"Index to check: ";
    cin>>index;
    if(myMap[current].find(index))
    {
        cout<<index<<" has a value of "<<myMap[current][index]<<endl;
    }
    else
        cout<<index<<" is not a current index in this map"<<endl;
}

void clear(map<string, int> myMap[], int current)
{
    myMap[current].clear();
}

void erase(map<string, int> myMap[],  int current)
{
    string index;
    cout<<"Which index do you wish to erase: ";
    cin>>index;
    myMap[current].erase(index);
}

char menu()
{
    string input;
    system("cls");
    fflush(stdin);
    cout<<endl<<endl
        <<"Map program options"<<endl
        <<"  I : insert"<<endl
        <<"  S : swap"<<endl
        <<"  F : find"<<endl
        <<"  C : clear"<<endl
        <<"  E : erase"<<endl
        <<"  R : replace current list witih the other list"<<endl
        <<"  P : pick current map"<<endl
        <<"  D : display current map and contents"<<endl
        <<"  Q : quit"<<endl
        <<"Please enter your selection: ";
    getline(cin, input);
    return tolower(input[0]);
}

void perform(map<string, int> myMap[], char item, int &current)
{
    system("cls");
    switch(item)
    {
       case 'i' : insert(myMap, current);
                  break;

       case 's' : swap(myMap);
                  break;

       case 'c' : clear(myMap, current);
                  break;

       case 'f' : find(myMap, current);
                  break;

       case 'e' : erase(myMap, current);
                  break;

       case 'r' : replace(myMap, current);
                  break;

       case 'p' : pick(current);
                  break;

       case 'd' : display(myMap, current);
                  break;

       case 'q' : exit(0);
    }
    system("pause");
}
