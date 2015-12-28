#include "CColShape.h"

CColPlane::CColPlane()

CColPlane::CColPlane(CEntity* Entity)
{
    this->Entity = Entity;
}

CColPlane::~CColPlane()
{
    Entity = nullptr;
}


float CColPlane::getNormalX()
{
    return NormalX;
}

float CColPlane::getNormalY() {
    return NormalY;
}
