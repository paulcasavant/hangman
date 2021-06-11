#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

const char *FILE_PATH = "/Users/paulcasavant/repos/hangman/wordlist.txt";

int main()
{
    string word;
    vector<string> dict;
    ifstream aFile(FILE_PATH);

    if (aFile.is_open())
    {
        while (getline(aFile, word))
        {
            dict.push_back(word);
        }
    }

    // Get random word
    srand(time(nullptr)); // Set random generator seed
    cout << dict.at(rand() % dict.size() + 1) << endl;

    return 0;
}

