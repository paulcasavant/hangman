#include "Game.h"

Game::Game()
{
    readDictionary(); // Read the input file into the Game dictionary

    _theBody = new Body(); // Init the body
    _quit = false; // Don't quit initially
    _state = START; // Start state initially
    _word = randomizeWord();
    _numGuessed = 0;

    /* Init the guessed with the same number of FALSE booleans as the length
     * of the current word. */
    for (int i = 0; i < _word.length(); i++)
    {
        _guessed.push_back(false);
    }
}

void Game::clearScreen()
{
    // If running Windows
    #ifdef WINDOWS
        system("CLS");
    // Otherwise, running POSIX
    #else
        system ("clear");
    #endif
}

bool Game::run()
{
    switch(_state)
    {
        // Start state
        case START:
            displayTitle();
            cout << "\n Press ENTER to continue... ";
            getline(cin, _buffer);
            cout << "\n The prisoner has "
                    << condition() << " chances." << endl;
            sleep_for(chrono::milliseconds(DELAY));
            _state = INPUT;
            break;
        // Input state
        case INPUT:
            // If the game has been won or lost, go to the conclusion state
            if (loss() || victory())
            {
                _state = CONCLUSION;
            }
            else
            {
                clearScreen();
                displayBody();
                displayState();
                cout << "\n Guess: ";
                getline(cin, _buffer);
                transform(_buffer.begin(), _buffer.end(), _buffer.begin(),::tolower);
                _state = VALIDATE_INPUT;
            }
            break;
        // Check that input conforms to requirements
        case VALIDATE_INPUT:
            if (regex_match (_buffer, regex("[A-Za-z1-2?]")))
            {
                _state = INPUT_SWITCH;
            }
            else
            {
                cout << " Error: Invalid input." << endl;
                sleep_for(chrono::milliseconds(DELAY));
                _state = INPUT;
            }
            break;
        // Determine next state based on input
        case INPUT_SWITCH:
            // Usage statement
            if (_buffer == QUESTION_MARK)
            {
                _state = USAGE;
            }
            // Restart the game
            else if (_buffer == NUM_ONE)
            {
                _state = RESTART;
            }
            // Quit the game
            else if (_buffer == NUM_TWO)
            {
                _state = QUIT;
            }
            // Play the game
            else
            {
                _state = GUESS;
            }
            break;
        // Print usage statement
        case USAGE:
            cout << " Usage:\n"
                    "     a-z: Play\n"
                    "     1: Restart\n"
                    "     2: Quit" << endl;
            sleep_for(chrono::milliseconds(LONG_DELAY));
            break;
        // Restart the game
        case RESTART:
            cout << " You have started a new game." << endl;
            sleep_for(chrono::milliseconds(DELAY));
            restart(); // Reset game state
            _state = INPUT;
            break;
        // Terminate the game
        case QUIT:
            _quit = true;
            clearScreen();
            cout << " Thanks for playing!" << endl;
            break;
        // Attempt to match the given guess
        case GUESS:
            // If the guess has been previously attempted, print a message
            if ((_attempted.find(_buffer[0]) != _attempted.end()))
            {
                cout << " You already guessed that. Try again!" << endl;
                sleep_for(chrono::milliseconds(DELAY));
            }
            // Else if the guess was correct, print success message
            else if (guess(_buffer[0]))
            {
                cout << "Good job!" << endl;
                sleep_for(chrono::milliseconds(DELAY));
            }
            // Otherwise, print failure message
            else
            {
                // If condition is one, refer to "part" in the singular
                if (condition() == 1)
                {
                    cout << " Oops! The prisoner has "
                         << condition() << " chances left." << endl;
                }
                // Otherwise use "parts"
                else
                {
                    cout << " Ouch! The prisoner has "
                         << condition() << " chances left." << endl;
                }
                sleep_for(chrono::milliseconds(DELAY));
            }

            _attempted.insert(_buffer[0]); // Record the guess
            _state = INPUT; // Go back to start
            break;
        // Print loss or victory message and provide option to quit or restart
        case CONCLUSION:
            clearScreen();

            // If the game was lost, print defeat message
            if (loss())
            {
                displayBody();
                transform(_word.begin(), _word.end(), _word.begin(), ::toupper);
                cout << " The prisoner has died! The secret word was "
                << _word << "." << endl;
            }
            // Otherwise, game was won so print victory message
            else
            {
                _theBody->setFree(); // Display ASCII art of freed hangman
                displayBody();
                cout << " Congratulations. You have won!" << endl;
            }

            cout << " 1: Restart\n"
                    " 2: Quit\n"
                    " Select: ";
            getline(cin, _buffer);
            _state = VALIDATE_INPUT;
            break;
    }

    return !_quit;
}

