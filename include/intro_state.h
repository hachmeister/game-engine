#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <OGRE/Ogre.h>

#include "state.h"

class IntroData
{
public:
  int x;
  int y;
};

class IntroState : public State
{
public:
  IntroState();
  ~IntroState();
  
  void init();
  void cleanup();
  
  void update(float delta);
  void draw(float alpha);
  
private:
  IntroData pdata;
  IntroData cdata;
  
  Ogre::Root* root_;
  Ogre::SceneManager* scene_;
  Ogre::Camera* camera_;
  Ogre::Viewport* viewport_;
  
public:
  int counter_;
  float counter_interpolated_;
};

#endif
