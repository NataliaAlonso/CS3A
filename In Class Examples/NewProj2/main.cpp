#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

void swap(char *a, char *b);
char* find(char s[], char item);
void swapIt(char &a, char &b);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char title[16] = ">Hello World!!<"; /*all C string end with /0 */
    char *lt, *gt;
    lt = find(title,'<');
    gt = find(title,'>');
    for (int i = 0; i < 10; i++)
    {
        cout<<title<<endl;
        swap(lt,gt);
    }
    return a.exec();
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* find(char s[], char item)
{
    char *ptr=&s[0];
    for(; *ptr != item; ptr++);
    return ptr;
}
