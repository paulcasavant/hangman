#ifndef HANGMAN__BODY_H_
#define HANGMAN__BODY_H_

#include <string>
#include <iostream>

using namespace std;

class Body
{
 public:

  /**
   * Constructs a man object.
   */
  Body();

  /*
   * Deconstructs a man object.
   */
  virtual ~Body();

  /*
   * Removes an appendage from the body.
   *
   * @return true if there was still a part available to remove.
   */
  bool removePart() const;

  void display();
};

#endif //HANGMAN__BODY_H_
