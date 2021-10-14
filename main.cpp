#include "common/Thread.hpp"
#include "common/ErrnoCheck.h"

#include "fheroes2/battle/battle_arena.h"
#include "fheroes2/army/army.h"
#include "fheroes2/world/world.h"
#include "fheroes2/system/settings.h"
#include "engine/rand.h"

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

  World::Get().GetKingdom(Color::BLUE).SetAiType(AI::AI_TYPE::AI_DENIS);
  World::Get().GetKingdom(Color::GREEN).SetAiType(AI::AI_TYPE::NORMAL);

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
