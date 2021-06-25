#include "Game.h"

/**
 * The driver for the game.
 */
int main()
{
    Game *theGame = new Game(); // Init the game

    // Keep running until run() returns FALSE due to command termination.
    while (theGame->run()){ }

    return 0;
}

