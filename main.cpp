#include <iostream>
#include "Game.h" // todo: remove

using namespace std;

int main()
{
    Game* theGame = new Game();

    cout << "Welcome to Hangman!" << endl;
    cout << theGame->getWord() << endl;
    return 0;
}


