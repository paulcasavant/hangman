/**
 * Ths class represents a game of hangman.
 */
#ifndef HANGMAN__GAME_H_
#define HANGMAN__GAME_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include "Body.h"

using namespace std;

static const string FILE_PATH = "/Users/paulcasavant/repos/hangman/wordlist.txt";

/**
 * This class represents a Game of hangman.
 */
class Game
{
 private:
  Body *_theBody;
  string _currentWord;
  bool _victory;
  vector<string> _dict;
  vector<bool> _guessed; // Parallel to word string; tracks guessed indices
  unordered_set<char> _attempted; // Records all attempted character guesses

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
  void randomizeWord();

  /**
   * Returns the current word.
   *
   * @return the current word.
   */
  string getCurrentWord();

  /**
   * Checks the specified character against the word and updates the guessed
   * vector where any matches are found.
   *
   * @param input the specified character
   * @return true if the guess has not been previously attempted
   */
  bool guess(char input);

  // todo: need this?
  /**
   * True if this Game has been won.
   *
   * @return true if the game has been won
   */
  bool victory();

  /**
   * True if this Game has been lost.
   *
   * @return true if the game has been lost
   */
   bool loss();

   /**
    * Returns the condition of the body as an integer.
    *
    * @return the condition of the body as an integer.
    */
   int condition();

  void restartGame();

  /**
   * Displays a visual representation of the body.
   */
  void displayBody();

  /**
   * Displays the current state of the letter blanks as well as messages
   * about the game status.
   *
   * If a blanks is not printed, win condition flag is set TRUE.
   */
  void displayState();

  /**
   * Display the title screen of the game.
   */
  void displayTitle();
};

#endif //HANGMAN__GAME_H_
