
#include <iostream>
#include <cstdlib>
#include <string>
#include "parser.h"


using namespace std;

int main()
{

    parser list;
    string line, rpnLine;
    vector<string> items;
    do
    {
          cout<<"Line: ";
          getline(cin, line);
          list << line;
          list >> items;
          list >> rpnLine;
          cout<<"You had "<<items.size()<<" items on your line and they are: "<<endl;
          for(int i = 0; i < items.size(); i++)
              cout<<items[i]<<endl;
          cout<<"The line in RPN is: "<<rpnLine<<endl;


    }while(line != "");

}
