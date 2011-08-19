#include "oisinputmanager.h"

#include <iostream>

OISInputManager::OISInputManager()
  : ois_inputmanager_(0),
    ois_keyboard_(0),
    ois_mouse_(0)
{
}

OISInputManager::~OISInputManager()
{
  if (ois_inputmanager_) {
    if (ois_keyboard_) {
      ois_inputmanager_->destroyInputObject(ois_keyboard_);
    }
    
    if (ois_mouse_) {
      ois_inputmanager_->destroyInputObject(ois_mouse_);
    }
    
    ois_inputmanager_->destroyInputSystem(ois_inputmanager_);
  }
}

void OISInputManager::init(size_t windowHnd)
{
  ois_inputmanager_ = OIS::InputManager::createInputSystem(windowHnd);
  ois_keyboard_ = static_cast<OIS::Keyboard*>(ois_inputmanager_->createInputObject(OIS::OISKeyboard, true));
  ois_keyboard_->setEventCallback(this);
  ois_mouse_ = static_cast<OIS::Mouse*>(ois_inputmanager_->createInputObject(OIS::OISMouse, true));
  ois_mouse_->setEventCallback(this);
}

void OISInputManager::update()
{
  if (ois_keyboard_) {
    ois_keyboard_->capture();
  }
  
  if (ois_mouse_) {
    ois_mouse_->capture();
  }
}

Keyboard OISInputManager::keyboard() const
{
  return keyboard_;
}

Mouse OISInputManager::mouse() const
{
  return mouse_;
}

bool OISInputManager::keyPressed(const OIS::KeyEvent& e)
{
  Key key = (Key)e.key;
  
  std::vector<KeyboardListener*>::iterator it;
  for (it = keyboardlistener_.begin(); it != keyboardlistener_.end(); ++it) {
    (*it)->keyDown(key);
  }
  
  return true;
}

bool OISInputManager::keyReleased(const OIS::KeyEvent& e)
{
  Key key = (Key)e.key;
  
  std::vector<KeyboardListener*>::iterator it;
  for (it = keyboardlistener_.begin(); it != keyboardlistener_.end(); ++it) {
    (*it)->keyUp(key);
  }
  
  return true;
}

bool OISInputManager::mouseMoved(const OIS::MouseEvent& e)
{
  return true;
}

bool OISInputManager::mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{
  return true;
}

bool OISInputManager::mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{
  return true;
}
