#include "codebreaker.h"
#include "codemaker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

codemaker::codemaker()
{
    initializeScoreArray();
}

codemaker::~codemaker()
{
    //dtor
}

char codemaker::returnColor(int i)
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

void codemaker::generateCode()
{
    srand(time(NULL));
    for ( int i = 0; i < 4; i++)
    {
        int temp = (rand()%6)+1;
        code[i] = returnColor(temp);
    }
}

bool codemaker::evaluate()
{
    //cout<<"\nBegin evaluation: "<<endl;
    int correctPeg = 0;
    int correctColor = 0;
    int select = 0;
    bool ignore[4];
    bool ignoreColor[4];
    bool inList = false;

    for (int i = 0; i < 4; i++)
    {
        ignore[i] = false;
        ignoreColor[i] = false;
    }

    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == code[i])
        {
            correctPeg++;
            ignore[i] = true;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (!ignore[i])
        {
            for (int j = 0; j < 4; j++)
            {
                if (!ignore[j] && i != j)
                {
                    if ((guess[i] == code[j]) && !ignoreColor[j])
                    {
                    inList = true;
                    select = j;
                    }
                }
            }
            if (inList)
            {
                correctColor++;
                inList = false;
                ignoreColor[select] = true;
            }
        }

    }

    //cout << "Converting score." << endl;
    score = convertScore(correctPeg, correctColor);
    //cout << "Done converting score." << endl;

    if ( score == 13)
    {
        cout << "The score is: [ " << correctPeg << ", " << correctColor<< " ]"<< endl << endl;
        return true;
    }
    else
    {
        cout << "The score is: [ " << correctPeg << ", " << correctColor<< " ]"<< endl << endl;
        return false;
    }
}

void codemaker::prompt(int n)
{
    cout <<"\n"<< n << " guesses left!! Enter guess:";
    cin >> guess[0] >> guess[1] >> guess [2] >> guess [3];
    for(int i = 0; i < 4; i++)
    {
        guess[i] = toupper(guess[i]);
    }

}

int codemaker::convertScore(int i, int j)
{
    peg = i;
    color = j;
    convertedScore = scoreArray[i][j];
    //cout << "Codemaker converted score is " << convertedScore <<endl;
    return convertedScore;
}

void codemaker::userResult( bool b )
{
    if(b)
        cout << "You win! The correct sequence was " << code[0] << " " << code[1]
             << " " << code[2] << " " << code[3] << endl;
    else
        cout << "You lost! :( The correct sequence was " << code[0] << " " << code[1]
             << " " << code[2] << " " << code[3] << endl;
}

void codemaker::computerResult( bool b )
{
    if(b)
        cout << "Computer wins!" <<endl;
    else
        cout << "Computer lost! :( " <<endl;
}

void codemaker::getUserInput()
{
    do{
    cout << "Please enter your code and the computer will try to break it:";
    cin >> code[0] >> code[1] >> code[2] >> code[3];
    for(int i = 0; i < 4; i++)
    {
        code[i] = toupper(code[i]);
    }
    }while(!isValid());

}

void codemaker::computerPrompt(int n)
{
    cout <<"\n"<< n << " guesses left!!" << guess[0] << " " << guess[1] << " " << guess[2] << " " << guess[3] << "\n";

}

int codemaker::getScore()
{
    return score;
}

void codemaker::setGuess(char c, int i)
{
    guess[i] = c;
}

void codemaker::displayGuess()
{
    //cout << "Codemaker received guess: " << guess[0] << " " << guess[1] << " " << guess[2] << " " << guess[3];
}

void codemaker::initializeScoreArray()
{
    scoreArray.resize(14);
    for (int i = 0; i < 14; ++i)
    {
        scoreArray[i].resize(2);
    }
    scoreArray[0][0] = 0;
    scoreArray[0][1] = 1;
    scoreArray[1][0] = 2;
    scoreArray[0][2] = 3;
    scoreArray[1][1] = 4;
    scoreArray[2][0] = 5;
    scoreArray[0][3] = 6;
    scoreArray[1][2] = 7;
    scoreArray[2][1] = 8;
    scoreArray[3][0] = 9;
    scoreArray[0][4] = 10;
    scoreArray[1][3] = 11;
    scoreArray[2][2] = 12;
    scoreArray[4][0] = 13;
}

int codemaker::getPegs()
{
    return peg;
}

int codemaker::getColor()
{
    return color;
}

bool codemaker::isValid()
{
    bool result;
    string codeString;
    for( unsigned int i = 0; i < 4; i++)
    {
        codeString.push_back(code[i]);
    }
    for( unsigned int i = 0; i < 6; i++)
    {
        int pos = codeString.find_first_not_of("RGBYOP",0);
        if (codeString.length()!= 4 || pos != -1)
        {
            cout << "Invalid code. Please re-enter." << endl;
            result = false;
            break;
        }
        else
            result = true;
    }

    return result;
}
