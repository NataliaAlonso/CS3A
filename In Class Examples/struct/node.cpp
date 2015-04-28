#include "node.h"

node::node()  //The Constructor
{
    build();
}

node::node(string myName)
{
   name = myName;
   build();
}

void node::build()
{
    x = rand()%81;
    y = rand()%24;
}

node::~node() //What do I do when I go out of scope
{
    //Destructor
    cout<<name<<" has left the room"<<endl;
}

node::node(const node &other) //How do I make a copy of another node
{
    //Copy constructor
    x = other.x;
    y = other.y;
    name = other.name;
}

node& node::operator=(node &other) //How do I assign a node's value to another node
/*
  Returning by reference allows you to "chain operations"
  This is
  a = b = c = d;
*/
{
    //Assignment operator
    x = other.x;
    y = other.y;
    name = other.name;
    return *this;
}

void node::print()
{
    //A member function called print
    cout<<name<<" is at x = "<<x<<" y = "<<y<<endl;
}

void node::move()
{
    x += (int)pow(-1., rand()%2)*(rand()%3);
    y += (int)pow(-1., rand()%2)*(rand()%3);
    if(x > 80)
        x = 0;
    if(x < 0)
        x = 80;
    if(y > 24)
        y = 0;
    if(y < 0)
        y = 24;
}
