#include "keyboard.h"

Keyboard::Keyboard()
{
  for (unsigned int i = 0; i < 256; ++i) {
    keys_[i] = false;
  }
}

Keyboard::~Keyboard()
{
}

bool Keyboard::up(Key key) const
{
  return !keys_[key];
}

bool Keyboard::down(Key key) const
{
  return keys_[key];
}

const Key* Keyboard::keys_down() const
{
  // TODO
  return 0;
}

void Keyboard::key(Key key, bool state)
{
  keys_[key] = state;
}
