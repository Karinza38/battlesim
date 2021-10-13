#pragma once

void exitWithMessage(const char* format, ...) __attribute__((format(printf, 1, 2))) __attribute__((noreturn));
