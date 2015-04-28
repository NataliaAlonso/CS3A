#ifndef NODE_H
#define NODE_H
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    //"Characteristics" of the structure -- size, shape, color, and so forth
    int x, y; //x and y location on a grid
    string name; //The name of the entity

    node(); //What do I do when I am created
    ~node(); //What do I do when I go out of scope
    node(string name);
    node(const node &x); //How do I make a copy of another node
    node& operator=(node &x); //How do I assign a node's value to another node
    /*
      Returning by reference allows you to "chain operations"
      This is
      a = b = c = d;
    */
    void print();
    void move();
    void build();
};

#endif // NODE_H
