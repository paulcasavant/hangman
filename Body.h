/**
 * This class represents the body in a game of Hangman.
 */
#ifndef HANGMAN__BODY_H_
#define HANGMAN__BODY_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int MAX_PARTS = 6;
int NO_PARTS = 0;


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
   * Prints out a visual depiction of this Body reflecting the number of
   * parts it has currently.
   */
  void display();
};

#endif //HANGMAN__BODY_H_
