#include "codebreaker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    bool play = true;
    while(play)
    {
        cout << "Think of a code and the computer will try to guess." <<endl;
        bool win = false;
        int guesses=10;
        char choice;
        codebreaker newGame;
        newGame.createFirstGuess();
        while( !win && guesses > 0)
        {
        newGame.storeGuess();
        cout<< "Guess # " << guesses << " :";
        newGame.displayGuess();
        cout << "\nPlease enter score." <<endl;
        int score;
        cin >> score;
        if ( score == 13 )
        {
            win = true;
            break;
        }
        newGame.getScore(score);
        newGame.createGuess();
        guesses--;
        }

        if(win)
        cout << "Computer wins!" <<endl;
        else
        cout << "Computer lost! :( " <<endl;

        cout << "Play again? Y or N" << endl;
        cin >> choice;
        choice = toupper(choice);
        play = (choice == 'Y') ? true : false;
    }
    exit(0);
}
