// CS3A Winter 2012 - Exam 1 - RPN Calculator
// Created by Natalia Alonso using mixed, fraction, and parser classes written by Dr. P.J. Wilkinson
// Mixed, fraction, and parser have been modified to suit the program
// Notes written in comments of source files

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "parser.h"
#include "mixed.h"
#include "fraction.h"

using namespace std;

void calculate(vector<string>& items);

int main()
{
    cout << "Please enter your equation with one space before and after" << endl
        << "each operator and each operand." << endl;
    parser list;
    string line, rpnLine;
    vector<string> items;
    do
    {
          cout<<"Your equation: ";
          getline(cin, line);
          if ( line != "")
          {list << line;
          list >> items;
          list >> rpnLine;
          cout<<"\nYour equation in RPN: "<< rpnLine << "= ";
          calculate(items);
          cout << "\n"<< endl;
          }
    }while(line != "");
}

void calculate(vector<string>& items)
{
    vector<mixed> numbers;                              // Create a stack for operands and total
    mixed a(1,0,1);                                     // Create a temp mixed number
	string token;                                       // Create a string to store parsed input
	unsigned int newPos;                                // Created to hold position of first digit in input string
	while (items.size())                                // (used to test if string is operator or operand)
	{
	    token = items[0];
	    newPos = token.find_first_of("0123456789",0);   // Test if token is operand or operator
		if ( newPos < string::npos )
		{
            a.setValue(token);                          // Set value of mixed a to string
            numbers.push_back(a);                       // Push mixed a
            items.erase(items.begin());                 // Erase first element in items
		}
		else
		{
		    mixed b, c;                                 // Temp mixed variables to store right and left hand side of equation
			int pos;
			pos = token.find_first_of("+-*/",0);        // Find operator position
			char op = token[pos];                       // Convert operator to char for switch statement
			switch(op)
			{
				case '+': c = numbers.back();           // Pop top of stack onto right hand temp
                          numbers.pop_back();
                          b = numbers.back();           // Pop top of stack onto left hand temp
                          numbers.pop_back();
                          numbers.push_back(b + c);     // Perform op and push back onto stack
                          break;
				case '-': c = numbers.back();           // Pop top of stack onto right hand temp
                          numbers.pop_back();
                          b = numbers.back();           // Pop top of stack onto left hand temp
                          numbers.pop_back();
                          numbers.push_back(b - c);     // Perform op and push back onto stack
                          break;
				case '*': c = numbers.back();           // Pop top of stack onto right hand temp
                          numbers.pop_back();
                          b = numbers.back();           // Pop top of stack onto left hand temp
                          numbers.pop_back();
                          numbers.push_back(b * c);     // Perform op and push back onto stack
                          break;
				case '/': c = numbers.back();           // Pop top of stack onto right hand temp
                          numbers.pop_back();
                          b = numbers.back();           // Pop top of stack onto left hand temp
                          numbers.pop_back();
                          numbers.push_back(b / c);     // Perform op and push back onto stack
                          break;

                case '^': c = numbers.back();           // Pop top of stack onto right hand temp
                          numbers.pop_back();
                          b = numbers.back();           // Pop top of stack onto left hand temp
                          numbers.pop_back();
                          numbers.push_back(pow(b,c));     // Perform op and push back onto stack
                          break;
			}
			items.erase(items.begin());                 // Erase first element in items
		}
	}
	cout << numbers.back() << endl;                     // Display total
}
