#include "Game.h"

Game::Game()
{
    _theBody = new Body(); // Init the body
    _victory = false; // No victory initially
    readDictionary(); // Read the input file into the Game dictionary
    randomizeWord(); // Get the first random word

    /* Init the guessed with the same number of FALSE booleans as the length
     * of the current word. */
    for (int i = 0; i < _currentWord.length(); i++)
    {
        _guessed.push_back(false);
    }
}

void Game::readDictionary()
{
    string buffer;
    ifstream aFile(FILE_PATH);

    if (aFile.is_open())
    {
        while (getline(aFile, buffer))
        {
            _dict.push_back(buffer);
        }
    }

    aFile.close();
}

void Game::randomizeWord()
{
    srand(time(nullptr)); // Set random generator seed
    _currentWord = _dict.at(rand() % _dict.size() + 1);
}

string Game::getCurrentWord()
{
    return _currentWord;
}

bool Game::guess(char input)
{
    bool isMatch = false; // Assumes that the guess is not successful
    bool isRedundant = false; // Assumes that the guess is not redundant

    // If the guess was previously attempted, make note of it
    if (_attempted.find(input) != _attempted.end())
    {
        isRedundant = true;
    }
    // Otherwise, see if the guess is a match
    else
    {
        // See if the input character matches any part of the current word
        for (int i = 0; i < _currentWord.length(); i++)
        {
            // If the input character matches a character of the current word
            if (input == _currentWord[i])
            {
                _guessed.at(i) = true;
                isMatch = true;
            }
        }

        _attempted.insert(input); // Record the guess attempt
    }

    // If the input character was not a match, decrease bodily condition
    if (!isMatch && !isRedundant)
    {
        _theBody->removePart();
    }

    return !isRedundant; // Return TRUE if the guess was not redundant
}

bool Game::victory()
{
    return _victory;
}

bool Game::loss()
{
    return _theBody->isDead();
}

int Game::condition()
{
    return _theBody->getCondition();
}

void Game::restartGame()
{
    /* Set the elements of the guessed vector to FALSE relative to the length
     * of the current word */
    for (int i = 0; i < _currentWord.length(); i++)
    {
        _guessed.at(i) = false;
    }

    randomizeWord(); // Assign a new random word

    /* If the new word is longer than the previous largest word, grow the
     * vector to size by pushing additional FALSE booleans */
    if (_currentWord.length() > _guessed.size())
    {
        for (int i = 0; i < (_currentWord.length() - _guessed.size()); i++)
        {
            _guessed.push_back(false);
        }
    }

    _theBody->restoreBody(); // Restore the body to its original condition
    _attempted.clear(); // Clear record of attempted guesses
    displayBody(); // Display the updated representation of the body
    displayState(); // Display the updated state of the game
}

void Game::displayState()
{
    bool hasBlanks = false; // Assumes a victory; that there are no blanks

    // Print blanks and/or letters
    for (int i = 0; i < _currentWord.size() - 1; i++)
    {
        // If the current character was guessed, print it
        if (_guessed.at(i))
        {
            cout << _currentWord[i];
        }
        // Otherwise, print a blank and set flag TRUE to avoid win condition
        else
        {
            cout << "-";
            hasBlanks = true; // A blank was printed so therefore no victory
        }

        cout << "   "; // Space characters out
    }

    cout << endl;

    _victory = !hasBlanks; // If there were no blanks to print, victory is TRUE

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
    cout << "$$\\   $$\\\n"
    "$$ |  $$ |\n"
    "$$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  $$$$$$$\\  \n"
    "$$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n"
    "$$  __$$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |\n"
    "$$ |  $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ |\n"
    "$$ |  $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$ |$$ |  $$ |\n"
    "\\__|  \\__| \\_______|\\__|  \\__| \\____$$ |\\__| \\__| \\__| \\_______|\\__|  \\__|\n"
    "                              $$\\   $$ |\n"
    "Usage:                        \\$$$$$$  |\n"
    "    a-z: Play                  \\______/ \n"
    "    1: Restart\n"
    "    2: Quit" << endl;
}





