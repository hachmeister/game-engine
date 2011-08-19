#include "intro_state.h"

#include "gameengine.h"
#include "play_state.h"

#include <iostream>

IntroState::IntroState()
{
  cdata.x = 0;
  cdata.y = 0;
  
  pdata = cdata;
}

IntroState::~IntroState()
{
}

void IntroState::init()
{
  root_ = Ogre::Root::getSingletonPtr();
  scene_ = root_->createSceneManager(Ogre::ST_GENERIC);
  camera_ = scene_->createCamera("IntroCamera");
  viewport_ = root_->getAutoCreatedWindow()->addViewport(camera_);
  viewport_->setBackgroundColour(Ogre::ColourValue(1.0, 0.0, 0.0));
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->addKeyboardListener(this);
}

void IntroState::cleanup()
{
  scene_->clearScene();
  scene_->destroyAllCameras();
  root_->getAutoCreatedWindow()->removeAllViewports();
  root_->destroySceneManager(scene_);
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->removeKeyboardListener(this);
}

void IntroState::update(float delta)
{
  pdata = cdata;
  
  cdata.x++;
  cdata.y++;
}

void IntroState::draw(float alpha)
{
  float pfac = 1.0f - alpha;
  float cfac = alpha;
}

void IntroState::keyDown(Key key)
{
  std::cout << "key down: " << key << std::endl;
  
  switch (key) {
    case SPACE:
      GameEngine::instance().state(new PlayState());
      break;
    case ESC:
      GameEngine::instance().exit();
      break;
    default:
      break;
  }
}

void IntroState::keyUp(Key key)
{
  std::cout << "key up: " << key << std::endl;
}
