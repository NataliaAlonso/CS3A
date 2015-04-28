#ifndef CODEMAKER_H
#define CODEMAKER_H
#include "codebreaker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class codemaker
{
    public:
        codemaker();
        virtual ~codemaker();
        codemaker(const codemaker& other);
        codemaker& operator=(const codemaker& other);
        char returnColor(int i);
        void generateCode();
        bool evaluate();
        void prompt(int n);
        int convertScore(int i, int j);
        void userResult(bool b);
        void computerResult( bool b );
        void getUserInput();
        void computerPrompt(int n);
        int getScore();
        char guess[4];
        void setGuess(char c,int i);
        void displayGuess();
        void initializeScoreArray();
        int getPegs();
        int getColor();
        bool isValid();

    private:
        char code[4];
        int score;
        int convertedScore;
        int peg, color;
        vector < vector<int> > scoreArray;
};

#endif // CODEMAKER_H
