#ifndef _CCONTACT_H_
    #define _CCONTACT_H_

#include "CEntity.h"

class CEntity;

class CContact {
public:
    static std::vector<CContact> ContactList;

public:
    CEntity* EntityA;
    CEntity* EntityB;

    Vector2D Normal;
    Vector2D RelV;
    float Distance;

public:
    CContact();
    CContact(CEntity* A, CEntity* B);
    ~CContact();
};

#endif // _CCONTACT_H_
