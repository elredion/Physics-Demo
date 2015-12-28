#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            break;
        }

        case SDLK_RIGHT: {
            break;
        }

        case SDLK_SPACE: {
            break;
        }

        default: {
        }
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            break;
        }

        case SDLK_RIGHT: {

            break;
        }

        default: {
        }
    }
}
