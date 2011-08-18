#include "gameengine.h"

#include "intro_state.h"
#include "timer.h"

GameEngine::GameEngine()
  : update_interval_(40),
    render_engine_(0),
    state_(0),
    next_state_(0)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::run()
{
  Timer timer;
  
  unsigned long now = 0;
  unsigned long delta = 0;
  unsigned long accu = 0;
  
  running_ = true;
  
  while (running_) {
    update_state();
    
    unsigned long tmp = timer.millis();
    delta = tmp - now;
    now = tmp;
    
    accu += delta;
    
    while (accu >= update_interval_) {
      update(1000.0f/(float)update_interval_);
      accu -= update_interval_;
    }
    
    draw((float)accu/(float)update_interval_);
  }
}

void GameEngine::exit()
{
  running_ = false;
}

void GameEngine::renderer(RenderEngine* render_engine)
{
  render_engine_ = render_engine;
}

void GameEngine::state(State* state)
{
  next_state_ = state;
}

void GameEngine::update(float delta)
{
  state_->update(delta);
}

void GameEngine::draw(float alpha)
{
  state_->draw(alpha);
  render_engine_->draw();
}

void GameEngine::update_state()
{
  if (next_state_) {
    if (next_state_ != state_) {
      if (state_) {
        state_->cleanup();
        delete state_;
      }
      
      state_ = next_state_;
      state_->init();
    }
    
    next_state_ = 0;
  }
}
