#include "CEntity.h"
#include "CContact.h"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    Surf_Entity = NULL;

    Width = Height = 0;

    InvMass = 1;

    MoveLeft = false;
    MoveRight = false;

    Type = ENTITY_TYPE_GENERIC;
    Flags = ENTITY_FLAG_GRAVITY;

    CurrentFrameCol = 0;
    CurrentFrameRow = 0;

    Col_X = 0;
    Col_Y = 0;
    Col_Height = 0;
    Col_Width = 0;
}

CEntity::~CEntity() {
    Surf_Entity = NULL;
}

bool CEntity::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
        return false;
    }

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

/* void CEntity::OnLoop() {
    if(MoveLeft == false && MoveRight == false) {
        StopMove();
    }

    if(MoveLeft) {
        Accel.SetX(-0.5);
    }else

    if(MoveRight) {
        Accel.SetX(0.5);
    }

    if(Flags & ENTITY_FLAG_GRAVITY) {
        Accel.SetY(0.75f);
    }

    Vel += Accel * CFPS::FPSControl.GetSpeedFactor();

    if(SpeedX > MaxSpeedX) SpeedX = MaxSpeedX;
    if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
    if(SpeedY > MaxSpeedY) SpeedY = MaxSpeedY;
    if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

    OnAnimate();
    OnMove(Vel);
} */

void CEntity::SetCenter()
{
    Center.SetX(Pos.GetX() + Width / 2);
    Center.SetY(Pos.GetY() + Height / 2);
}

void CEntity::OnLoop()
{

    Pos += Vel * CFPS::FPSControl.GetSpeedFactor() + ( Accel * CFPS::FPSControl.GetSpeedFactor() * CFPS::FPSControl.GetSpeedFactor() * 0.5);
    Vel += Accel * CFPS::FPSControl.GetSpeedFactor();

    SetCenter();
}


void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, Pos.GetX() - CCamera::CameraControl.GetX(), Pos.GetY() - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()), Width, Height);
}

void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

/* void CEntity::OnAnimate() {
    if(MoveLeft) {
        CurrentFrameCol = 0;
    }else

    if(MoveRight) {
        CurrentFrameCol = 1;
    }

    Anim_Control.OnAnimate();
}
*/

