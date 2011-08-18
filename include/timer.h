#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>

class Timer
{
public:
  Timer();
  ~Timer();
  unsigned long millis() const;

private:
  struct timeval start_;
};

#endif
