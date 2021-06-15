#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

static string ONE = "1";
static string TWO = "2";

/**
 * The driver for the Hangman game.
 */
int main()
{
    string input;
    bool quit = false;
    Game *theGame = new Game(); // Create a new game

    theGame->displayTitle(); // Display the title screen of the game

    while (!quit)
    {
        cin >> input;

        if (input == ONE)
        {
            quit = true;
        }
        else if (input == TWO)
        {

        }
        else
        {
            cout << input << endl;
        }
    }

    return 0;
}

