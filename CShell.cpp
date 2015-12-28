#include "CEntity.h"

CShell::CShell()
{
}

bool CShell::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) return false;

    return true;
}

void CShell::OnLoop() {
    CEntity::OnLoop();
}

void CShell::OnRender(SDL_Surface* Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CShell::OnCleanup() {
    CEntity::OnCleanup();
}

void CShell::OnAnimate() {
    if(SpeedX != 0) {
        Anim_Control.MaxFrames = 4;
    }else{
        Anim_Control.MaxFrames = 0;
    }

    CEntity::OnAnimate();
}

bool CShell::OnCollision(CEntity* Entity, float ImpulseX, float ImpulseY) {
    if(Entity == NULL) return false;

    if(ImpulseX == 0 && ImpulseY == 0) {
        StopMove();
        return true;
    }

    OnMove(ImpulseX * InvMass, ImpulseY * InvMass);

    return true;
}

bool CShell::Collides(CColCircle Circle) {
}
