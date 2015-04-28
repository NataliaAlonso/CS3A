#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


class parser
{
    public:
      parser();
      ~parser();
      parser(string &data);
      parser(const parser& other);
      parser& operator=(const parser& other);

      parser& operator<<(string& data);//Insertion operator
      void input(string& data);

      parser& operator>>(vector<string> &result);//Extraction operator
      void result(vector<string> &data);

    private:
      vector<string> items;
      string line;

      void putResult(vector<string> &data);
      void parse();
      void binaryOp(int &pos, bool &redo);
      void fractionOp(int &pos);
};


#endif // PARSER_H
