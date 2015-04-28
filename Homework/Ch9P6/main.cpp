#include <iostream>
#include <cstdlib>
using namespace std;


string* addEntry(string *dynamicArray, int &size, string newEntry);
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);

int main()
{
    int dynamicArraySize=5;

    string *dynamicArray = new string[dynamicArraySize];

    dynamicArray[0] = "String 1";
    dynamicArray[1] = "String 2";
    dynamicArray[2] = "String 3";
    dynamicArray[3] = "String 4";
    dynamicArray[4] = "String 5";

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;

    dynamicArray = addEntry(dynamicArray, dynamicArraySize, "String 6");

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;

    dynamicArray = deleteEntry(dynamicArray, dynamicArraySize, "String 7");

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;

    dynamicArray = deleteEntry(dynamicArray, dynamicArraySize, "String 2");

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;

    dynamicArray = addEntry(dynamicArray, dynamicArraySize, "String 7");

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;


    dynamicArray = deleteEntry(dynamicArray, dynamicArraySize, "String 7");

        cout << "\nArray has elements: " << endl;
        for(int i =0; i < dynamicArraySize; i++)
            cout << dynamicArray[i] << endl;

}

string* addEntry(string *dynamicArray, int &size, string newEntry)
{
    string *newArray = new string[size+1]; // create a new array 1 element larger than dynamicArray

    for(int i = 0; i < size; i++)
        newArray[i] = dynamicArray[i]; // copy elements from dynamicArray into newArray

    newArray[size] = newEntry; // add newEntry onto end of newArray

    size++; // increment size by 1

    delete [] dynamicArray; // delete dynamic array

    return newArray; // return new array
}

string *deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
    string *newArray = new string[size-1];
    int location = 0;

    for(int i = 0; i < size; i++)
        if (dynamicArray[i] == entryToDelete)
            location = i;

    if(location == 0)
        return dynamicArray;
    else

        for (int j = 0; j < size; j++)
            {

                if (dynamicArray[j] != entryToDelete)
                    newArray[j] = dynamicArray[j];
                else
                {
                    for (int k = j; k < size-1; k++ )
                    {
                        newArray[k] = dynamicArray[k+1];
                    }

                    break;
                }
             }

    size--;

    delete [] dynamicArray;

    return newArray;

}
