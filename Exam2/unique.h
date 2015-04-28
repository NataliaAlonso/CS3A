#ifndef UNIQUE_H
#define UNIQUE_H
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

template <typename T>
class unique
{
    public:
        unique();
        ~unique();

        unique(const unique<T> &other);
        unique<T>& operator=(const unique<T> &other);

        void addToMap( T x, int y );    // Adds new value to map
        void incrementValue( T x );     // Increments the value at key x
        bool searchKey( T x );          // Searches for key x
        void displayAscending();        // Display map ascending
        void displayDescending();       // Display map descending

        template<typename R>
        friend
        ostream& operator<<(ostream &out, unique<R> &uniqueText); // Output

        template<typename R>
        friend
        istream& operator>>(istream &in, unique<R> &uniqueText); // Input

        map<T,int> index;               // Map member variable
        vector<T> elements;             // Template vector elements (string, char, int, double)
        vector<int> totals;             // Int vector for tallies
};

#endif // UNIQUE_H

template <typename T>
unique<T>::unique()
{
    index.clear();
}

template <typename T>
unique<T>::~unique()
{

}

template <typename T>
unique<T>::unique(const unique<T> &other)       // Copy constructor
{
    index = other.index;
}

template <typename T>
unique<T>& unique<T>::operator=(const unique<T> &other) // Assignment operator
{
    index.clear();
    index = other.index;
    return *this;
}


template <typename T>
void unique<T>::addToMap( T x, int y )              // Function: add element to mad
{
    typename map<T,int>::iterator it;
    pair<typename map<T,int>::iterator,bool> ret;
    ret = index.insert( pair<T,int>(x,y) );
    if ( ret.second == false )                      // Check if element is already in map
    {                                               // If yes, increment value
        incrementValue(x);
    }
}


template <typename T>
void unique<T>::incrementValue( T x )               // Increment value at key
{
    int count = index[x];
    count++;
    index[x] = count;
}


template <typename T>
bool unique<T>::searchKey( T x )                    // Search for key
{
    return index.find(x) != index.end();
}


template<typename R>
ostream& operator<<(ostream &out, unique<R> &uniqueText)    // Output
{
    typename map<R,int>::iterator it;
    for(it = uniqueText.index.begin() ; it != uniqueText.index.end(); it++)
        out << it->first << "  " << it->second << endl;
    return out;
}


template<typename R>
istream& operator>>(istream &in, unique<R> &uniqueText)     // Input
{
    R index;
    while(in>>index)
    {
        uniqueText.index(index);
    }
    return in;
}

template<typename T>
void unique<T>::displayAscending()                      // Display map elements ascending
{
    ofstream outfile ("output.txt");                    // Create ouput file
    outfile << setw(8) << "Qty" << ": " << "Element"<<endl<<endl;
    typename map<T,int>::iterator it;                   // Create iterator
    for(it = index.begin() ; it != index.end(); it++)   // Iterate through map
        outfile << setw(8) << it->second << ": " << it->first << endl << endl;
    outfile.close();                                    // Close file
    system("start output.txt");                         // Open file for user
}

template<typename T>
void unique<T>::displayDescending()                     // Display map elements descending
{
    ofstream outfile ("output.txt");                    // Create output file
    outfile << setw(8) << "Qty" << ": " << "Element"<<endl<<endl;
    typename map<T,int>::reverse_iterator rit;          // Create iterator
    for(rit = index.rbegin() ; rit != index.rend(); rit++) // Iterate through map
        outfile << setw(8) << rit->second << ": " << rit->first << endl << endl;
    outfile.close();                                    // Close file
    system("start output.txt");                         // Open file for user
}
