// CS3A Winter 2012 - Exam 2 - Data Element Counter
// Created by Natalia Alonso using palindrome class written by Dr. P.J. Wilkinson
// Palindrome been modified to suit the program
// Notes written in comments of source files

#include "unique.h"
#include "palindrom.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

bool checkPal(string s);                // Check for palindrom
string fileSelection();                 // Select file to sort
char typeSelection();                   // Select element type to sort
char formatSelection();                 // Select ascending or descending
void perform(char c, char d, string s); // Perform sort
void uniqueString(char c, string s);    // Sort function for unique strings
void notUniqueString(char c, string s); // Sort function for non-unique strings
void doubleOption(char c, string s);    // Sort function for doubles
void charOption(char c, string s);      // Sort function for characters
void intOption(char c, string s);       // Sort function for integers
void displayPalindromeA(unique<string> &input); // Display palindromes ascending
void displayPalindromeD(unique<string> &input); // Display palindromes descending

int main()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
         << "|           Super Fancy Element Sorter            |" << endl
         << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
         << " Thank you for using Super Fancy Element Sorter!!! " << endl
         << "You will be asked to choose what kind of items you " << endl
         << "want to sort, if you would like to sort ascending  " << endl
         << "or descending, and the name of the file you would  " << endl
         << "like to use. If you would like to see a demo, just " << endl
         << "type in demo when prompted. Cheers!!               " << endl
         << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;
     while(1)
    {
        char quit;                      // Character for exception handling
        try
        {
        char type = typeSelection();
        if (type == 'Q')                // If user selects quit, throw quit
            throw quit;
        char format = formatSelection();// Else, proceed with format and file selection
        string file = fileSelection();
        perform(type, format, file);    // Perform sort
        }
        catch(char c)                   // If user selected quit, exit program.
        {
            cout << "Exiting program." << endl;
            return(0);
        }
    }
}

bool checkPal(string s)
{
    stack<char> characters;             // Create stack of characters for palindrome check
    return performPal(characters, s);   // Get boolean from comparison
}

string fileSelection()
{
    string fileName;                    // String variable to hold user input
    int bad = 0;                        // Integer for exception handling
    char b;                             // Character for exception handling
    try
    {
    cout << endl                        // Prompt user for input file name or default demo file selection
         << "Please enter the name of the file you would like to sort," << endl
         << "or enter demo for the demo file." << endl;
         cin >> fileName;
         if (fileName == "demo")        // If user selected file, throw b
            throw b;
         ifstream myfile;               // Create ifstream for user file
         myfile.open(fileName.c_str()); // Open user file
         if ( !myfile.good() )          // Check if user file exists
            throw bad;                  // If not, throw bad
         else                           // If yes, use file
         {
            cout << "Using file " << fileName << endl;
            return fileName;
         }
    }

    catch(int e)                        // Exception for non-existant file
    {
        string newFileName;
        cout << "File does not exist. Please re-enter." << endl;
        newFileName = fileSelection();
        return newFileName;
    }

    catch(char c)                       // Exception for user selection of default demo file
    {
        cout << "You have elected to use the demo files." << endl;
        fileName = "";
        return fileName;
    }
}

char typeSelection()                    // Prompt user to select what kind of elements will be sorted
{                                       // User can also choose to exit program
        char type;
        cout << "Please select what kind of items you want to sort: " << endl
             << "U: Unique String" << endl
             << "N: Non-Unique String" << endl
             << "C: Character" <<endl
             << "I: Integer" <<endl
             << "D: Double" <<endl
             << "Q: Quit" <<endl;
             cin >> type;               // Get user input
             type = toupper(type);      // Convert to uppercase for ease of handling
            return type;                // Return user selection
}

char formatSelection()                  // Prompt user to select ascending or descending sort
{
    char format;
        cout << "Please select how you would like your items displayed: " << endl
             << "A: Ascending" << endl
             << "D: Descending" << endl;
             cin >> format;             // Get user input
             format = toupper(format);  // Convert to uppercase for ease of handling
             return format;             // Return user selection

}

void perform(char c, char d, string s)  // Function performs user selected sort
{
    switch(c)
    {
        case 'U': uniqueString(d,s);    // Perform sort for unique string elements
                  break;
        case 'N': notUniqueString(d,s); // Perform sort for non-unique string elements
                  break;
        case 'C': charOption(d,s);      // Perform sort for character elements
                  break;
        case 'I': intOption(d,s);       // Perform sort for integer elements
                  break;
        case 'D': doubleOption(d,s);    // Perform sort for double elements
                  break;
    }
}

void uniqueString(char c, string s)
{
    unique<string> ustring;             // Create string type unique item for input elements
    unique<string> palindrome;          // Create string type unique item for palindromes
    ifstream myfile;                    // Create ifstream for input

    if ( s == "")                       // If s is empty (default), open demo file string.txt
         myfile.open("string.txt");
    else
        myfile.open(s.c_str());         // Else open user defined file

    char line[256];
    while ( myfile.good() )
    {
        myfile.getline(line,256,' ');   // Space delimmited
        int i = 0;
        while( line[i] )                // Remove punctuation
        {
            if ((isspace(line[i]) || ispunct(line[i])) && line[i] != '-' && !isdigit(line[i+1])  && line[i] != '(' && line[i] != ')')
            {
                line[i] = '\0';
                break;
            }
            i++;
        }
        if( checkPal(line) == true )    // Check if element is a palindrome
            palindrome.addToMap(line,1);// If so, add to palindrome map

        ustring.addToMap(line,1);       // Add element to map
    }
    switch(c)
    {
        case 'A': displayPalindromeA(palindrome);   // Display palindrome map ascending first
                  ustring.displayAscending();       // Display element map ascending second so it will in front
                  break;
        case 'D': displayPalindromeD(palindrome);   // Display palindrome map descending first
                  ustring.displayDescending();      // Display element map descending second so it will in front
                  break;
    }
}

