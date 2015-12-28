#include "CApp.h"

bool CApp::OnInit(){

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) return false;

	if((Surf_Background = CSurface::OnLoad("background.jpg")) == NULL) return false;

	for(int i = 0; i < 2; i++)
    {
        if(Balls[i].OnLoad("ball.jpg", 44, 44, 1) == false) return false;
        CEntity::EntityList.push_back(&Balls[i]);
    }

    Balls[0].Pos = Vector2D(10,180);
    Balls[1].Pos = Vector2D(450,180);
    Balls[0].Vel = Vector2D(10,0);
    Balls[1].Vel = Vector2D(-10,0);


    Planes[0] = CPlane(1,0,0);
    Planes[1] = CPlane(0,1,0);
    Planes[2] = CPlane(-1,0,640);
    Planes[3] = CPlane(0,-1,430);

    CEntity::EntityList.push_back(&Planes[0]);
    CEntity::EntityList.push_back(&Planes[1]);
    CEntity::EntityList.push_back(&Planes[2]);
    CEntity::EntityList.push_back(&Planes[3]);


	return true;
}
