#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    stack<char> characters;
    string line, temp, revline;
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

    return a.exec();
}
