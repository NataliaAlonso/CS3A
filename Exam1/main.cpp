#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>
#include "mixed.h"
#include "fraction.h"
#include "parser.h"
#include "calculator.h"


using namespace std;



//mixed correct(string s);

int main()
{

// TESTING MIXED
 string lols = "1 1/2";
 fraction g(1,2);

 mixed a(lols);
 mixed b(5,1,2);
 mixed c(1,0,2);
 mixed d(1,1,1);
 mixed e(1,2,3);
 mixed f(1,g);

cout << "These are the mixed numbers: " << endl;
cout << a << endl;
cout << b <<endl;
cout << c <<endl;
cout << d <<endl;
cout << e <<endl;
cout << f <<endl;

cout << "These are the results:" <<endl;

cout << (a + g) << endl;
cout << a+b <<endl;
cout << a-b <<endl;
cout << a*b <<endl;
cout << a/b <<endl;



 //PARSER
 /*
 string str = "2/3";
 mixed a(str);
 cout << a;

    parser list;
    string line;
    vector<string> item;
    do
    {
        cout<<"Line: ";
        getline(cin, line);
        list << line;
        list >> item;

    }while(line != "");
    */
}
