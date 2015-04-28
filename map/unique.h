#ifndef UNIQUE_H
#define UNIQUE_H

template<typename T>
class unique
{
    public:
        /** Default constructor */
        unique();

        /** Default destructor */
        virtual ~unique();

    protected:

    private:
    //map<T,int> index;
};

#endif // UNIQUE_H

template<typename T>
unique<T>::unique()
{
  map<T,int> index;
}

template<typename T>
virtual unique<T>::~unique()
{
    delete [] index;
}
