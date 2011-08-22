#include "intro_state.h"

#include <CEGUI/RendererModules/Ogre/CEGUIOgreRenderer.h>

#include "gameengine.h"
#include "play_state.h"

#include <iostream>

CEGUI::MouseButton convertMouseButtonToCegui(int button) {
  switch (button) {
    case 0:
      return CEGUI::LeftButton;
    case 1:
      return CEGUI::RightButton;
    case 2:
      return CEGUI::MiddleButton;
    default:
      return CEGUI::LeftButton;
  }
}

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
  camera_->setPosition(Ogre::Vector3(0.0, 0.0, 500.0));
  camera_->lookAt(Ogre::Vector3(0.0, 0.0, -300.0));
  camera_->setNearClipDistance(5.0);
  viewport_ = root_->getAutoCreatedWindow()->addViewport(camera_);
  viewport_->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
  camera_->setAspectRatio(Ogre::Real(viewport_->getActualWidth()) / Ogre::Real(viewport_->getActualHeight()));
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->addKeyboardListener(this);
  inputmanager->addMouseListener(this);
  
  
  
  CEGUI::SchemeManager::getSingleton().create("TaharezLook.scheme");
  CEGUI::System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
  CEGUI::WindowManager& winMgr = CEGUI::WindowManager::getSingleton();
  CEGUI::DefaultWindow* root = (CEGUI::DefaultWindow*)winMgr.createWindow("DefaultWindow", "Root");
  CEGUI::System::getSingleton().setGUISheet(root);
  CEGUI::FrameWindow* wnd = (CEGUI::FrameWindow*)winMgr.createWindow("TaharezLook/FrameWindow", "Demo Window");
  root->addChildWindow(wnd);
  wnd->setPosition(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim( 0.25f)));
  wnd->setSize(CEGUI::UVector2(cegui_reldim(0.5f), cegui_reldim( 0.5f)));
  wnd->setMaxSize(CEGUI::UVector2(cegui_reldim(1.0f), cegui_reldim( 1.0f)));
  wnd->setMinSize(CEGUI::UVector2(cegui_reldim(0.1f), cegui_reldim( 0.1f)));
  wnd->setText("Hello World!");
}

void IntroState::cleanup()
{
  scene_->clearScene();
  scene_->destroyAllCameras();
  root_->getAutoCreatedWindow()->removeAllViewports();
  root_->destroySceneManager(scene_);
  
  InputManager* inputmanager = GameEngine::instance().inputmanager();
  inputmanager->removeKeyboardListener(this);
  inputmanager->removeMouseListener(this);
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

void IntroState::keyDown(KeyboardEvent& event)
{
  std::cout << "key down: " << event.key << std::endl;
  
  switch (event.key) {
    case SPACE:
      GameEngine::instance().state(new PlayState());
      break;
    case ESC:
      GameEngine::instance().exit();
      break;
    default:
      break;
  }
  
  CEGUI::System& sys = CEGUI::System::getSingleton();
  sys.injectKeyDown(event.key);
  sys.injectChar(event.chr);
}

void IntroState::keyUp(KeyboardEvent& event)
{
  std::cout << "key up: " << event.key << std::endl;
  
  CEGUI::System& sys = CEGUI::System::getSingleton();
  sys.injectKeyUp(event.key);
}

void IntroState::mouseMoved(MousePositionEvent& event)
{
  CEGUI::System& cegui = CEGUI::System::getSingleton();
  cegui.injectMousePosition(event.x, event.y);
}

void IntroState::mouseDown(MouseButtonEvent& event)
{
  CEGUI::System& cegui = CEGUI::System::getSingleton();
  cegui.injectMouseButtonDown(convertMouseButtonToCegui(event.button));
}

void IntroState::mouseUp(MouseButtonEvent& event)
{
  CEGUI::System& cegui = CEGUI::System::getSingleton();
  cegui.injectMouseButtonUp(convertMouseButtonToCegui(event.button));
}

bool IntroState::exit(const CEGUI::EventArgs& args)
{
  GameEngine::instance().exit();
  return true;
}
