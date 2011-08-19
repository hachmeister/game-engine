#include "gameengine.h"
#include "intro_state.h"
#include "ogrerenderengine.h"
#include "oisinputmanager.h"

int main()
{
  size_t windowHnd;
  
  OgreRenderEngine* renderengine = new OgreRenderEngine();
  OISInputManager* inputmanager = new OISInputManager();
  renderengine->window()->getCustomAttribute("WINDOW", &windowHnd);
  inputmanager->init(windowHnd);
  
  GameEngine& game = GameEngine::instance();
  game.renderengine(renderengine);
  game.inputmanager(inputmanager);
  game.state(new IntroState());
  game.run();
  
  return 0;
}
