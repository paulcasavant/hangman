#ifndef HANGMAN__GAME_H_
#define HANGMAN__GAME_H_

#include <string>
#include <fstream>

class Game
{
 public:
  static std::string getWord();
 private:
  std::string word;
  ifstream inFile;
};

const static char* wordPath = "wordlist.txt";

#endif //HANGMAN__GAME_H_
