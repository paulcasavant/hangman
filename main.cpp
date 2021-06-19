#include <iostream>
#include <string>
#include <regex>
#include "Game.h"

using namespace std;

enum STATES { START, PLAY, RESTART, QUIT};

static string ONE = "1";
static string TWO = "2";

/**
 * The driver for the Hangman game.
 */
int main()
{
    string buffer; // Buffer for user input
    bool quit = false; // Set to keep running initially
    Game *theGame = new Game(); // Init the game
    int state = START;

    //theGame->displayTitle(); // Display the title screen of the game

    while (!quit)
    {

        theGame->displayBody();
        theGame->displayState();
        cout << "Guess: ";
        cin >> buffer;

        if (!regex_match (buffer, regex("[A-Za-z1-2]")))
        {
            cout << "Error: Invalid input." << endl;
        }
        else
        {
            // Restart the game
            if (buffer == ONE)
            {
                theGame->restartGame();
                cout << "You have started a new game." << endl;
            }
            // Quit the game
            else if (buffer == TWO)
            {
                quit = true;
                cout << "Thanks for playing!" << endl;
            }
            // Play the game
            else
            {
                // If the guess has been previously attempted, print a message
                if (!theGame->guess(buffer[0]))
                {
                    cout << "You already guessed that. Try again!" << endl;
                }
                else
                {
                    if (theGame->victory() || theGame->loss())
                    {
                        // If the game has been won, print a victory message
                        if (theGame->victory())
                        {
                            cout << "Congratulations! You have won." << endl;
                        }
                            // If the game has been lost, print a loss message
                        else if (theGame->loss())
                        {
                            cout << "The prisoner has died. Play again!" << endl;
                            theGame->displayBody();
                        }

                        cout << "1: Restart\n"
                                "2: Quit." << endl;
                    }
                    else
                    {
                        cout << "Oops! The prisoner now has "
                             << theGame->condition() << " body parts left."
                             << endl;
                    }
                }
            }
        }
    }

    return 0;
}
