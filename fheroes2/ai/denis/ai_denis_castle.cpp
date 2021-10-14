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
#include "castle.h"
#include "kingdom.h"
#include "race.h"
#include "world.h"

namespace AI
{
    struct BuildOrder;

    extern const std::vector<BuildOrder> & GetDefensiveStructures();

    extern bool Build( Castle & castle, const std::vector<BuildOrder> & buildOrderList, int multiplier = 1 );

    extern bool CastleDevelopment( Castle & castle );

    void Denis::CastleTurn( Castle & castle, bool defensive )
    {
        if ( defensive ) {
            Build( castle, GetDefensiveStructures() );

            castle.recruitBestAvailable( castle.GetKingdom().GetFunds() );
            OptimizeTroopsOrder( castle.GetArmy() );
        }
        else {
            CastleDevelopment( castle );
        }
    }
}