void notUniqueString(char c, string s)
{
    unique<string> nustring;            // Create string type unique item for input elements
    unique<string> palindrome;          // Create string type unique item for palindromes
    ifstream myfile;                    // Create ifstream for input

    if ( s == "")
         myfile.open("string.txt");      // If s is empty (default), open demo file string.txt
    else
        myfile.open(s.c_str());         // Else open user defined file

    char line[256];

    while ( myfile.good() )
    {
        myfile.getline(line,256,' ');   // Space delimmited
        line[0] = toupper(line[0]);
        int i = 0;
        while( line[i] )                // Remove punctuation
        {
            if ( (isspace(line[i]) || ispunct(line[i])) && line[i] != '-' && !isdigit(line[i+1])  && line[i] != '(' && line[i] != ')')
            {
                line[i] = '\0';
                break;
            }
            i++;
        }
        if( checkPal(line) == true )    // Check if element is a palindrome
            palindrome.addToMap(line,1);// If so, add to palindrome map

        nustring.addToMap(line,1);      // Add element to map
    }
    switch(c)
    {
        case 'A': displayPalindromeA(palindrome);   // Display palindrome map ascending first
                  nustring.displayAscending();      // Display element map ascending second so it will in front
                  break;
        case 'D': displayPalindromeD(palindrome);   // Display palindrome map descending first
                  nustring.displayDescending();     // Display element map descending second so it will in front
                  break;
    }
}

void charOption(char c, string s)
{
    unique<char> charstring;            // Create char type unique item for input elements
    char charItem;
    ifstream myfile;                    // Create ifstream for input

    if ( s == "")
         myfile.open("string.txt");     // If s is empty (default), open demo file "string.txt"
    else
        myfile.open(s.c_str());         // Else open user defined file

    while ( myfile.good() )
    {
        myfile.get(charItem);           // Get each char item including spaces
        charstring.addToMap(charItem,1);// Add element to map
    }
    switch(c)
    {
        case 'A': charstring.displayAscending();    // Display element map ascending
                  break;
        case 'D': charstring.displayDescending();   // Display element map descending
                  break;
    }
}

void intOption(char c, string s)
{
    unique<int> intstring;              // Create int type unique item for input elements
    char line[256];
    int intItem;
    ifstream myfile;                    // Create ifstream for input

    if ( s == "")                       // If s is empty (default), open demo file "int.txt"
         myfile.open("int.txt");
    else
        myfile.open(s.c_str());         // Else open user defined file

    while ( myfile.good() )
    {
        myfile.getline(line,256,' ');   // Space delimmited
        intItem = atoi(line);           // Convert string to int
        intstring.addToMap(intItem,1);  // Add element to map
    }
    switch(c)
    {
        case 'A': intstring.displayAscending(); // Display element map ascending
                  break;
        case 'D': intstring.displayDescending();// Display element map descending
                  break;
    }
}


void doubleOption(char c, string s)
{
    unique<double> dblstring;           // Create double type unique item for input elements
    char line[256];
    double dblItem;
    ifstream myfile;                    // Create ifstream for input

    if ( s == "")
         myfile.open("double.txt");     // If s is empty (default), open demo file "double.txt"
    else
        myfile.open(s.c_str());         // Else open user defined file

    while ( myfile.good() )
    {
        myfile.getline(line,256,' ');   // Space delimmited
        dblItem = atof(line);           // Convert string to double
        dblstring.addToMap(dblItem,1);  // Add element to map
    }
    switch(c)
    {
        case 'A': dblstring.displayAscending(); // Display element map ascending
                  break;
        case 'D': dblstring.displayDescending();// Display element map descending
                  break;
    }
}


void displayPalindromeA(unique<string> &input)                      // Creates a file for outputting the palindromes
{                                                                   // Creates interator to iterate through palindrome map
    ofstream outfile ("palindrome.txt");                            // Outputs each elements in palindrome map
    outfile << setw(5) << "Qty" << ": " << "Element"<< endl << endl;   // Closes output file
    map<string,int>::iterator it;                                   // Opens output file
    for(it = input.index.begin() ; it != input.index.end(); it++)
        outfile << setw(5) << it->second << ": " << it->first << endl << endl;
    outfile.close();
    system("start palindrome.txt");
}

void displayPalindromeD(unique<string> &input)                      // Creates a file for outputting the palindromes
{                                                                   // Creates interator to iterate through palindrome map
    ofstream outfile ("palindrome.txt");                            // Outputs each elements in palindrome map
    outfile << setw(5) << "Qty" << ": " << "Element"<<endl<<endl;   // Closes output file
    map<string,int>::reverse_iterator rit;                          // Opens output file
    for(rit = input.index.rbegin() ; rit != input.index.rend(); rit++)
        outfile << setw(5) << rit->second << ": " << rit->first << endl << endl;
    outfile.close();
    system("start palindrome.txt");
}


