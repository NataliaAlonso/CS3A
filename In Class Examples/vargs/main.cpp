#include <QtCore/QCoreApplication>



/* va_arg example */
#include <stdio.h>
#include <stdarg.h>

void PrintLines ( char* first, ...)
{
  char* str;
  va_list vl;

  str=first;

  va_start(vl,first);

  do {
    printf ("%s\n",str);
    str=va_arg(vl,char*);
  } while (str!=NULL);

  va_end(vl);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  PrintLines ("First","Second","Third","Fourth",NULL);
  return a.exec();
}
