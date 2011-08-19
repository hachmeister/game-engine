#include "gameengine.h"

#include "intro_state.h"
#include "timer.h"

#include <iostream>

GameEngine::GameEngine()
  : updateinterval_(40),
    renderengine_(0),
    inputmanager_(0),
    state_(0),
    nextState_(0)
{
}

GameEngine::~GameEngine()
{
  if (state_) {
    state_->cleanup();
    delete state_;
  }
  
  if (nextState_) {
    delete nextState_;
  }
  
  if (inputmanager_) {
    delete inputmanager_;
  }
  
  if (renderengine_) {
    delete renderengine_;
  }
}

void GameEngine::run()
{
  Timer timer;
  
  unsigned long now = 0;
  unsigned long delta = 0;
  unsigned long accu = 0;
  
  running_ = true;
  
  while (running_) {
    updateState();
    
    unsigned long tmp = timer.millis();
    delta = tmp - now;
    now = tmp;
    
    accu += delta;
    
    inputmanager_->update();
    
    while (accu >= updateinterval_) {
      update(1000.0f/(float)updateinterval_);
      accu -= updateinterval_;
    }
    
    draw((float)accu/(float)updateinterval_);
  }
}

void GameEngine::exit()
{
  running_ = false;
}

void GameEngine::renderengine(RenderEngine* renderengine)
{
  renderengine_ = renderengine;
}

RenderEngine* GameEngine::renderengine()
{
  return renderengine_;
}

void GameEngine::inputmanager(InputManager* inputmanager)
{
  inputmanager_ = inputmanager;
}

InputManager* GameEngine::inputmanager()
{
  return inputmanager_;
}

void GameEngine::state(State* state)
{
  nextState_ = state;
}

void GameEngine::update(float delta)
{
  state_->update(delta);
}

void GameEngine::draw(float alpha)
{
  state_->draw(alpha);
  renderengine_->draw();
}

void GameEngine::updateState()
{
  if (nextState_) {
    if (nextState_ != state_) {
      if (state_) {
        state_->cleanup();
        delete state_;
      }
      
      state_ = nextState_;
      state_->init();
    }
    
    nextState_ = 0;
  }
}
