#ifndef HANGMAN__BODY_H_
#define HANGMAN__BODY_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

static int MAX_PARTS = 6;
static int NO_PARTS = 0;

/**
 * This class represents the body in a game of Hangman.
 */
class Body
{
 private:
  int _numParts;
  bool _hasParts;

 public:
  /**
   * Constructs a new Body.
   */
  Body();

  /*
   * Deconstructs a Body.
   */
  virtual ~Body();

  /*
   * Removes an appendage from the body if there is one to remove.
   */
  void removePart() ;

  /**
   * Returns true if this Body is deceased. This means there are no parts left
   * @return
   */
  bool isDead();

  /**
   * Returns a visual depiction of this Body as a string accurately reflecting
   * the number of parts it has currently.
   */
  string getASCII();
};

#endif //HANGMAN__BODY_H_
