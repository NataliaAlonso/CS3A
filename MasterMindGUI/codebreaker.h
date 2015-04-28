#ifndef CODEBREAKER_H
#define CODEBREAKER_H
#include "codemaker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;


class codebreaker
{
    public:
        codebreaker();
        ~codebreaker();
        codebreaker(const codebreaker& other);
        codebreaker& operator=(const codebreaker& other);

        char returnColor(int i);
        void createFirstGuess();
        void createGuess();
        void assignCFG();
        void assignGuess();
        void getScore(int score);
        void storeGuess();
        bool compareScore(int s);
        bool compareGuess();
        void removeColor();
        void setActions();
        bool checkGuessElement(int i);
        void performActions();
        char getBreakerGuess(int i);
        void initializeColorArray();
        void displayGuess();
        char guess[4];
        void initializeBreakerScoreArray();
        void setKeep(int i);
        void setMove(int i);

    private:
        char CFG[4];
        int keep, move;
        int score, tempScore;
        vector<char> colorArray;
        vector<string> guessArray;
        vector < vector<int> > breakerScoreArray;
};

#endif // CODEBREAKER_H
