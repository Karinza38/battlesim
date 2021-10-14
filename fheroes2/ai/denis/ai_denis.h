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

#ifndef H2AI_DENIS_H
#define H2AI_DENIS_H

#include "ai.h"
#include "normal/ai_normal.h"
#include "world_pathfinding.h"

namespace Battle
{
    class Units;
}

namespace AI
{
    class Denis : public Base
    {
    public:
        Denis();
        void KingdomTurn( Kingdom & kingdom ) override;
        void CastleTurn( Castle & castle, bool defensive ) override;
        void BattleTurn( Battle::Arena & arena, const Battle::Unit & currentUnit, Battle::Actions & actions ) override;
        bool HeroesTurn( VecHeroes & heroes ) override;

        void revealFog( const Maps::Tiles & tile ) override;

        void HeroesPreBattle( HeroBase & hero, bool isAttacking ) override;
        void HeroesActionComplete( Heroes & hero ) override;

        double getObjectValue( const Heroes & hero, const int index, const double valueToIgnore, const uint32_t distanceToObject ) const;
        int getPriorityTarget( const Heroes & hero, double & maxPriority, int patrolIndex = -1, uint32_t distanceLimit = 0 );
        void resetPathfinder() override;

    private:
        // following data won't be saved/serialized
        double _combinedHeroStrength = 0;
        std::vector<IndexObject> _mapObjects;
        std::vector<RegionStats> _regions;
        AIWorldPathfinder _pathfinder;
        BattlePlanner _battlePlanner;

        double getHunterObjectValue( const Heroes & hero, const int index, const double valueToIgnore, const uint32_t distanceToObject ) const;

        double getFighterObjectValue( const Heroes & hero, const int index, const double valueToIgnore, const uint32_t distanceToObject ) const;
    };
}

#endif
