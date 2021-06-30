/**
 * Ths class represents a game of hangman.
 */
#ifndef HANGMAN__GAME_H_
#define HANGMAN__GAME_H_

#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include "Body.h"

using namespace std;
using std::this_thread::sleep_for;

static const string TITLE =
        " $$\\   $$\\\n"
        " $$ |  $$ |\n"
        " $$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  $$$$$$$\\  \n"
        " $$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n"
        " $$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n"
        " $$  __$$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |\n"
        " $$ |  $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ |\n"
        " $$ |  $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$ |$$ |  $$ |\n"
        " \\__|  \\__| \\_______|\\__|  \\__| \\____$$ |\\__| \\__| \\__|\\_______|\\__|  \\__|\n"
        "                               $$\\   $$ |\n"
        " Usage:                        \\$$$$$$  |   by Paul Casavant\n"
        "   - a-z: Play                  \\______/ \n"
        "   - 1: Restart\n"
        "   - 2: Quit\n"
        "   - Enter the entire word at any time.\n\n";
static const string FILE_PATH = "./wordlist.txt"; // File lines sorted by length
static const string INPUT_ERROR = " Error: Invalid input.";
static const string REGEX_YES = "[yY]|[yY][eE][sS]";
static const string REGEX_NO = "[nN]|[nN][oO]";
static const string REGEX_WORD ="[a-zA-Z]{2,}";
static const string REGEX_VALID_CHARS = "[a-zA-Z1-2?]";
static const string IGNORED_CHARS = ".,/ \n\t";
static const string STR_ONE = "1";
static const string STR_TWO = "2";
static const string QUESTION_MARK = "?";
static const int DELAY = 550;
static const int ONE = 1;

enum STATES { TITLE_SCREEN, INIT, SET_LENGTH, WIN_OR_LOSS, GET_INPUT, CHAR_INPUT,
    WORD_INPUT, USAGE, RESTART, QUIT, CHECK_GUESS, EPILOGUE, VALIDATE_INPUT};

/**
 * This class is a game of Hangman complete with ASCII art.
 *
 * @author Paul Casavant
 */
class Game
{
 private:
  Body *_theBody;
  string _word;
  string _buffer;
  bool _quit;
  int _numGuessed;
  int _maxWordLength;
  unordered_set<char> _attempted; // Records all attempted character guesses
  vector<bool> _guessed; // Parallel to word string; tracks guessed indices
  STATES _state;
  unordered_map<int, int> _lengthIndex; // Map word len to starting dict index
  vector<string> _dict;

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
   * Clears the console screen on both Windows and POSIX systems.
   */
  static void clearScreen();

  /**
   * Runs the game.
   *
   * @return true if the game should keep running
   */
  bool run();

  /**
   * Reads the dictionary file into the game program.
   */
  void readDictionary();

  /**
   * Returns a random word from the dictionary and sets it as the current
   * word.
   */
  string getRandomWord();

  /**
   * Checks the specified character against the word and returns true if the
   * guess matched any part of the word. Records correct guesses.
   *
   * @param input the specified character
   * @return true if the guess was a match
   */
  bool guess(char input);

  /**
   * True if this Game has been won.
   *
   * @return true if the game has been won
   */
  bool victory() const;

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

  void restart();

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
};

#endif //HANGMAN__GAME_H_
