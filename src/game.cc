#include "gameengine.h"
#include "intro_state.h"
#include "ogrerenderengine.h"

int main()
{
  GameEngine* engine = GameEngine::instance();
  engine->renderer(OgreRenderEngine::instance());
  engine->state(new IntroState());
  engine->run();
  
  return 0;
}
