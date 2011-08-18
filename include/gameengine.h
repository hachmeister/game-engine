#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "renderengine.h"
#include "singleton.h"
#include "state.h"

class GameEngine : public Singleton<GameEngine>
{
  friend class Singleton<GameEngine>;
  
public:
  void run();
  void exit();
  void renderer(RenderEngine* render_engine);
  void state(State* state);
  
private:
  GameEngine();
  ~GameEngine();
  
  void update(float delta);
  void draw(float alpha);
  
  void update_state();

private:
  unsigned int update_interval_;
  bool running_;
  RenderEngine* render_engine_;
  State* state_;
  State* next_state_;
};

#endif
