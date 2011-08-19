#ifndef OGRE_RENDERER_H
#define OGRE_RENDERER_H

#include <OGRE/Ogre.h>

#include "renderengine.h"

class OgreRenderEngine : public RenderEngine
{
public:
  OgreRenderEngine();
  ~OgreRenderEngine();
  void draw();
  Ogre::RenderWindow* window();
  
private:
  Ogre::Root* root_;
  Ogre::RenderWindow* window_;
};

#endif
