#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>
#include <cmath>

#include "CCamera.h"
#include "CFPS.h"
#include "CAnimation.h"
#include "CSurface.h"
#include "vector2d.h"
#include "CContact.h"

enum {
    ENTITY_TYPE_GENERIC = 0,
    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE = 0,

    ENTITY_FLAG_GRAVITY = 0x00000001,
    ENTITY_FLAG_GHOST = 0x00000002,
    ENTITY_FLAG_MAPONLY = 0x00000004
};

class CEntity;
class CContact;
class CBall;
class CPlane;

class CEntity {
public:
    static std::vector<CEntity*> EntityList;

protected:
    CAnimation Anim_Control;
    SDL_Surface* Surf_Entity;

public:
    Vector2D Pos;
    Vector2D Center;
    Vector2D Vel;
    Vector2D Accel;
    float InvMass;
    int Width;
    int Height;

    bool MoveLeft;
    bool MoveRight;

public:
    int Type;
    int Flags;



public:
   // float MaxSpeedX;
   // float MaxSpeedY;

protected:
    int CurrentFrameCol;
    int CurrentFrameRow;

protected:
    // bool CanJump;

public:
    CEntity();
    ~CEntity();

public:
    bool OnLoad(char* File, int Width, int Height, int MaxFrames);
    void OnLoop();
    void OnRender(SDL_Surface* Surf_Display);
    void OnCleanup();
    void OnAnimate();


public:
   // void OnMove(Vector2D Move);
    void SetCenter();
    // void StopMove();

public:
    virtual CContact GenerateContact(CBall* Ball)=0;
    virtual CContact GenerateContact(CPlane* Plane)=0;
    virtual CContact GenerateContact(CEntity* Entity)=0;

public:
    int Col_X;
    int Col_Y;
    int Col_Width;
    int Col_Height;

 /* private:
    bool PosValid(int NewX, int NewY);
    bool PosValidTile(CTile* Tile);
    bool PosValidEntity(CEntity* Entity, int NewX, int NewY); */
};



class CBall : public CEntity
{
public:
    CBall();
    CBall(float R) : Radius(R) { }
    ;

    CContact GenerateContact(CBall* Ball);
    CContact GenerateContact(CPlane* Plane);
    CContact GenerateContact(CEntity* Entity);

    float Radius;
};

class CPlane : public CEntity
{
public:
    CPlane(float nX = 0, float nY = 0, float D = 0);

    CContact GenerateContact(CBall* Ball);
    CContact GenerateContact(CPlane* Plane);
    CContact GenerateContact(CEntity* Entity);

    Vector2D Normal;
    float Distance;
};

#endif // _CENTITY_H_
