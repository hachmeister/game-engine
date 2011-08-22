#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <CEGUI/CEGUI.h>
#include <OGRE/Ogre.h>

#include "inputmanager.h"
#include "state.h"

class IntroData
{
public:
  int x;
  int y;
};

class IntroState : public State, public KeyboardListener, public MouseListener
{
public:
  IntroState();
  ~IntroState();
  void init();
  void cleanup();
  void update(float delta);
  void draw(float alpha);
  void keyDown(KeyboardEvent& event);
  void keyUp(KeyboardEvent& event);
  void mouseMoved(MousePositionEvent& event);
  void mouseDown(MouseButtonEvent& event);
  void mouseUp(MouseButtonEvent& event);
  bool exit(const CEGUI::EventArgs& args);
  
private:
  IntroData pdata;
  IntroData cdata;
  Ogre::Root* root_;
  Ogre::SceneManager* scene_;
  Ogre::Camera* camera_;
  Ogre::Viewport* viewport_;
};

#endif
