/**
 * Ths class represents a game of hangman.
 */
#ifndef HANGMAN__GAME_H_
#define HANGMAN__GAME_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Body.h"

using namespace std;

static const string FILE_PATH = "/Users/paulcasavant/repos/hangman/wordlist.txt";

/**
 * This class represents a Game of hangman.
 */
class Game
{
 private:
  vector<string> _dict;
  string _currentWord;
  Body *_theBody;

 public:
  /**
   * Constructs a new Game of hangman.
   */
  Game();

  /**
   * Deconstructs a Game of hangman.
   */
  ~Game();

  /**
   * Reads the dictionary file into the game program.
   */
  void readDictionary();

  /**
   * Returns a random word from given dictionary and sets it as the current
   * word.
   */
  void randomWord();

  /**
   * Returns the current word.
   *
   * @return the current word.
   */
  string getCurrentWord();

  bool makeMove(string word);

  void restartGame();

  /**
   * Display the current state of the game.
   */
  void displayState();

  /**
   * Display the title screen of the game.
   */
  void displayTitle();
};

#endif //HANGMAN__GAME_H_
