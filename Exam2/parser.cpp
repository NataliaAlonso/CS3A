#include "parser.h"

parser::parser()            // Default constructor
{
}

parser::~parser()           // Destructor
{
    for(;items.size();)
        items.erase(items.begin());
}

parser::parser(string &data)        // Constructor from string
{
    line = data;
}

parser::parser(const parser& other)     // Copy constructor
{
    line = other.line;
    for(unsigned int i = 0; i < other.items.size(); i++)
        items.push_back(other.items[i]);
}

parser& parser::operator=(const parser& other)          // Assignment operator
{
    if(this != &other)
    {
        line = other.line;
        items.clear();
        for(unsigned int i = 0; i < other.items.size(); i++)
            items.push_back(other.items[i]);
    }
    return *this;
}

parser& parser::operator<<(string& data)        // Get line from data string, parse it
{
    line = data;
    parse();
    return *this;
}//Insertion operator

void parser::input(string& data)
{
    line = data;
    parse();
}

void parser::parse()
{
    unsigned int pos;           // Position of character
    string temp;
    items.clear();              // Clear items stack
    while(line.size())
    {
        pos = 0;                // Set position to 0
        pos = line.find_first_of(" ", pos);                       // Find first non-digit character
        if(pos < string::npos)
        {
            /**
            FOR STRINGS
            1. Create a substring from 0 to pos
            2. Check string for punctuation marks
            3. Discard punctuation marks
            4. Check for palindrome
            5. If user selected non-unique string, convert all to lowercase, then capitalize first letter and return
            6. If user selected unique string, return string
            7. Pass through addToMap(x, 1);

            FOR ALL OTHERS
            1. Create a substring from 0 to pos
            2. Convert substring to type
            3. Pass through addToMap(x, 1);
            **/
        }
        else
        {
            exit(0);
        }

    }
}

parser& parser::operator>>(vector<string> &result)
{
    putResult(result);
    return *this;
}//Extraction operator

void parser::result(vector<string> &data)
{
    putResult(data);
}

void parser::putResult(vector<string> &data)
{
    data.clear();
    for(unsigned int i = 0; i < items.size(); i++)
    {
        data.push_back(items[i]);
    }
}

