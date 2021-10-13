#include "Thread.h"

#include "ErrnoCheck.h"
#include "Log.h"

#include <string.h> // strerror

Thread::Thread() : _thread(0) {
  // do nothing
}

Thread::~Thread() {
  // do nothing
}

Thread::ResultType Thread::join() {
  ResultType result;
  int errorNumber = pthread_join(_thread, &result);
  if (errorNumber < 0) {
    exitWithMessage("pthread_join failed: %d / %s.", errorNumber, strerror(errorNumber));
  }
  verifyErrnoIsntSet("pthread_join");

  _thread = 0;
  return result;
}

bool Thread::isStarted() const { return _thread != 0; }

Thread::ResultType Thread::successCode() { return nullptr; }

Thread::ResultType Thread::failureCode() { return nullptr; }
