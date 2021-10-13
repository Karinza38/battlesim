#pragma once

#include "Thread.h"
#include "ErrnoCheck.h"

template <typename T>
void Thread::start(T* ptr, ResultType (*entryPoint)(T*)) {
  verifyErrnoIsntSet("+start");

  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&_thread, &attr, (void* (*)(void*))entryPoint, ptr);

  verifyErrnoIsntSet("-start");
}
