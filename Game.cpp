#include "Game.h"

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

/**
 * Returns a random word from the dictionary.
 *
 * @return a random word from the dictionary.
 */
string Game::randomWord()
{
    srand(time(nullptr)); // Set random generator seed
    return _dict.at(rand() % _dict.size() + 1); // Return random element
}

