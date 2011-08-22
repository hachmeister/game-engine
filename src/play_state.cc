#include "play_state.h"

#include "gameengine.h"
#include "intro_state.h"

PlayState::PlayState()
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
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->addKeyboardListener(this);
}

void PlayState::cleanup()
{
  scene_->clearScene();
  scene_->destroyAllCameras();
  root_->getAutoCreatedWindow()->removeAllViewports();
  root_->destroySceneManager(scene_);
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->removeKeyboardListener(this);
}

void PlayState::update(float delta)
{
  pdata = cdata;
  
  cdata.x++;
  cdata.y++;
}

void PlayState::draw(float alpha)
{
  float pfac = 1.0f - alpha;
  float cfac = alpha;
}

void PlayState::keyDown(KeyboardEvent& event)
{
  std::cout << "key down: " << event.key << std::endl;
  
  switch (event.key) {
    case ESC:
      GameEngine::instance().state(new IntroState());
      break;
    default:
      break;
  }
}

void PlayState::keyUp(KeyboardEvent& event)
{
  std::cout << "key up: " << event.key << std::endl;
}
