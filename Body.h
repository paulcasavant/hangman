#ifndef HANGMAN__BODY_H_
#define HANGMAN__BODY_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum STATUS { DEAD, SIX_PARTS, FIVE_PARTS,
    FOUR_PARTS, THREE_PARTS, TWO_PARTS, ONE_PART, ZERO_PARTS, FREE };

/**
 * This class represents the hangman's body in the game of Hangman.
 *
 * @author Paul Casavant
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
  bool isDead() const;

  /**
   * Restore Body to original condition.
   */
   void reset();

   /**
    * Returns the condition of this Body.
    *
    * @return
    */
   int getCondition() const;

  /**
   * Prints a visual depiction of this Body that accurately reflects
   * the condition it is in.
   */
  void displayASCII() const;
};

#endif //HANGMAN__BODY_H_
