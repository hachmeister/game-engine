#include "ogrerenderengine.h"

OgreRenderEngine::OgreRenderEngine()
{
  root_ = new Ogre::Root();
  
  if (!root_->restoreConfig()) {
    root_->showConfigDialog();
  }
  
  window_ = root_->initialise(true);
  
  Ogre::ConfigFile cf;
  cf.load("resources.cfg");
  Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

  Ogre::String secName, typeName, archName;
  while (seci.hasMoreElements())
  {
    secName = seci.peekNextKey();
    Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
    Ogre::ConfigFile::SettingsMultiMap::iterator i;
    for (i = settings->begin(); i != settings->end(); ++i)
    {
      typeName = i->first;
      archName = i->second;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
    }
  }
  
  renderer_ = &CEGUI::OgreRenderer::bootstrapSystem();
  /*renderer_ = &CEGUI::OgreRenderer::create();
  CEGUI::System::create(*renderer_);*/
  
  CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
  CEGUI::Font::setDefaultResourceGroup("Fonts");
  CEGUI::Scheme::setDefaultResourceGroup("Schemes");
  CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
  CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
  //CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
  //CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");

}

OgreRenderEngine::~OgreRenderEngine()
{
  CEGUI::OgreRenderer::destroySystem();
  
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
