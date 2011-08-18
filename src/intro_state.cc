#include "intro_state.h"

#include "gameengine.h"
#include "play_state.h"

IntroState::IntroState()
  : counter_(0),
    counter_interpolated_(0.0f)
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
}

void IntroState::cleanup()
{
  scene_->clearScene();
  scene_->destroyAllCameras();
  root_->getAutoCreatedWindow()->removeAllViewports();
  root_->destroySceneManager(scene_);
}

void IntroState::update(float delta)
{
  pdata = cdata;
  
  cdata.x++;
  cdata.y++;
  
  if (counter_ >= 50) {
    GameEngine::instance()->state(new PlayState());
  }
  
  counter_ = cdata.x;
}

void IntroState::draw(float alpha)
{
  float pfac = 1.0f - alpha;
  float cfac = alpha;
  
  counter_interpolated_ = (float)pdata.x * pfac + (float)cdata.x * cfac;
}
