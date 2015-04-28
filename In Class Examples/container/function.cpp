#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;


void perform(stack<char> &characters)
{
    string temp, revline, line;
    while(1)
    {
        temp = revline = "";
        cout<<"Line: ";
        getline(cin, line);
        for(int i = 0; i < line.size(); i++)
        {
            temp += toupper(line[i]);
            characters.push(toupper(line[i]));
        }
        while(!characters.empty())
        {
            revline += characters.top();
            characters.pop();
        }
        cout<<line;
        if(revline == temp)
            cout<<" is a ";
        else
            cout<<" is not a";
        cout<<" palindrome"<<endl;
    }
}