void Game::readDictionary()
{
    string fileBuffer;
    ifstream aFile(FILE_PATH);

    if (aFile.is_open())
    {
        while (getline(aFile, fileBuffer))
        {
            _dict.push_back(fileBuffer);
        }
    }

    aFile.close();
}

string Game::randomizeWord()
{
    srand(time(nullptr)); // Set random generator seed
    return _dict.at(rand() % _dict.size() + 1);
}

bool Game::guess(char input)
{
    bool isMatch = false; // Assumes incorrect guess

    // See if the input character matches any part of the current word
    for (int i = 0; i < _word.length(); i++)
    {
        // If the input character is a match, establish record of it
        if (input == _word[i])
        {
            _guessed.at(i) = true;
            isMatch = true;
            _numGuessed++;
        }
    }

    // If the input character was not a match, degrade bodily condition
    if (!isMatch)
    {
        _theBody->removePart();
    }

    return isMatch; // Return TRUE if the guess was correct
}

bool Game::victory() const
{
    return _numGuessed == _word.length();
}

bool Game::loss()
{
    return _theBody->isDead();
}

int Game::condition()
{
    return _theBody->getCondition();
}

void Game::restart()
{
    /* Set the elements of the guessed vector to FALSE relative to the length
     * of the current word */
    for (int i = 0; i < _word.length(); i++)
    {
        _guessed.at(i) = false;
    }

    _word = randomizeWord(); // Assign a new random word

    /* If the new word is longer than the previous largest word, grow the
     * vector to size by pushing additional FALSE booleans */
    if (_word.length() > _guessed.size())
    {
        for (int i = 0; i < (_word.length() - _guessed.size()); i++)
        {
            _guessed.push_back(false);
        }
    }

    _numGuessed = 0;
    _theBody->reset(); // Restore the body to its original condition
    _attempted.clear();
}

void Game::displayState()
{
    cout << "\n ";

    // Print blanks and/or letters
    for (int i = 0; i < _word.size(); i++)
    {
        // If the current character was guessed, print it
        if (_guessed.at(i))
        {
            cout << _word[i];
        }
        // Otherwise, print a blank and set flag TRUE to avoid win condition
        else
        {
            cout << "-";
        }

        cout << "   "; // Space characters out
    }

    cout << endl;

    // If there are no more blanks, set the body free
    if (victory())
    {
        _theBody->setFree();
    }
}

void Game::displayBody()
{
    _theBody->displayASCII();
}

void Game::displayTitle()
{
    Game::clearScreen(); // Clear the screen

    cout << " $$\\   $$\\\n"
    " $$ |  $$ |\n"
    " $$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  $$$$$$$\\  \n"
    " $$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n"
    " $$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n"
    " $$  __$$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |\n"
    " $$ |  $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ |\n"
    " $$ |  $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$ |$$ |  $$ |\n"
    " \\__|  \\__| \\_______|\\__|  \\__| \\____$$ |\\__| \\__| \\__|\\_______|\\__|  \\__|\n"
    "                               $$\\   $$ |\n"
    " Usage:                        \\$$$$$$  |   by Paul Casavant\n"
    "     a-z: Play                  \\______/ \n"
    "     1: Restart\n"
    "     2: Quit" << endl;
}






