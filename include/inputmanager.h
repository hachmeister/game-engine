#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <vector>

#include "keys.h"
#include "keyboard.h"
#include "mouse.h"

class KeyboardListener
{
public:
  virtual void keyDown(Key key) = 0;
  virtual void keyUp(Key key) = 0;
};

class MouseListener
{
public:
  virtual void mouseMoved(int x, int y) = 0;
};

class InputManager
{
public:
  InputManager();
  virtual ~InputManager();
  virtual void update() = 0;
  virtual Keyboard keyboard() const = 0;
  virtual Mouse mouse() const = 0;
  void addKeyboardListener(KeyboardListener* listener);
  void removeKeyboardListener(KeyboardListener* listener);
  void addMouseListener(MouseListener* listener);
  void removeMouseListener(MouseListener* listener);
  
protected:
  std::vector<KeyboardListener*> keyboardlistener_;
  std::vector<MouseListener*> mouselistener_;
};

#endif
