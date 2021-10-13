#pragma once

#include <pthread.h>

class Thread {
 public:
  typedef void* ResultType;

  Thread();
  ~Thread();

  template <typename T>
  void start(T* ptr, ResultType (*entryPoint)(T*));

  ResultType join();
  bool isStarted() const;

  static ResultType successCode();
  static ResultType failureCode();

 private:
  pthread_t _thread;
};
