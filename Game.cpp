#include "Game.h"

Game::Game()
{
    _theBody = new Body(); // Init the body
    readDictionary(); // Read the input file into the Game dictionary
    randomWord(); // Get the first random word
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

void Game::randomWord()
{
    srand(time(nullptr)); // Set random generator seed
    _currentWord = _dict.at(rand() % _dict.size() + 1);
}

string Game::getCurrentWord()
{
    return _currentWord;
}

bool Game::makeMove(string word)
{
    return false;
}

void Game::restartGame()
{
    randomWord();
    displayState();
}

void Game::displayState()
{
    cout << _theBody->getASCII() << endl;
}

void Game::displayTitle()
{
    cout << "***********************" << endl;
    cout << "* Welcome to Hangman! *" << endl;
    cout << "***********************" << endl;
    cout << "Usage: Enter a letter to play, 1 to start a new game, or 2"
            " to restart the game." <<
    endl;
}





