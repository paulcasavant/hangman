/**
 * Ths class represents a game of hangman.
 */
#ifndef HANGMAN__GAME_H_
#define HANGMAN__GAME_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

static const string FILE_PATH = "/Users/paulcasavant/repos/hangman/wordlist.txt";

class Game
{
 private:
  vector<string> _dict;

 public:
  /**
   * Constructs a new Game of hangman.
   */
  Game(){};

  /**
   * Deconstructs a Game of hangman.
   */
  ~Game(){};

  /**
   * Reads the dictionary file into the game program.
   */
  void readDictionary();

  /**
   * Returns a random word from given dictionary.
   *
   * @return a random word from the dictionary.
   */
  string randomWord();
};

#endif //HANGMAN__GAME_H_
