#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void sterilize(string& line);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string line;
    while(getline(cin, line))
       {
        cout << "You entered: " << line << endl;
        sterilize(line);
        cout << "Sterilized line: " << line <<endl;
    }
    
    return a.exec();
}

void sterilize(string& line)
{
    int pos;
    cout << "Entering sterilize, line =" << line << endl;
    while((pos = line.find(' ')) != string::npos) // predefined const: max # chars a string can hold
        line.erase(pos,1);
    cout << "After erasing spaces: " << line << endl;
    pos = line.find('/');
    pos = line.find_first_of("!><=+*/", pos+1);
    line.insert(pos," ");
    pos = line.find_first_of("0123456789", pos); // tell me which one you find first
    line.insert(pos," ");
    cout << "Leaving sterilize, line = " << line << endl;

}
