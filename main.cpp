#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Body.h"

using namespace std;

const char *FILE_PATH = "/Users/paulcasavant/repos/hangman/wordlist.txt";

int main()
{
    string buffer;
    vector<string> dict;
    ifstream aFile(FILE_PATH);

    if (aFile.is_open())
    {
        while (getline(aFile, buffer))
        {
            dict.push_back(buffer);
        }
    }

    // Get random word
    srand(time(nullptr)); // Set random generator seed
    cout << dict.at(rand() % dict.size() + 1) << endl;

    Body* aBody = new Body();
    aBody->display();

    return 0;
}

