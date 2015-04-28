#include "node.h"


node::node() //Constructor
{
    x = rand()%80;
    y = rand()%24;
    name = "Object " + char(65+rand()%26);
}

node::~node() // Destructor
{
    cout << name << " has left the building."<<endl;
}

void node::build()
{
    x = rand()%81;
    y = rand()%24;
}

node::node(const node &other) //Copy Constructor
{
    x = other.x; //dot operator go to x of other and get value
    y = other.y;
    name = other.name;

}

node& node::operator=(node &other) //Return by Reference
{
    x = other.x;
    y = other.y;
    name = other.name;
    return*this;
}

void node::print()
{
    string name;
    int x, y;
    cout << name << " is at x = " << x << ", y = " << y << endl;
}

void node::move()
{
    x += (int)pow(-1., rand()%2)*(rand()%3);
    y += (int)pow(-1., rand()%2)*(rand()%3);
    if ( x > 80)
        x = 0;
    if ( x < 0);
        x = 80;
    if ( y > 24)
        y = 0;
    if ( y < 0 )
        y = 24;
}
