#include "ErrnoCheck.h"
#include "Log.h"

#include <errno.h>  // errno
#include <string.h> // strerror

void clearErrno() {
  errno = 0;
}

void verifyErrnoIsntSet(const char* marker) {
  int e = errno;
  if (e != 0) {
    errno = 0;
    exitWithMessage("%s unexpectedly set errno %d (%s)", marker, e, strerror(e));
  }
}
