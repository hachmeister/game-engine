#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "inputmanager.h"
#include "renderengine.h"
#include "singleton.h"
#include "state.h"

class GameEngine : public Singleton<GameEngine>
{
  friend class Singleton<GameEngine>;
  friend class SingletonDestroyer<GameEngine>;
  
public:
  void run();
  void exit();
  void renderengine(RenderEngine* renderengine);
  RenderEngine* renderengine();
  void inputmanager(InputManager* inputmanager);
  InputManager* inputmanager();
  void state(State* state);
  
private:
  GameEngine();
  ~GameEngine();
  void update(float delta);
  void draw(float alpha);
  void updateState();

private:
  unsigned int updateinterval_;
  bool running_;
  RenderEngine* renderengine_;
  InputManager* inputmanager_;
  State* state_;
  State* nextState_;
};

#endif
