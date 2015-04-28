#include "parser.h"
#include <cstring>
using namespace std;

parser::parser()
{
}

parser::~parser()
{
    for(;items.size();)
        items.erase(items.begin());
}

parser::parser(string &data)
{
    line = data;
}

parser::parser(const parser& other)
{
    line = other.line;
    for(int i = 0; i < other.items.size(); i++)
        items.push_back(other.items[i]);
}

parser& parser::operator=(const parser& other)
{
    if(this != &other)
    {
        line = other.line;
        items.clear();
        for(int i = 0; i < other.items.size(); i++)
            items.push_back(other.items[i]);
    }
    return *this;
}

parser& parser::operator<<(string& data)
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
    int pos;
    bool redo;
    string temp;
    items.clear();
    while(line.size())
    {
        pos = 0;
        redo = true;
        while(redo)
        {
            redo = false;
            pos = line.find_first_not_of("0123456789 ",pos);
            if(pos < string::npos)
                switch(line[pos])
                {
                  case '(' :  items.push_back(line.substr(pos,1));
                              line.erase(pos,1);
                              break;
                  case '/' : // Cascade
                  case '+' : // Cascade
                  case '-' : // Cascade
                  case '*' : binaryOp(pos, redo);
                             break;
                  case '=' : // Cascade
                  case '!' : // Cascade
                  case '>' : // Cascade
                  case '<' : if(line[pos+1] == '=')
                             {
                                 items.push_back(line.substr(pos,2));
                                 line.erase(pos,2);
                             }
                             else
                                if(line[pos+1] == ' ')
                                    binaryOp(pos, redo);
                                else
                                {
                                    redo = true;
                                    line.insert(pos+1," ");
                                }
                             break;

                   case ')' : items.push_back(line.substr(0,pos));
                              items.push_back(line.substr(pos,1));
                              line.erase(0,pos+1);
                }
            else
            {
                items.push_back(line);
                line = "";
            }
        }
    }
}

void parser::fractionOp(int &pos)
{
    const char* cs = "/";
	line.replace(pos,1,cs,1);
	// pos = line.find_first_of(" ",pos);
	// items.push_back(line.substr(0,pos));
	// line.erase(0,pos+1);
}

void parser::binaryOp(int &pos, bool &redo)
{
    if(line[pos-1] == ' ' && line[pos+1] == ' ')
    {
       items.push_back(line.substr(0,pos));
       items.push_back(line.substr(pos,1));
       line.erase(0,pos+1);
    }
    else
    {
      pos++;
      redo = true;
    }
}

parser& parser::operator>>(string &result)
{
    result = rpnLine;
    return *this;
}//Extraction operator

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
    for(int i = 0; i < items.size(); i++)
    {
        data.push_back(items[i]);
        rpnLine = items[i] + " ";
    }
}
