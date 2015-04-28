#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "parser.h"

using namespace std;

void calculate(vector<string>& items);
int pop(vector<int>& stk);

int main()
{
    parser list;
    string line, rpnLine;
    vector<string> things;
    do
    {
          cout<<"Line: ";
          getline(cin, line);
          list << line;
          list >> things;
          list >> rpnLine;
          cout<<"You had "<<things.size()<<" items on your line and they are: "<<endl;
          for(unsigned int i = 0; i < things.size(); i++)
              cout<<things[i]<<endl;
          cout<<"The line in RPN is: "<< rpnLine << "= ";
          calculate(things);

    }while(line != "");
}

void calculate(vector<string>& items)
{
	vector<int> numbers;
	string token;
	while (items.size())
	{
	    token = items[0];
		if ( isdigit(token[0]) )
		{
			numbers.push_back(atoi(token.c_str()));
			items.erase(items.begin());
		}
		else
		{
			int first, second, pos;
			pos = token.find_first_of("+-*/",0);
			char op = token[pos];
			switch(op)
			{
				case '+': second = numbers.back();
                          numbers.pop_back();
                          first = numbers.back();
                          numbers.pop_back();
                          numbers.push_back(first + second);
                          break;
				case '-': second = numbers.back();
                          numbers.pop_back();
                          first = numbers.back();
                          numbers.pop_back();
                          numbers.push_back(first - second);
                          break;
				case '*': second = numbers.back();
                          numbers.pop_back();
                          first = numbers.back();
                          numbers.pop_back();
                          numbers.push_back(first * second);
                          break;
				case '/': second = numbers.back();
                          numbers.pop_back();
                          first = numbers.back();
                          numbers.pop_back();
                          numbers.push_back(first / second);
                          break;
			}
			items.erase(items.begin());
		}
	}
	cout << numbers.back() << endl;
}
