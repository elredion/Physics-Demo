#ifndef _CCONTACT_H_
    #define _CCONTACT_H_

#include "CEntity.h"

class CContact {
public:
    static std::vector<CContact> ContactList;

public:
    CEntity* EntityA;
    CEntity* EntityB;

    Vector2D ContactNormal;

    Vector2D RelativeVel;

    Vector2D Impulse;

    Vector2D Distance;

public:
    CContact();
    ~CContact();
    void CalcImpulse();
};

#endif // _CCONTACT_H_
