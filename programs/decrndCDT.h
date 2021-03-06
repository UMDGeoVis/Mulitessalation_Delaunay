/*****************************************************************************
Delaunay Triangulator and MT constructor, version 1.0, 1999.
Copyright (C) 1999 DISI - University of Genova, Italy.
Group of Geometric Modeling and Computer Graphics DISI.
DISI - University of Genova, Via Dodecaneso 35, 16146 Genova - ITALY.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*****************************************************************************/

// -------------------------------------------------------------------------
//
//   file   : decrndCDT.h
//   author : Alessio Calcagno
//
//   Definition of class TDecRndCDT, sub-class of TDecCDT, for
//   decimation of constrained Delaunay triangulation with a random choice
//   of the vertex to be removed.

#ifndef _DECRNDCDT_H
#define _DECRNDCDT_H

#include "decCDT.h"


class TDecRndCDT;

typedef class TDecRndCDT *PTDecRndCDT;
typedef class TDecRndCDT &RTDecRndCDT;

class TDecRndCDT : public TDecCDT
{
   protected:

       virtual void InitialTriangulation();

   public:

       TDecRndCDT( int iK, PMTTracer iMT ): TDecCDT( iK, iMT ), TDecimDelaunay( iK, iMT )
       {
	   // #ifdef DEBUG
		 cout << "TDecRndCDT Constructor" << endl;
 	   // #endif
       };
         
       TDecRndCDT( int iK, PMTTracer iMT, boolean EXTActive, boolean ALLOWFeaturesDel, boolean ALLOWChainBrk  )
          : TDecCDT( iK, iMT, EXTActive, ALLOWFeaturesDel, ALLOWChainBrk ),
            TDecimDelaunay( iK, iMT )
       {
	   // #ifdef DEBUG
		 cout << "TDecRndCDT(Options) Constructor" << endl;
	   // #endif
       };
};

#endif // _DECRNDCDT_H
