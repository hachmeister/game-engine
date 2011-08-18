#include "timer.h"

Timer::Timer()
{
  gettimeofday(&start_, 0);
}

Timer::~Timer()
{
}

unsigned long Timer::millis() const
{
  struct timeval now;
  gettimeofday(&now, 0);
  return (now.tv_sec - start_.tv_sec)*1000 + (now.tv_usec - start_.tv_usec)/1000;
}
