#ifndef OGRE_RENDERER_H
#define OGRE_RENDERER_H

#include <OGRE/Ogre.h>

#include "renderengine.h"
#include "singleton.h"

class OgreRenderEngine : public RenderEngine, public Singleton<OgreRenderEngine>
{
  friend class Singleton<OgreRenderEngine>;
  
public:
  void draw();

private:
  OgreRenderEngine();
  ~OgreRenderEngine();
  
private:
  Ogre::Root* root_;
  Ogre::RenderWindow* window_;
};

#endif
