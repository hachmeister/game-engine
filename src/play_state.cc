#include "play_state.h"

#include "gameengine.h"

PlayState::PlayState()
  : counter_(0),
    counter_interpolated_(0.0f)
{
  cdata.x = 0;
  cdata.y = 0;
  
  pdata = cdata;
}

PlayState::~PlayState()
{
}

void PlayState::init()
{
  root_ = Ogre::Root::getSingletonPtr();
  scene_ = root_->createSceneManager(Ogre::ST_GENERIC);
  camera_ = scene_->createCamera("IntroCamera");
  viewport_ = root_->getAutoCreatedWindow()->addViewport(camera_);
  
  viewport_->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 1.0));
}

void PlayState::cleanup()
{
  scene_->clearScene();
  scene_->destroyAllCameras();
  root_->getAutoCreatedWindow()->removeAllViewports();
  root_->destroySceneManager(scene_);
}

void PlayState::update(float delta)
{
  pdata = cdata;
  
  cdata.x++;
  cdata.y++;
  
  if (counter_ >= 50) {
    GameEngine::instance()->exit();
  }
  
  counter_ = cdata.x;
}

void PlayState::draw(float alpha)
{
  float pfac = 1.0f - alpha;
  float cfac = alpha;
  
  counter_interpolated_ = (float)pdata.x * pfac + (float)cdata.x * cfac;
}
