#ifndef _CAPP_H_
	#define _CAPP_H_

#include <SDL.h>
#include "Define.h"
#include "CSurface.h"
#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "CCamera.h"
#include "CPlayer.h"
#include "CContact.h"

class CApp : public CEvent
{
	private:
		bool Running;
		SDL_Surface* Surf_Display;
		SDL_Surface* Surf_Background;
        CBall Balls[2];
        CPlane Planes[4];

	public:
		CApp();
		int OnExecute();

	public:
		bool OnInit();
		void OnEvent(SDL_Event* Event);
		void OnExit();
		void OnLoop();
		void OnRender();
		void OnCleanup();
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicoide);
};

#endif
