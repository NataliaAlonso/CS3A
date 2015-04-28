#ifndef NODE_H
#define NODE_H
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct node
{
public:
    int x, y;
    string name;
    node(); // what do I do when I am created
    ~node(); // what do I do when I go out of scope
    node(const node &x); // copy constructor how do I make a copy of something that's called node
    node& operator=(node &x); // how do I assign the values of one node to another note
    /* allows you to "chain operations". That is: "a = b = c = d;" */
    void build();
    void print();
    void move();
};

#endif // NODE_H
