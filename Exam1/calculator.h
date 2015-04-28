#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "mixed.h"
#include "fraction.h"
#include "parser.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

class calculator
{
    public:
        /** Default constructor */
        calculator();
        /** Default destructor */
        virtual ~calculator();
        /** Copy constructor
         *  \param other Object to copy from
         */
        calculator(const calculator& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        calculator& operator=(const calculator& other);



    protected:

    private:
        stack<string> outputStack;; //!< Member variable "outputStack;"
        stack<int> numberStack;; //!< Member variable "numberStack;"
        stack<char> operatorStack;; //!< Member variable "numberStack;"
};

#endif // CALCULATOR_H
