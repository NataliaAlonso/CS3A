#include "codebreaker.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

codebreaker::codebreaker()
{
    initializeBreakerScoreArray();
}

codebreaker::~codebreaker()
{
    //dtor
}

codebreaker::codebreaker(const codebreaker& other)
{
    for(int i = 0; i <4; i++)
    {
        guess[i] = other.guess[i];
    }
    tempScore = other.tempScore;
    score = other.score;
    colorArray = other.colorArray;
    guessArray = other.guessArray;
}

codebreaker& codebreaker::operator=(const codebreaker& other)
{
    if (this == &other) return *this;
    for(int i = 0; i <4; i++)
    {
        guess[i] = other.guess[i];
    }
    colorArray = other.colorArray;
    guessArray = other.guessArray;
    initializeColorArray();
    return *this;
}


char codebreaker::returnColor(int i)
{
    char color = '\0';
    switch(i)
    {
        case 1: color = 'R';
                break;
        case 2: color = 'G';
                break;
        case 3: color = 'B';
                break;
        case 4: color = 'Y';
                break;
        case 5: color = 'O';
                break;
        case 6: color = 'P';
                break;
    }
    return color;
}

void codebreaker::createFirstGuess()
{
    score = 0;
    keep = 0;
    move = 0;
    for(int i = 0; i <4; i++)
    {
        guess[i] = '\0';
        CFG[i] = '\0';
    }
    initializeColorArray();

    for ( int i = 0; i < 4; i++)
    {
        int temp = (rand()%6)+1;
        guess[i] = returnColor(temp);
    }
    assignCFG();
 }

void codebreaker::createGuess()
{
    bool repeat = true;
    int count=0;
    while(repeat)
    {
        count++;
        repeat = false;
        if(compareScore(tempScore))
        {
            assignCFG();
        }
        else
        {
            assignGuess();
        }
        setActions();
        performActions();
        repeat = compareGuess();
    }
}

void codebreaker::assignCFG()
{
    for( int i = 0; i < 4; i++ )
        {
            CFG[i] = guess[i];
        }
}

void codebreaker::assignGuess()
{
    for( int i = 0; i < 4; i++ )
        {
            guess[i] = CFG[i];
        }
}

void codebreaker::getScore(int s)
{
    tempScore = s;
}

void codebreaker::storeGuess()
{
    string code;
    for( unsigned int i = 0; i < 4; i++ )
    {
        code.push_back(guess[i]);
    }
    //cout << "STORING CODE" << code <<endl;
    guessArray.push_back(code);
    //cout << "STORED: " << guessArray.back () << endl;
    //cout << "Exiting store" << endl;
}

bool codebreaker::compareScore( int s )
{
    bool compare;
    compare = ( (s>=score) && s!=0 );
    //cout << "Comparing Score inside" <<endl;
    //cout << "Score is" << s <<endl;
    if( s == 0 )
        {
            //cout << "REMOVING A COLOR" <<endl;
            removeColor();
            //cout << "DONE REMOVING A COLOR" <<endl;
        }
    if( compare )
        {
            //cout << "STORING NEW HIGH SCORE" << endl;
            score = s;
        }
    return compare;
}

