#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class SingletonDestroyer
{
public:
  SingletonDestroyer() : obj_(0)
  {
  }
  
  ~SingletonDestroyer()
  {
    if (obj_) {
      delete obj_;
    }
  }
  
  void instance(T* obj)
  {
    obj_ = obj;
  }
  
private:
  T* obj_;
};

template<typename T>
class Singleton
{
public:
  static T& instance()
  {
    if (!instance_) {
      instance_ = new T;
      destroyer_.instance(instance_);
    }
    
    return *instance_;
  }
  
protected:
  Singleton() {};
  
  static T* instance_;
  static SingletonDestroyer<T> destroyer_;
  
private:
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
};

template<typename T> T* Singleton<T>::instance_ = 0;
template<typename T> SingletonDestroyer<T> Singleton<T>::destroyer_;

#endif
