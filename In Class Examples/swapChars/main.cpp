#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

void swap(char *a, char *b);
void swapIt(char &a, char &b);
char* find(char s[], char item);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char title[16] = ">Hello World!!<";
    char *lt, *gt;
    lt = find(title, '<');
    gt = find(title, '>');
    for(int i = 0; i < 10; i++)
    {
        cout<<title<<endl;
        i%2 ? swap(lt,gt) : swapIt(*lt,*gt);
        /*
          The above is:
          if(i%2 == 1)
            swap(lt,gt);
          else
            swapIt(*lt, *gt);
         */
    }
    return a.exec();
}

void swapIt(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* find(char s[], char item)
{
    char *ptr = &s[0];
    for(; *ptr != item; ptr++);
    return ptr;
}
