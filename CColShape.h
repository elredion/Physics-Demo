#ifndef _CCOLSHAPE_H_
    #define _CCOLSHAPE_H_

#include "CEntity.h"
#include "vector2d.h"

class CColShape
{
    class CColCircle : public CColShape
    {

    };

    class CColPlane : public CColShape
    {
    public:
        CColPlane(CPlane* Attach);

        int Distance;
        Vector2D Normal;
    };

    class CColRectangle : public CColShape
    {

    };

public:
    CColShape(CEntity* Attach);
    ~CColShape();

    virtual bool Collides(CColCircle Circle);
    virtual bool Collides(CColPlane Plane);
    virtual bool Collides(CColRectangle Rectangle);

protected:
    CEntity* Entity;







};
#endif
