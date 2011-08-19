#include "ogrerenderengine.h"

OgreRenderEngine::OgreRenderEngine()
{
  root_ = new Ogre::Root();
  
  if (!root_->restoreConfig()) {
    root_->showConfigDialog();
  }
  
  window_ = root_->initialise(true);
}

OgreRenderEngine::~OgreRenderEngine()
{
  if (root_) {
    delete root_;
  }
}

void OgreRenderEngine::draw()
{
  Ogre::WindowEventUtilities::messagePump();
  root_->renderOneFrame();
}

Ogre::RenderWindow* OgreRenderEngine::window()
{
  return window_;
}
