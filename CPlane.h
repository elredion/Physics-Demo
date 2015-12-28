#ifndef _CPLANE_H_
    #define _CPLANE_H_

#include "CEntity.h"

class CPlane : public CEntity
{
public:
    CPlane(int nX=0, int nY=0);

    Vector2D Normal;
    int Distance;
}


#endif // _CPLANE_H_