bool codebreaker::compareGuess()
{
    bool same = false;
    string code;
    for( unsigned int i = 0; i < 4; i++)
    {
        code.push_back(guess[i]);
    }
    //cout << "Code is: " << code << endl;
    for( unsigned int j = 0; j < guessArray.size(); j++)
    {
        if( guessArray[j] == code )
        {
            same = true;
        }
    }
    return same;
}

 void codebreaker::removeColor()
 {
    //cout <<"STARTING REMOVE COLOR"<<endl;
    for(unsigned int i=0; i < 4; i++)
    {
        for(unsigned int j = 0; j < colorArray.size(); j++)
        {
            if( guess[i] == colorArray[j] )
            {
                //cout << "Guess is" << guess[i];
                //cout << "Color array is " << colorArray[j];
                colorArray.erase(colorArray.begin()+j);
                //cout << "Colorarray size is: "<<colorArray.size()<<endl;
            }
        }
    }
 }

 void codebreaker::setActions()
 {
    switch(score)
    {
    case 0: keep = 0;
            move = 0;
            break;
    case 1: keep = 0;
            move = 1;
            break;
    case 2: keep = 1;
            move = 0;
            break;
    case 3: keep = 0;
            move = 2;
            break;
    case 4: keep = 1;
            move = 1;
            break;
    case 5: keep = 2;
            move = 0;
            break;
    case 6: keep = 0;
            move = 3;
            break;
    case 7: keep = 1;
            move = 2;
            break;
    case 8: keep = 2;
            move = 1;
            break;
    case 9: keep = 3;
            move = 0;
            break;
    case 10: keep = 0;
            move = 4;
            break;
    case 11: keep = 1;
            move = 3;
            break;
    case 12: keep = 2;
            move = 2;
            break;
    case 13: keep = 4;
            move = 0;
            break;
    }
    //cout << " Keep " << keep <<endl;
    //cout << " Move " << move <<endl;
 }

bool codebreaker::checkGuessElement(int i)
{
    bool result;
    for( unsigned int j = 0; j < colorArray.size(); j++ )
    {
        if( (guess[i] == colorArray[j]) )
        {
            result= true;
            break;
        }
        else
        {
            result= false;
        }
    }
    return result;
}


void codebreaker::performActions()
{

    bool ignore[4];
    bool swapArray[4];
    for ( int i = 0; i < 4; i++ )
    {
        ignore[i] = false;
        swapArray[i] = false;
    }

    if( move == 4 )
    {
        int select = 0;
        int swap = 0;
        int swap2 = 0;
        char tempSelect;

        while( ignore[select] == true )
        {
            select = rand()%4;
        }

        while( ignore[swap] == true || swap == select )
        {
            swap = rand()%4;
        }
        while( ignore[swap2] == true || swap2 == select || swap2 == swap )
        {
            swap2 = rand()%4;
        }
        //cout << "Swapping " << select << " into "<< swap2 <<endl;
        //cout << "Swapping " << swap2 << " into "<< swap <<endl;
        //cout << "Swapping " << swap << " into "<< select <<endl;
        tempSelect = guess[select];

        guess[select] = guess[swap2];
        guess[swap2] = guess[swap];
        guess[swap] = tempSelect;


        ignore[select] = true;
        ignore[swap] = true;
        ignore[swap2] = true;

        for ( int i = 0; i < keep; i++ )
        {
            int select = 0;
            int swap;
            char tempSelect;
            while ( ignore[select] == true )
            {
                select = rand()%4;
            }
            while (swap == select )
            {
            swap = rand()%4;
            }
        	tempSelect = guess[select];
        	guess[select] = guess[swap];
        	guess[swap] = tempSelect;
        	ignore[select] = true;
        }
    }

    if ( move == 3 )
    {
        int select = 0;
        int swap = 0;
        int swap2 = 0;
        char tempSelect;

        while( ignore[select] == true )
        {
            select = rand()%4;
        }

        while( ignore[swap] == true || swap == select )
        {
            swap = rand()%4;
        }
        while( ignore[swap2] == true || swap2 == select || swap2 == swap )
        {
            swap2 = rand()%4;
        }
        //cout << "Swapping " << select << " into "<< swap2 <<endl;
        //cout << "Swapping " << swap2 << " into "<< swap <<endl;
        //cout << "Swapping " << swap << " into "<< select <<endl;
        tempSelect = guess[select];

        guess[select] = guess[swap2];
        guess[swap2] = guess[swap];
        guess[swap] = tempSelect;


        ignore[select] = true;
        ignore[swap] = true;
        ignore[swap2] = true;

        for ( int i = 0; i < keep; i++ )
        {
            int select = 0;
            select = rand()%4;
            while ( ignore[select] == true )
            {
                select = rand()%4;
            }
            //cout << "Keeping: " << select <<endl;
            ignore[select] = true;
        }
    }
    if ( move == 2 )
    {
        int select = 0;
        int swap = 0;
        char tempSelect;
        while( ignore[select] == true )
        {
            select = rand()%4;
        }
        while( ignore[swap] == true || swap == select )
        {
            swap = rand()%4;
        }
        //cout << "Swapping " << swap << " into "<< select <<endl;
        //cout << "Swapping " <<select << " into " << swap <<endl;
        tempSelect = guess[select];
        guess[select] = guess[swap];
        guess[swap] = tempSelect;
        ignore[select] = true;
        ignore[swap] = true;

        for ( int i = 0; i < keep; i++ )
        {
            int select = 0;
            select = rand()%4;
            while ( ignore[select] == true )
            {
                select = rand()%4;
            }
            //cout << "Keeping: " << select <<endl;
            ignore[select] = true;
        }
    }
    if( move < 2 )
    {
        if ( move == 1 )
        {
            int select = 0;
            int swap = 0;
            while( ignore[select] == true )
            {
                select = rand()%4;
            }
            while( ignore[swap] == true || swap == select )
            {
                swap = rand()%4;
            }
            //cout << "Swapping " << swap << " into "<< select <<endl;
            guess[select] = guess[swap];
            ignore[select] = true;
        }
        for ( int i = 0; i < keep; i++ )
        {
            int select = 0;
            select = rand()%4;
            while ( ignore[select] == true )
            {
                select = rand()%4;
            }
            //cout << "Keeping: " << select <<endl;
            ignore[select] = true;
        }
    }

    for(int k = 0; k < 4; k++)
    {
        if ( ignore[k] == true )
        {
            ignore[k] = checkGuessElement(k);
        }
    }

    for (int m = 0; m < 4; m++)
    {
        if ( ignore[m] == false )
        {
            int temp = (rand()%colorArray.size());
            //cout << "Guess at " << m << " is " << guess[m]<<endl;
            //cout << "Colorarray at " << temp << " is " << colorArray[temp]<<endl;
            if ( guess[m] != colorArray[temp] )
            {
                 //cout << "Assigning temp" <<endl;
                 guess[m] = colorArray[temp];
            }
            else
            {
                int tempCA;
                tempCA = colorArray.size()-1;
                //cout<< "Assigning size - temp"<<endl;
                guess[m] = colorArray[tempCA-temp];
            }
        }
    }
}

