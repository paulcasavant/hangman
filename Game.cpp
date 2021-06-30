#include "Game.h"

Game::Game()
{
    readDictionary(); // Read the input file into the Game dictionary
    srand(time(nullptr)); // Set random number generator seed

    _theBody = new Body(); // Init the body
    _quit = false; // Don't quit initially
    _state = TITLE_SCREEN; // Start game at title screen
    _word = "";
    _numGuessed = 0;
    _maxWordLength = 0;
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
    string responseBuffer;

    switch(_state)
    {
        // Display the title screen of the game
        case TITLE_SCREEN:
            clearScreen();
            cout << TITLE;
            cout << " Press ENTER to continue... ";
            getline(cin, _buffer);
            _state = SET_LENGTH;
            break;
        case SET_LENGTH:
            clearScreen();
            cout << TITLE;
            cout << " Enter Maximum Word Length [3-9]: ";
            getline(cin, _buffer);

            while (!regex_match (_buffer, regex("[3-9]")))
            {
                cout << " Please enter a valid number." << endl;
                sleep_for(chrono::milliseconds(DELAY));
                clearScreen();
                cout << TITLE;
                cout << " Enter Maximum Word Length [3-9]: ";
                getline(cin, _buffer);
            }

            _maxWordLength = stoi(_buffer); // Set max word length for game
            _state = INIT;
            break;
        // Finish initializing game after word length set by user
        case INIT:
            _word = getRandomWord(); // Must set word length before this call

            while (_guessed.size() < _word.length())
            {
                _guessed.push_back(false);
            }

            _state = WIN_OR_LOSS;
            break;
        // Check if game won or lost before getting input
        case WIN_OR_LOSS:
            if (loss() || victory())
            {
                _state = EPILOGUE;
            }
            else
            {
                _state = GET_INPUT;
            }
            break;
        // Input state
        case GET_INPUT:
            clearScreen();
            displayBody();
            displayState();
            cout << "\n Guess: ";
            getline(cin, _buffer);
            transform(_buffer.begin(), _buffer.end(), _buffer.begin(),::tolower);
            _state = VALIDATE_INPUT;
            break;
        // Check that input conforms to requirements
        case VALIDATE_INPUT:
            if (regex_match (_buffer, regex(REGEX_VALID_CHARS)))
            {
                _state = CHAR_INPUT;
            }
            else if (regex_match (_buffer, regex(REGEX_WORD)))
            {
                _state = WORD_INPUT;
            }
            else
            {
                cout << INPUT_ERROR << endl;
                sleep_for(chrono::milliseconds(DELAY));
                _state = GET_INPUT;
            }
            break;
        // Handle input of a single character
        case CHAR_INPUT:
            // Usage statement
            if (_buffer == QUESTION_MARK)
            {
                _state = USAGE;
            }
            // Restart the game
            else if (_buffer == STR_ONE)
            {
                _state = RESTART;
            }
            // Quit the game
            else if (_buffer == STR_TWO)
            {
                _state = QUIT;
            }
            // Play the game
            else
            {
                _state = CHECK_GUESS;
            }
            break;
        // Handle input of an entire word
        case WORD_INPUT:
        {
            string response;
            cout << " Continue? [y/n]?: ";
            getline(cin, response);

            if (regex_match (response, regex(REGEX_YES)))
            {
                /*
                 * Trim periods, commas, slashes, spaces, newlines, and tabs
                 * from beginning and end of word
                 */
                _buffer.erase(0, _buffer.find_first_not_of(IGNORED_CHARS));
                _buffer.erase(_buffer.find_last_not_of(IGNORED_CHARS) + 1);

                // If the input buffer is the same as the current word
                if (_buffer == _word)
                {
                    _numGuessed = _word.length();
                }
            }
            else if (!regex_match (response, regex(REGEX_NO)))
            {
                cout << INPUT_ERROR << endl;
                sleep_for(chrono::milliseconds(DELAY));
            }

            _state = WIN_OR_LOSS;
            break;
        }
        // Print usage statement
        case USAGE:
            clearScreen();
            cout << TITLE;
            cout << " Press ENTER to return... ";
            getline(cin, _buffer);
            _state = GET_INPUT;
            break;
        // Restart the game
        case RESTART:
            cout << " You have started a new game." << endl;
            sleep_for(chrono::milliseconds(DELAY));
            restart(); // Reset game state
            _state = WIN_OR_LOSS;
            break;
        // Terminate the game
        case QUIT:
            _quit = true;
            clearScreen();
            cout << " Thanks for playing!" << endl;
            break;
        // Attempt to match the guess the user entered
        case CHECK_GUESS:
            // If the guess has been previously attempted, print a message
            if ((_attempted.find(_buffer[0]) != _attempted.end()))
            {
                cout << " You already guessed that. Try again!" << endl;
                sleep_for(chrono::milliseconds(DELAY));
            }
            // Else if the guess was correct, print success message
            else if (guess(_buffer[0]))
            {
                cout << " Nice job!" << endl;
                sleep_for(chrono::milliseconds(DELAY));
            }
            // Otherwise, print failure message
            else
            {
                // If condition is one, refer to "part" in the singular
                if (condition() == ONE)
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
            _state = WIN_OR_LOSS;
            break;
        // Print loss or victory message and provide option to quit or restart
        case EPILOGUE:
            clearScreen();
            transform(_word.begin(), _word.end(), _word.begin(), ::toupper);

            // If the game was lost, print defeat message
            if (loss())
            {
                displayBody();
                cout << " The prisoner has died! The secret word was "
                << _word << "." << endl;
            }
            // Otherwise, game was won so print victory message
            else
            {
                _theBody->setFree(); // Display ASCII art of freed hangman
                displayBody();
                cout << " You have won! The secret word was "
                << _word << "." << endl;
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
    string wordBuffer;
    ifstream aFile(FILE_PATH);

    if (aFile.is_open())
    {
        while (getline(aFile, wordBuffer))
        {
            _dict.push_back(wordBuffer);
            _lengthIndex[wordBuffer.length()] = _dict.size() - 1;
        }
    }

    aFile.close();
}

string Game::getRandomWord()
{
    return _dict.at(rand() % _lengthIndex[_maxWordLength] + 1); // Random bounded by max size
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
    /*
     * Set the elements of the guessed vector to FALSE relative to the length
     * of the current word.
     */
    for (int i = 0; i < _word.length(); i++)
    {
        _guessed.at(i) = false;
    }

    _word = getRandomWord(); // Assign a new random word

    /*
     * If the new word is longer than the previous largest word, grow the
     * vector to size by pushing additional FALSE booleans.
     */
    while (_word.length() > _guessed.size())
    {
        _guessed.push_back(false);
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
}

void Game::displayBody()
{
    _theBody->displayASCII();
}
