#include "CApp.h"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display,Surf_Background,0,0);

    for(int i = 0; i < CEntity::EntityList.size(); i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(Surf_Display);
    }

    SDL_Flip(Surf_Display);
}
