#ifndef HANGMAN__BODY_H_
#define HANGMAN__BODY_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum CONDITIONS { DEAD, ONE_PART, TWO_PARTS,
  THREE_PARTS, FOUR_PARTS, FIVE_PARTS, UNHARMED, FREED };

/**
 * This class represents the body in a game of Hangman.
 */
class Body
{
 private:
  int _condition;

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
  void removePart();

  /**
   * Free the hangman.
   */
  void setFree();

  /**
   * Returns true if this Body is deceased. This means there are no parts left
   * @return
   */
  bool isDead();

  /**
   * Restore Body to original condition.
   */
   void restoreBody();

   /**
    * Returns the condition of this Body.
    *
    * @return
    */
   int getCondition();

  /**
   * Prints a visual depiction of this Body that accurately reflects
   * the condition it is in.
   */
  void displayASCII() const;
};

#endif //HANGMAN__BODY_H_
