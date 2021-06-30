#include "Game.h"
#include <string>
#include <iostream>

/**
 * The driver for the game.
 *
 * @return EXIT_SUCCESS
 */
int main()
{
    Game *theGame = new Game(); // Init the game

    // Keep running until run() returns FALSE due to program termination
    while (theGame->run()){}

    return EXIT_SUCCESS;
}
