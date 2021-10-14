/***************************************************************************
 *   Free Heroes of Might and Magic II: https://github.com/ihhub/fheroes2  *
 *   Copyright (C) 2020                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "ai_denis.h"
#include "artifact.h"
#include "battle_arena.h"
#include "battle_army.h"
#include "battle_cell.h"
#include "battle_command.h"
#include "battle_tower.h"
#include "battle_troop.h"
#include "castle.h"
#include "difficulty.h"
#include "game.h"
#include "heroes.h"
#include "logging.h"
#include "settings.h"
#include "speed.h"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <set>

using namespace Battle;

namespace AI
{
    void Denis::HeroesPreBattle( HeroBase & hero, bool isAttacking )
    {
        if ( isAttacking ) {
            OptimizeTroopsOrder( hero.GetArmy() );
        }
    }

    bool CanUnitAttack(Board* board, const Unit& attacker, s32 index) {
        auto surroundingCells = board->GetAroundIndexes(index);
        for (auto it = surroundingCells.begin(), end = surroundingCells.end(); it != end; ++it) {
            s32 surroundingIndex = *it;
            uint32_t distance = board->GetDistance(surroundingIndex, attacker.GetHeadIndex());
            if (distance <= attacker.GetSpeed()) {
                // if (board->CanAttackUnitFromCell(attacker, surroundingIndex)) {
                //     return true;
                // }
                return true;
            }
        }

        return false;
    }

    s32 GetAttackIndex(Board* board, const Unit& attacker, const Unit& defender) {
        auto surroundingCells = board->GetAroundIndexes(defender.GetHeadIndex());
        for (auto it = surroundingCells.begin(), end = surroundingCells.end(); it != end; ++it) {
            s32 surroundingIndex = *it;
            Position pos = Position::GetReachable(attacker, surroundingIndex);
            const Cell* head = pos.GetHead();
            if (head != nullptr) {
                if (board->CanAttackUnitFromCell(attacker, surroundingIndex)) {
                    return surroundingIndex;
                }
            }
        }
        return -1;
    }

    void MoveToWithoutBeingAttacked(Board* board, const Unit& currentUnit, const Unit& moveTowards, const Unit* enemyPeasants, bool shouldAttackIfPossible, Actions & actions) {
        if (shouldAttackIfPossible) {
            s32 index = GetAttackIndex(board, currentUnit, moveTowards);
            if (index >= 0) {
                actions.emplace_back(CommandType::MSG_BATTLE_MOVE, currentUnit.GetUID(), index);
                actions.emplace_back(CommandType::MSG_BATTLE_ATTACK, currentUnit.GetUID(), moveTowards.GetUID(), index, 0 );
                actions.emplace_back(CommandType::MSG_BATTLE_END_TURN, currentUnit.GetUID());
                return;
            }
        }

        s32 shortestDistanceCell = -1;
        uint32_t shortestDistance = 10000;
        std::vector<u32> passable;

        for (int32_t dst = 0; dst < ARENASIZE; ++dst) {
            Position pos = Position::GetReachable(currentUnit, dst);
            const Cell* head = pos.GetHead();
            if (head != nullptr) {
                s32 index = head->GetIndex();

                // Can I get attacked by their peasants? If yes, don't make this move.
                if (enemyPeasants != nullptr && CanUnitAttack(board, *enemyPeasants, index)) {
                    // Don't move here - we will get attacked.
                    continue;
                }

                passable.push_back(index);
                uint32_t distance = board->GetDistance(index, moveTowards.GetHeadIndex());
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    shortestDistanceCell = index;
                }
            }
        }

        if (shortestDistanceCell == -1) {
            // No move that will not get us attacked. In that case, attack.
            s32 index = GetAttackIndex(board, currentUnit, moveTowards);
            if (index >= 0) {
                actions.emplace_back(CommandType::MSG_BATTLE_MOVE, currentUnit.GetUID(), index);
                actions.emplace_back(CommandType::MSG_BATTLE_ATTACK, currentUnit.GetUID(), moveTowards.GetUID(), index, 0 );
                actions.emplace_back(CommandType::MSG_BATTLE_END_TURN, currentUnit.GetUID());
                return;
            }

            actions.emplace_back(CommandType::MSG_BATTLE_END_TURN, currentUnit.GetUID());
            return;
        }
        
        actions.emplace_back(CommandType::MSG_BATTLE_MOVE, currentUnit.GetUID(), shortestDistanceCell);
        actions.emplace_back(CommandType::MSG_BATTLE_END_TURN, currentUnit.GetUID());
    }

    void Denis::BattleTurn( Arena & arena, const Unit & currentUnit, Actions & actions )
    {
        const Units enemies( arena.getEnemyForce(currentUnit.GetCurrentColor()), true );

        Board * board = Arena::GetBoard();
        board->Reset();
        board->SetScanPassability( currentUnit );

        Unit* bestTarget = nullptr;
        if (currentUnit.GetShots() > 0) {
            // Shoot their archer, if there is one.
            for (auto it = enemies.begin(), end = enemies.end(); it != end; ++it) {
                Unit* target = *it;
                if (target->GetShots() > 0) {
                    // Found archer.
                    auto dmg = currentUnit.CalculateMaxDamage(*target);
                    auto howManyWillKill = target->HowManyWillKilled(dmg);
                    if (howManyWillKill >= target->GetCount()) {
                        continue;
                    }
                    
                    bestTarget = target;
                }
            }

            // Otherwise, shoot whoever is left.
            if (bestTarget == nullptr) {
                bestTarget = enemies[0];
            }

            actions.emplace_back(CommandType::MSG_BATTLE_ATTACK, currentUnit.GetUID(), bestTarget->GetUID(), bestTarget->GetHeadIndex(), 0 );
            actions.emplace_back(CommandType::MSG_BATTLE_END_TURN, currentUnit.GetUID());
            return;
        }

        Unit* enemyPeasants = nullptr;
        Unit* enemyArchers = nullptr;

        for (auto it = enemies.begin(), end = enemies.end(); it != end; ++it) {
            Unit* enemy = *it;
            if (enemy->GetID() == Monster::PEASANT) {
                enemyPeasants = enemy;
            } else if (enemy->GetID() == Monster::ARCHER) {
                enemyArchers = enemy;
            }
        }

        // See if enemy peasants can attack my archers.
        bool shouldAttack = false;
        Unit* enemyToMoveTowardsTo = enemyArchers == nullptr ? enemyPeasants : enemyArchers;

        if (enemyPeasants != nullptr) {
            const Units myArmy( arena.getForce(currentUnit.GetCurrentColor()), true );
            for (auto it = myArmy.begin(), end = myArmy.end(); it != end; ++it) {
                Unit* myUnit = *it;
                if (myUnit->GetShots() > 0) {
                    // Found my archers. Are they in close proximity to enemy peasants?
                    if (CanUnitAttack(board, *enemyPeasants, myUnit->GetHeadIndex())) {
                        // Our archer can be attacked. Must defend them by counter-attacking.
                        shouldAttack = true;
                        enemyToMoveTowardsTo = enemyPeasants;
                        break;
                    }
                }
            }
        }

        MoveToWithoutBeingAttacked(board, currentUnit, *enemyToMoveTowardsTo, enemyPeasants, shouldAttack, actions);
    }
}
