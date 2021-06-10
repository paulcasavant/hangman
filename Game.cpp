#include "Game.h"
#include <fstream>
#include <iostream>
#include <string>

std::string Game::getWord()
{
    std::ifstream wordFile (wordPath);
    wordFile.op
    std::string name;
    std::getline(wordFile, name);
    std::cout << name << std::endl;
}


