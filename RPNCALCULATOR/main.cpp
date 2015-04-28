// stl/rpn.cpp -- RPN (Reverse Polish Notation) Calculator
// Fred Swartz 2001-12-05, 2002-09-27
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

int pop(vector<int>& stk);  //--- prototype to pop stack

//============================================================= main
int main() {
    vector<int> opndStack; // vector used as operand stack
    string token;          // to read number or operator

    while (cin >> token) {
        if (isdigit(token[0])) { // if first is digit, it's number.
            opndStack.push_back(atoi(token.c_str())); // convert, push

        } else { // If it's not a number, assume it's an operator
            int left, right;  //  used by some operators as temps

            switch (token[0]) {  // assume operators are one char
              case '+': opndStack.push_back(pop(opndStack) + pop(opndStack));
                        break;
              case '-': right = pop(opndStack); // get right operand
                        left  = pop(opndStack); // get left operand
                        opndStack.push_back(left - right);
                        break;
              case '*': opndStack.push_back(pop(opndStack) * pop(opndStack));
                        break;
              case '/': right = pop(opndStack); // get right operand
                        left  = pop(opndStack); // get left operand
                        opndStack.push_back(left / right);
                        break;
              default:  throw domain_error("Undefined operator");
            }
            cout << "Result: " << opndStack.back() << endl;
        }
    }
    return 0;
}//end main

//============================================================== pop
   // This utility function checks stack for underflow
   // and pops (removes and returns) last element.
int pop(vector<int>& stk) {
    if (stk.empty()) {
        throw underflow_error("Stack underflow.");
    }
    int result = stk.back();
    stk.pop_back();
    return result;
}//end pop
