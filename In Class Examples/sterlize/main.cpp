#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void sterilize(string& line);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string line;
    while(getline(cin, line))
    {
        cout<<"You entered: "<<line<<endl;
        sterilize(line);
        cout<<"Sterilized line: "<<line<<endl;
    }
    return a.exec();
}

void sterilize(string& line)
{
    int pos;
    cout<<"Entering sterilize, line = "<<line<<endl;

    while((pos = line.find(' ')) != string::npos)
          line.erase(pos,1);
    cout<<"After erasing spaces: "<<line<<endl;

    pos = line.find('/');
    cout<<"Found the / for the frist fraction at "<<pos<<endl;
    pos = line.find_first_of("!><=+-*/", pos+1);
    cout<<"Found the operator beginning at "<<pos<<endl;
    line.insert(pos," ");
    pos = line.find_first_of("0123456789", pos);
    line.insert(pos," ");
    cout<<"Leaving sterilize, line = "<<line<<endl;
}
