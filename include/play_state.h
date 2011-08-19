#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include <OGRE/Ogre.h>

#include "inputmanager.h"
#include "state.h"

class PlayData
{
public:
  int x;
  int y;
};

class PlayState : public State, public KeyboardListener
{
public:
  PlayState();
  ~PlayState();
  void init();
  void cleanup();
  void update(float delta);
  void draw(float alpha);
  void keyDown(Key key);
  void keyUp(Key key);
  
private:
  PlayData pdata;
  PlayData cdata;
  Ogre::Root* root_;
  Ogre::SceneManager* scene_;
  Ogre::Camera* camera_;
  Ogre::Viewport* viewport_;
};

#endif
