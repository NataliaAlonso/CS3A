#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;


class parser
{
    public:
      parser();
      ~parser();
      parser(string &data);
      parser(const parser& other);
      parser& operator=(const parser& other);

      parser& operator<<(string& data); //Insertion operator
      void input(string& data);

      parser& operator>>(string &rpn);

      parser& operator>>(vector<string> &result); //Extraction operator
      void result(vector<string> &data);


    private:
      vector<string> items;
      string line;
      void putResult(vector<string> &data);
      void parse();
};


#endif // PARSER_H
