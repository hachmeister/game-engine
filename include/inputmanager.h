#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <vector>

#include "keys.h"
#include "keyboard.h"
#include "mouse.h"

class KeyboardEvent
{
public:
  KeyboardEvent(Key _key, unsigned int _chr) : key(_key), chr(_chr) {}
  Key key;
  unsigned int chr;
};

class KeyboardListener
{
public:
  virtual void keyDown(KeyboardEvent& event) = 0;
  virtual void keyUp(KeyboardEvent& event) = 0;
};

class MousePositionEvent
{
public:
  MousePositionEvent(int _x, int _y) : x(_x), y(_y) {}
  int x;
  int y;
};

class MouseButtonEvent
{
public:
  MouseButtonEvent(int _button) : button(_button) {}
  int button;
};

class MouseListener
{
public:
  virtual void mouseMoved(MousePositionEvent& event) = 0;
  virtual void mouseDown(MouseButtonEvent& event) = 0;
  virtual void mouseUp(MouseButtonEvent& event) = 0;
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
