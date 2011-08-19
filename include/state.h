#ifndef STATE_H
#define STATE_H

class State
{
public:
  virtual void init() {};
  virtual void cleanup() {};
  virtual void update(float delta) = 0;
  virtual void draw(float alpha) = 0;
};

#endif
