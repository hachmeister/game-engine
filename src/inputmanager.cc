#include "inputmanager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::addKeyboardListener(KeyboardListener* listener)
{
  keyboardlistener_.push_back(listener);
}

void InputManager::removeKeyboardListener(KeyboardListener* listener)
{
  std::vector<KeyboardListener*>::iterator it;
  for (it = keyboardlistener_.begin(); it != keyboardlistener_.end(); ) {
    if (*it == listener) {
      it = keyboardlistener_.erase(it);
    } else {
      ++it;
    }
  }
}

void InputManager::addMouseListener(MouseListener* listener)
{
  mouselistener_.push_back(listener);
}

void InputManager::removeMouseListener(MouseListener* listener)
{
  std::vector<MouseListener*>::iterator it;
  for (it = mouselistener_.begin(); it != mouselistener_.end(); ) {
    if (*it == listener) {
      it = mouselistener_.erase(it);
    } else {
      ++it;
    }
  }
}
