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

// -----------------------------------------------------------------------------
//  
//   file   : decrndCDT.cpp
//   author : Alessio Calcagno
//
//   Implementation of class TDecRndCDT, sub-class of TDecCDT, for 
//   decimation of constrained Delaunay triangulation with a random choice
//   of the vertex to be removed.
//   This class re-implements method InitialTriangulation in this way:
//   before inserting the removable vertices
//   in ElimVtxTree, it sets a random key in their Error field
//   (function compare for PTVertex used in TBTree uses this field).
//

#ifdef CC_SILICON /* PAOLA */
#include <rand48.h>
#else
#include <stdlib.h>
#endif /* CC_SILICON */
#include <time.h>

#include "defs.h"
#include "error.h"

#include "ttriang.h"

#include "decCDT.h"
#include "decrndCDT.h"


#ifdef CC_VISUAL5
#define srand48 srand
#define drand48() ((double) rand() / RAND_MAX)
#endif


// -----------------------------------------------------------------------------
//  
//  void TDecRndCDT::InitialTriangulation()
//
//  Similar to TDecimDelaunay::InitialTriangulation. The difference is
//  that, before inserting the removable vertices
//  in ElimVtxTree, it sets a random key in their Error field
//  (function compare for PTVertex used in TBTree uses this field).
//  Equal to the implementation given in TDecRndDelaunay.
//
//  IDEA: give a large key to vertices with constraints incident in them.
//


void TDecRndCDT::InitialTriangulation()
{
   #ifdef DEBUG
      DEBUG << "\nTDecRndCDT::InitialTriangulation()" << endl;
   #endif
       
   srand48( (int) time(NULL) );

   for( int v=0; v<nPts; v++ )
   {

      if( ((PTVertex) Points[v])->VE[0] != NULL ) 
      // in order to read also files which contain points not present
      // in the triangulation (e.g., output of a decimation): for such
      // points,  only coordinates are initialized (e.g.,  0.0  0.0  0.0 ).
      { 
         PTVertex V = (PTVertex)(Points[v]);
       
         Points[v]->Error = drand48();
         
         if ( IsVtxElim( V ) && OkDegree( CalcDegree(V) ) && OkConstrDegree( V ) )
            ElimVtxTree.Insert( V );
       
      } // end ...if(  Points[v]->VE[0] != NULL
   } // end ...for(v)

   // Since TDecCDT inherits from both TDecimDelaunay and TRefCDTDelaunay
   // it is necessary to specify the base class

   TDecimDelaunay::MT_Initial();         
                                         
   TDecimDelaunay::InitialPhase = FALSE; 

}
