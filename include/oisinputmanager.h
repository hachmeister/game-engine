#ifndef OIS_INPUT_MANAGER_H
#define OIS_INPUT_MANAGER_H

#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>

#include <OGRE/Ogre.h>

#include "inputmanager.h"
#include "keyboard.h"
#include "mouse.h"

class OISInputManager
  : public InputManager, public OIS::KeyListener, OIS::MouseListener
{
public:
  OISInputManager();
  ~OISInputManager();
  void init(size_t windowHnd);
  void update();
  Keyboard keyboard() const;
  Mouse mouse() const;
  bool keyPressed(const OIS::KeyEvent& e);
  bool keyReleased(const OIS::KeyEvent& e);
  bool mouseMoved(const OIS::MouseEvent& e);
  bool mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id);
  bool mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id);
  
private:
  Keyboard keyboard_;
  Mouse mouse_;
  OIS::InputManager* ois_inputmanager_;
  OIS::Keyboard* ois_keyboard_;
  OIS::Mouse* ois_mouse_;
};

#endif
