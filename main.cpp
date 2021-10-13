#include "common/Thread.hpp"
#include "common/ErrnoCheck.h"

#include "fheroes2/battle/battle_arena.h"
#include "fheroes2/army/army.h"
#include "fheroes2/world/world.h"
#include "fheroes2/system/settings.h"
#include "engine/rand.h"

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// #include <iostream>
#include <dlfcn.h>
#include <typeinfo>
// #include <string>
// #include <memory>
#include <cxxabi.h>
// #include <cstdlib>

void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

namespace {
  void * last_frames[20];
  size_t last_size;
  std::string exception_name;

  std::string demangle(const char *name) {
    int status;
    std::unique_ptr<char,void(*)(void*)> realname(abi::__cxa_demangle(name, 0, 0, &status), &std::free);
    return status ? "failed" : &*realname;
  }
}

extern "C" {
  void __cxa_throw(void *thrown_exception, std::type_info* tinfo, void (*dest)(void *)) {
    exception_name = demangle(tinfo->name());
    last_size = backtrace(last_frames, sizeof last_frames/sizeof(void*));

    static void (*const rethrow)(void*,void*,void(*)(void*)) = (void (*)(void*,void*,void(*)(void*)))dlsym(RTLD_NEXT, "__cxa_throw");
    rethrow(thrown_exception, tinfo, dest);
    exit(0);
  }
}


int timesArmy1WonTotal = 0;
int timesArmy2WonTotal = 0;

Thread::ResultType simulateBattles(Thread* unused) {
	int timesArmy1Won = 0;
    int timesArmy2Won = 0;

	World::Get().NewMaps( 10, 10 );

	Settings & conf = Settings::Get();
    conf.GetPlayers().Init( Color::ALL );

    conf.GetPlayers().Get(Color::BLUE)->SetControl(CONTROL_AI);
    conf.GetPlayers().Get(Color::GREEN)->SetControl(CONTROL_AI);

	for (int i = 0; i < 100 * 1000; ++i) {
    	// Army1 is weaker but makes the first move.
    	Army army1;
	    army1.GetTroop(0)->Set(Monster::PEASANT, 821);
	    army1.GetTroop(1)->Set(Monster::ARCHER, 50);
	    army1.SetColor(Color::BLUE);

	    Army army2;
	    army2.GetTroop(0)->Set(Monster::PEASANT, 1001);
	    army2.GetTroop(1)->Set(Monster::ARCHER, 50);
	    army2.SetColor(Color::GREEN);

	    Battle::Result result = Battle::Loader(army1, army2, /* mapsindex= */ 0);

	    if (result.AttackerWins()) {
	    	++timesArmy1Won;
	    } else {
	    	++timesArmy2Won;
	    }
    }

    __atomic_add_fetch(&timesArmy1WonTotal, timesArmy1Won, __ATOMIC_RELAXED);
    __atomic_add_fetch(&timesArmy2WonTotal, timesArmy2Won, __ATOMIC_RELAXED);

    return Thread::successCode();
}

int main() {
	clearErrno();

	// populates monster data to avoid race condition doing so later.
	fheroes2::getMonsterData(0);

	verifyErrnoIsntSet("+signal#0");
	signal(SIGSEGV, handler);
	verifyErrnoIsntSet("-signal#0");

	verifyErrnoIsntSet("+signal#1");
	signal(SIGFPE, handler);
	verifyErrnoIsntSet("-signal#1");

    Thread threads[16];
    for (int i = 0; i < 16; ++i) {
    	threads[i].start(&threads[i], &simulateBattles);
    }

    for (int i = 0; i < 16; ++i) {
    	threads[i].join();
    }

	printf("timesArmy1Won: %d, timesArmy2Won: %d\n", timesArmy1WonTotal, timesArmy2WonTotal);

	return 0;
}
