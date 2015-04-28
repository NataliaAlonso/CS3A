#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

enum ERRORS {NOT_FOUND};

template<typename T, typename U>
class map
{
   public:
        map();
        ~map();
        map(const map<T,U> &other);
        map<T,U>& operator=(const map<T,U> &other);


        U& operator[](const T& index);

        bool empty();
        int size();
        void insert(const T &index, const U &value);
        void erase(T &item);
        void clear();
        void swap(map<T,U> &other);
        bool find(T& index);

        template<typename R,typename S>
        friend
        ostream& operator<<(ostream &out, map<R,S> &theMap);

        template<typename R,typename S>
        friend
        istream& operator>>(istream &in, map<R,S>& myMap);

   private:
        vector<T> indexes;
        vector<U> values;

        int locate(const T &index);

};

template<typename T, typename U>
map<T,U>::map()
{

}

template<typename T, typename U>
map<T,U>::~map()
{

}

template<typename T, typename U>
map<T,U>::map(const map<T,U> &other)
{
    for(int i = 0; i < other.indexes.size();i++)
        insert(other.indexes[i], other.values[i]);
}

template<typename T, typename U>
map<T,U>& map<T,U>::operator=(const map<T,U> &other)
{
    indexes.clear();
    values.clear();
    for(unsigned int i = 0; i < other.indexes.size();i++)
        insert(other.indexes[i], other.values[i]);
    return *this;
}

template<typename T, typename U>
U& map<T,U>::operator[](const T& index)
{
    int place = locate(index);
    if(place == -1)
        throw NOT_FOUND;
    return values[place];
}

template<typename T, typename U>
bool map<T,U>::empty()
{
    return indexes.empty();
}

template<typename T, typename U>
int map<T,U>::size()
{
   return indexes.size();
}

template<typename T, typename U>
void map<T,U>::insert(const T &index,const U &value)
{
    indexes.push_back(index);
    values.push_back(value);
}

template<typename T, typename U>
void map<T,U>::erase(T &item)
{
    int place = locate(item);
    if(place == -1)
        throw NOT_FOUND;
    indexes.erase(indexes.begin() + place);
    values.erase(values.begin() + place);
}

template<typename T, typename U>
void map<T,U>::clear()
{
    indexes.clear();
    values.clear();
}

template<typename T, typename U>
void map<T,U>::swap(map<T,U> &other)
{
    indexes.swap(other.indexes);
    values.swap(other.values);
}

template<typename T, typename U>
bool map<T,U>::find(T& index)
{
    return locate(index) != -1;
}

template<typename R,typename S>
ostream& operator<<(ostream &out, map<R,S> &theMap)
{
    for(unsigned int i = 0; i < theMap.indexes.size(); i++)
        out<<"map["<<theMap.indexes[i]
          <<"] = "<<theMap.values[i]<<endl;
    return out;
}

template<typename R,typename S>
istream& operator>>(istream &in, map<R,S> &myMap)
{
    R index;
    S value;
    while(in>>index>>value)
    {
        myMap.indexes(index);
        myMap.values(value);
    }
    return in;
}

template<typename T, typename U>
int map<T,U>::locate(const T &index)
{
    for(unsigned int i = 0; i < indexes.size(); i++)
        if(index == indexes[i])
            return i;
    return -1;
}

#endif // MAP_H
