#include "CColShape.h"

CColShape::CColShape() : Entity(Attach)
{
}

CColShape::~CColShape()
{
    Entity = nullptr;
}

bool CColShape::Collides(CColCircle Object)
{
    //Pure Virtual
}

bool CColShape::Collides(CColPlane Object)
{
    //Pure Virtual
}

bool CColShape::Collides(CColRectangle Object)
{
    //Pure Virtual
}

bool CColCircle::Collides(CColCircle Object)
{
    const CEntity* EntityA = Entity;
    const CEntity* EntityB = Object.Entity;

    Vector2D CenterA(EntityA->Pos.GetX() + (float) EntityA->Width / 2, EntityA->Pos.GetY() - (float) EntityA->Height / 2);
    Vector2D CenterB(EntityB->Pos.GetX() + (float) EntityB->Width / 2, EntityB->Pos.GetY() - (float) EntityB->Height / 2);

    Vector2D Distance = CenterA - CenterB;

    if(Distance.Mag() <= (EntityA->Width + EntityB->Width)) return true;
    else return false;
}

bool CColCircle::Collides(CColPlane Object)
{
    Vector2D Center(Entity->Pos.GetX() + (float) Entity->Width / 2, Entity->Pos.GetY() - (float) Entity->Height / 2);

    float Distance = Center.Dot(Object.Normal) + Object.Distance;

    if(Distance < 0 && (Entity->Vel.Dot(Object.Normal)) < 0) return true;
    else return false;
}

bool CColCircle::Collides(CColRectangle Object)
{

}

bool CColRectangle::Collides(CColCircle Object)
{
    return Object.Collides(*this);
}

bool CColRectangle::Collides(CColPlane Object)
{

}

bool CColRectangle::Collides(CColRectangle Object)
{

}

CColPlane::CColPlane(CPlane* Attach)
{
    Entity = Attach;
    Distance = Attach->Distance;
    Normal = Attach->Normal;
}

bool CColPlane::Collides(CColCircle Object)
{
    return Object.Collides(*this);
}

bool CColPlane::Collides(CColPlane Object)
{
    return false;
}

bool CColPlane::Collides(CColRectangle Object)
{
    return Object.Collides(*this);
}
