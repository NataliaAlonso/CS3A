#include <iostream>
#include <cstdlib>
using namespace std;

typedef int* array2D;

int* create2DArray(int rows, int columns);
    //creates a 1D dynamic array and returns a pointer to the array
    //ptr = create2DArray(2,3) ~~ int ptr[2][3]

void set(int *arr, int rows, int columns, int desired_row, int desired_column, int val);
    //stores val into array at desired_row, desired_column
    //return error message and exit if indices are invalid
    //arr is the 1D array emulating 2D array
    //rows is the total number of rows in the array
    //columns is the total number of columns in the array
    //desired_row is the zero-based index of the row the caller would like accessed
    //desired_column is the zero-based index of the column the caller would like accessed
    //val is the value to store at desired_row and desired_column

int get(int *arr, int rows, int columns, int desired_row, int desired_column);
    // returns the value in the array at position desired_row and desired_column

int main()
{
    int arrayValue;
    array2D dynamic2DArray = create2DArray(2,3);

    //set a value for each element
    set(dynamic2DArray, 2, 3, 0, 0, 1);
    set(dynamic2DArray, 2, 3, 0, 1, 2);
    set(dynamic2DArray, 2, 3, 0, 2, 3);
    set(dynamic2DArray, 2, 3, 1, 0, 4);
    set(dynamic2DArray, 2, 3, 1, 1, 5);
    set(dynamic2DArray, 2, 3, 1, 2, 6);

    //display each element
    arrayValue = get(dynamic2DArray, 2, 3, 0, 0);
        cout << "\nArray element at [0][0] is " << arrayValue << endl;

    arrayValue = get(dynamic2DArray, 2, 3, 0, 1);
        cout << "\nArray element at [0][1] is " << arrayValue << endl;

    arrayValue = get(dynamic2DArray, 2, 3, 0, 2);
        cout << "\nArray element at [0][2] is " << arrayValue << endl;

    arrayValue = get(dynamic2DArray, 2, 3, 1, 0);
        cout << "\nArray element at [1][0] is " << arrayValue << endl;

    arrayValue = get(dynamic2DArray, 2, 3, 1, 1);
        cout << "\nArray element at [1][1] is " << arrayValue << endl;

    arrayValue = get(dynamic2DArray, 2, 3, 1, 2);
        cout << "\nArray element at [1][2] is " << arrayValue << endl;

    //change one element to 7
    set(dynamic2DArray, 2, 3, 1, 2, 7);
        arrayValue = get(dynamic2DArray, 2, 3, 1, 2);
        cout << "\nArray element at [1][2] is " << arrayValue << endl;

    //change element to 6
    set(dynamic2DArray, 2, 3, 1, 2, 6);
    arrayValue = get(dynamic2DArray, 2, 3, 1, 2);
        cout << "\nArray element at [1][2] is " << arrayValue << endl;

    set(dynamic2DArray, 2, 3, 1, 4, 7); //should return error

    arrayValue = get(dynamic2DArray, 2, 3, 1, 7); //should return error
}

int* create2DArray(int rows, int columns)
{
    array2D a;
    int size = rows*columns;
    a = new int[size];
    return a;
}

void set(int *arr, int rows, int columns, int desired_row, int desired_column, int val)
{
    int indexRow = rows-1;
    int indexCol = columns-1;
    int insert = (desired_row*columns) + desired_column;

    if((desired_row<=indexRow)&&(desired_column<=indexCol)&&(desired_row>=0)&&(desired_column>=0))//compare rows and columns to desired_row and desired_column
    {
        arr[insert] = val; //stores val into array at desired_row, desired_column
    }
    else
    {
      cout << "\nIndices are invalid." << endl; //return error message and exit if indices are invalid
    }
}

int get(int *arr, int rows, int columns, int desired_row, int desired_column)
{
    int indexRow = rows-1;
    int indexCol = columns-1;
    int getValue = 0;

    if((desired_row<=indexRow)&&(desired_column<=indexCol)&&(desired_row>=0)&&(desired_column>=0))//compare rows and columns to desired_row and desired_column
    {
        int location = (desired_row*columns) + desired_column;
        getValue = arr[location]; //stores val into array at desired_row, desired_column
        return getValue;
    }
    else
    {
        cout << "\nIndices are invalid." << endl; //return error message and exit if indices are invalid
        return 0;
    }
}