/* void CEntity::OnMove(Vector2D Move) {
    CanJump = false;

    if(MoveX == 0 && MoveY == 0) return;

    double NewX = 0;
    double NewY = 0;

    MoveX *= CFPS::FPSControl.GetSpeedFactor();
    MoveY *= CFPS::FPSControl.GetSpeedFactor();

    if(MoveX != 0) {
        if(MoveX >= 0) NewX = CFPS::FPSControl.GetSpeedFactor();
        else NewX = -CFPS::FPSControl.GetSpeedFactor();
    }

    if(MoveY != 0) {
        if(MoveY >= 0) NewY = CFPS::FPSControl.GetSpeedFactor();
        else NewY = -CFPS::FPSControl.GetSpeedFactor();
    }

    while(true) {
        if(Flags & ENTITY_FLAG_GHOST) {
            PosValid((int)(X + NewX), (int)(Y + NewY));

            X += NewX;
            Y += NewY;
        }else{
            if(PosValid((int)(X + NewX), (int)(Y))) {
                X += NewX;
            }else{
                SpeedX = 0;
            }

            if(PosValid((int)(X), (int)(Y + NewY))) {
                Y += NewY;
            }else{
                if(MoveY > 0) {
                    CanJump = true;
                }

                SpeedY = 0;
            }
        }

        MoveX += -NewX;
        MoveY += -NewY;

        if(NewX > 0 && MoveX <= 0) NewX = 0;
        if(NewX < 0 && MoveX >= 0) NewX = 0;

        if(NewY > 0 && MoveY <= 0) NewY = 0;
        if(NewY < 0 && MoveY >= 0) NewY = 0;

        if(MoveX == 0) NewX = 0;
        if(MoveY == 0) NewY = 0;

        if(MoveX == 0 && MoveY == 0) break;
        if(NewX == 0 && NewY == 0) break;
    }
}

void CEntity::OnMove(Vector2D Move)
{
    Pos += Move * CFPS::FPSControl.GetSpeedFactor();
}

void CEntity::StopMove(){
    if(Vel.GetX() > 0) {
        Accel.SetX(-1);
    }

    if(Vel.GetX() < 0) {
        Accel.SetX = 1;
    }

    if(Vel.GetX() < 2.0f && Vel.GetX() > -2.0f) {
        Accel.SetX(0);
        Vel.SetX(0);
    }
}

bool CEntity::PosValid(int NewX, int NewY) {
    bool Return = true;

    int StartX = (NewX + Col_X) / TILE_SIZE;
    int StartY = (NewY + Col_Y) / TILE_SIZE;

    int EndX = ((NewX + Col_X) + Width - Col_Width - 1) / TILE_SIZE;
    int EndY = ((NewY + Col_Y) + Height - Col_Height - 1) / TILE_SIZE;

    for(int iY = StartY; iY <= EndY; iY++) {
        for(int iX = StartX; iX <= EndX; iX++) {
            CTile* Tile = CArea::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);

            if(PosValidTile(Tile) == false) { Return = false; }
        }
    }

    if(Flags & ENTITY_FLAG_MAPONLY) {
    }else{
        for(int i = 0; i < EntityList.size(); i++) {
            if(PosValidEntity(EntityList[i], NewX, NewY) == false) { Return = false; }
        }
    }

    return Return;
}

bool CEntity::PosValidTile(CTile* Tile) {
    if(Tile == NULL) return true;

    if(Tile->TypeID == TILE_TYPE_BLOCK) return false;

    return true;
}

bool CEntity::PosValidEntity(CEntity* Entity, int NewX, int NewY) {
    if(this != Entity && Entity != NULL && Entity->Dead == false && Entity->Flags ^ ENTITY_FLAG_MAPONLY &&
       Entity->Collides(NewX + Col_X, NewY + Col_Y, Width - Col_Width - 1, Height - Col_Height - 1) == true) {

            CContact EntityCol;

            EntityCol.EntityA = this;
            EntityCol.EntityB = Entity;

            CContact::ContactList.push_back(EntityCol);

            return false;
    }

    return true;
} */

/*
CContact CEntity::GenerateContact(CBall* Ball)
{
    CContact Contact;
    return Contact;
}

CContact CEntity::GenerateContact(CPlane* Plane)
{
    CContact Contact;
    return Contact;
}

CContact CEntity::GenerateContact(CEntity* Entity)
{
    CContact Contact;
    return Contact;
} */

CBall::CBall()
{
    Radius = 1;
}

CContact CBall::GenerateContact(CBall* Ball)
{
    CContact Contact(this,Ball);

    Contact.Normal = Center - Ball->Center;
    Contact.Distance = Contact.Normal.Mag() - (Radius + Ball->Radius);
    Contact.Normal = Contact.Normal / Contact.Normal.Mag();

    return Contact;
}

CContact CBall::GenerateContact(CPlane* Plane)
{
    CContact Contact(this,Plane);

    Contact.Normal = Plane->Normal;
    Contact.Distance = Center.Dot(Plane->Normal) + Plane->Distance - Radius;

    return Contact;
}

CContact CBall::GenerateContact(CEntity* Entity)
{
    CContact Contact;
    return Contact;
}

CPlane::CPlane(float nX, float nY, float D)
{
    Normal.SetX(nX);
    Normal.SetY(nY);
    Distance = D;
}

CContact CPlane::GenerateContact(CBall* Ball)
{
    CContact Contact;
    return Contact;
}

CContact CPlane::GenerateContact(CPlane* Plane)
{
    CContact Contact;
    return Contact;
}

CContact CPlane::GenerateContact(CEntity* Entity)
{
    CContact Contact;
    return Contact;
}
