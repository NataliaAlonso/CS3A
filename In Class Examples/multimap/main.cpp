#include <QtCore/QCoreApplication>
// constructing multimaps
#include <iostream>
#include <map>
using namespace std;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  multimap<char,int> first;
  multimap<char,int> second;

  first.insert(pair<char,int>('x',32));
  first.insert(pair<char,int>('y',64));
  first.insert(pair<char,int>('y',96));
  first.insert(pair<char,int>('z',128));

  second=first;                // second now contains 4 ints
  first=multimap<char,int>();  // and first is now empty

  cout << "Size of first: " << int (first.size()) << endl;
  cout << "Size of second: " << int (second.size()) << endl;
  return a.exec();
}
