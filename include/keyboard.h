#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keys.h"

class Keyboard
{
public:
  Keyboard();
  ~Keyboard();
  bool up(Key key) const;
  bool down(Key key) const;
  const Key* keys_down() const;
  void key(Key key, bool state);

private:
  bool keys_[256];
  unsigned int modifiers_;
};

#endif
