#include "Log.h"

#include <stdio.h>  // vprintf
#include <stdarg.h> // va_list, va_start, va_end
#include <stdlib.h> // exit

void exitWithMessage(const char* format, ...) {
  va_list arglist;
  va_start(arglist, format);
  vprintf(format, arglist);
  va_end(arglist);

  exit(0);
}
