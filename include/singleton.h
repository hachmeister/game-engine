#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton
{
public:
  static T* instance()
  {
    if (!instance_) {
      instance_ = new T;
    }
    
    return instance_;
  }
  
protected:
  Singleton() {};
  ~Singleton() {};
  
  static T* instance_;
  
private:
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
};

template<typename T> T* Singleton<T>::instance_ = 0;

#endif
