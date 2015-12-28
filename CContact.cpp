#include "CEntity.h"
#include "CContact.h"
#include <cmath>

std::vector<CContact> CContact::ContactList;

CContact::CContact()
{
    EntityA = NULL;
    EntityB = NULL;
    Distance = 0;
}

CContact::CContact(CEntity* A, CEntity* B)
{
    EntityA = A;
    EntityB = B;

    RelV = EntityA->Vel - EntityB->Vel;
    Distance = 0;
}

CContact::~CContact()
{
    EntityA = NULL;
    EntityB = NULL;
}