void codebreaker::initializeColorArray()
{
    for(unsigned int i = 0; i < colorArray.size(); i++)
        colorArray.pop_back();

    colorArray.push_back('P');
    colorArray.push_back('R');
    colorArray.push_back('G');
    colorArray.push_back('B');
    colorArray.push_back('Y');
    colorArray.push_back('O');
}

char codebreaker::getBreakerGuess(int i)
{
    char c = guess[i];
    return c;
}

void codebreaker::displayGuess()
{
    cout << guess[0] << " " << guess[1] << " " << guess[2] << " " << guess[3] << "\n";
}

void codebreaker::initializeBreakerScoreArray()
{
    breakerScoreArray.resize(14);
    for (int i = 0; i < 14; ++i)
    {
        breakerScoreArray[i].resize(2);
    }
    breakerScoreArray[0][0] = 0;
    breakerScoreArray[0][1] = 1;
    breakerScoreArray[1][0] = 2;
    breakerScoreArray[0][2] = 3;
    breakerScoreArray[1][1] = 4;
    breakerScoreArray[2][0] = 5;
    breakerScoreArray[0][3] = 6;
    breakerScoreArray[1][2] = 7;
    breakerScoreArray[2][1] = 8;
    breakerScoreArray[3][0] = 9;
    breakerScoreArray[0][4] = 10;
    breakerScoreArray[1][3] = 11;
    breakerScoreArray[2][2] = 12;
    breakerScoreArray[4][0] = 13;
}

void codebreaker::setKeep(int i)
{
    keep=i;
}
void codebreaker::setMove(int i)
{
    move=i;
}
