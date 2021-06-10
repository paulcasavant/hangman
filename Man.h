#ifndef HANGMAN__MAN_H_
#define HANGMAN__MAN_H_

class Man
{
 public:

  /**
   * Constructs a man object.
   */
  Man();

  /*
   * Deconstructs a man object.
   */
  virtual ~Man();

  /*
   * Removes an appendage from the man.
   *
   * @return true if there was still a part available to remove.
   */
  bool removePart() const;
};

#endif //HANGMAN__MAN_H_
