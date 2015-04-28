#include <QtCore/QCoreApplication>
#include <string>
#include <iostream>
#include <cstdarg>
#include <cstdlib>

using namespace std;

void myPrintF(char *format,...);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    myPrintF("This is a test. 4 / 5 is %d\n", (4/5));
    myPrintF("Pi is %f\n", 3.1415);
    myPrintF("Hello World\n");
    myPrintF("%s\n", "Bye");
    return a.exec();
}


void myPrintF(char *format,...)
{
    char *fmt = format;
    int d;
    char c;
    char *s;
    double f;
    va_list vl;

    va_start(vl,format);
    while(*fmt != '\0')
    {
        switch(*fmt)
        {
          case '\\' : fmt++;
                      switch(*fmt)
                      {
                         case 'n' : cout<<"\n";
                                    break;

                         case 't' : cout<<"\t";
                                    break;

                         case 'b' : cout<<"\b";
                                    break;

                         default  : c = *fmt;
                                    cout<<c;

                      }

                      break;
          case '%' : fmt++;
                     switch(*fmt)
                     {
                        case 'd' : d = va_arg(vl,int);
                                   cout<<d;
                                   break;

                        case 'c' : c = va_arg(vl,char);
                                   cout<<c;
                                   break;

                        case 'f' : f = va_arg(vl, double);
                                   cout<<f;
                                   break;

                        case 's' : s = va_arg(vl, char*);
                                   cout<<s;
                                   break;

                        default  : c = *fmt;
                                   cout<<c;
                     }

                     break;

          default  : c = *fmt;
                     cout<<c;
        }
        fmt++;
    }
    va_end(vl);
}

