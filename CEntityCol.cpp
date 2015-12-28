#include "CEntity.h"
#include "CContact.h"
#include <cmath>

std::vector<CContact> CContact::ContactList;

CContact::CContact() {
    EntityA = NULL;
    EntityB = NULL;
}

CContact::~CContact() {
    EntityA = NULL;
    EntityB = NULL;
}

void CContact::CalcImpulse() {
    RelativeVel = EntityA->Vel - EntityB->Vel;

    Vector2D CenterA(EntityA->Pos.GetX() + (float) EntityA->Width / 2, EntityA->Pos.GetY() - (float) EntityA->Height / 2);
    Vector2D CenterB(EntityB->Pos.GetX() + (float) EntityB->Width / 2, EntityB->Pos.GetY() - (float) EntityB->Height / 2);

    Distance = CenterA - CenterB;

    ContactNormal = Distance / Distance.Mag();

    Impulse = 1.5f * ContactNormal * (RelativeVel * ContactNormal) / (EntityA->GetInvMass() + EntityB->GetInvMass());

}
