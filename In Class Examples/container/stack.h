#ifndef BAG_H
#define BAG_H
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<typename T>
class stack
{
  public:
    stack(); //Default constructor
    stack(int qty);//Constructor to set size
    ~stack();
    stack(const T &other);
    stack<T>& operator=(stack<T> &other);

    T top();
    void push(const T &data);
    void pop();
    void clear();
    void resize(int qty);
    bool full();
    bool empty();
    int size();
    stack<T>& operator<<(const T &data); //Pushing
    stack<T>& operator>>(T &data); //Popping, with data returned

    template<typename U>
    friend ostream& operator<<(ostream &out, stack<U> &stk);


    template<typename U>
    friend istream& operator>>(istream &in, stack<U> &stk);

  private:
    int mySize, tos;
    T *list;
};

template<typename T>
stack<T>::stack() //Default constructor
{
    mySize = 5;
    list = new T[mySize];
    clear();
}

template<typename T>
stack<T>::stack(int qty)//Constructor to set size
{
    list = new T[mySize = qty];
    clear();
}

template<typename T>
stack<T>::~stack()
{
    delete [] list;
}

template<typename T>
stack<T>::stack(const T &other)
{
    mySize = other.mySize();
    list = new T[mySize];
    for(int i = 0; i < mySize; i++)
        list[i] = other.list[i];
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> &other)
{
    if(this != &other)
    {
        delete [] list;
        mySize = other.mySize();
        list = new T[mySize];
        for(int i = 0; i < mySize; i++)
            list[i] = other.list[i];
    }
    return *this;
}

template<typename T>
T stack<T>::top()
{
    return list[tos];
}

template<typename T>
void stack<T>::push(const T &data)
{
    if(!full())
    {
        list[++tos] = data;
    }
    else
        cout<<"Stack full!"<<endl;
}

template<typename T>
void stack<T>::pop()
{
    if(!empty())
    {
        tos--;
    }
    else
       cout<<"Stack empty"<<endl;
}

template<typename T>
void stack<T>::clear()
{
    tos = -1;
}

template<typename T>
void stack<T>::resize(int qty)
{
    delete [] list;
    mySize = qty;
    list = new T[mySize];
    clear();
}

template<typename T>
bool stack<T>::full()
{
    return (tos+1) == mySize;
}

template<typename T>
bool stack<T>::empty()
{
    return tos == -1;
}

template<typename T>
int stack<T>::size()
{
    return mySize;
}


template<typename T>
stack<T>& stack<T>::operator<<(const T &data) //Pushing
{
    push(data);
    return *this;
}

template<typename T>
stack<T>& stack<T>::operator>>(T &data) //Popping, with data returned
{
    data = top();
    pop();
    return *this;
}

template<typename U>
ostream& operator<<(ostream &out, stack<U> &stk)
{
    for(int i = stk.tos; i > -1; i--)
        out<<"stack["<<i<<"] = "<<stk.list[i]<<endl;
    return out;
}


template<typename U>
istream& operator>>(istream &in, stack<U> &stk)
{
    U data;
    while(in>>data)
        stk.push(data);
    return in;
}


#endif // BAG_H
