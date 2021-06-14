#include <iostream>
#include "Game.h"

using namespace std;

/**
 * The driver for the Hangman game.
 */
int main()
{
    Game *theGame = new Game();
    theGame->readDictionary();

    cout << theGame->randomWord();

    return 0;
}

