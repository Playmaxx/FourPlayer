#include "RectangleDrawer.h"



void RectangleDrawer::Render(SDL_Renderer& renderer, int PosX, int PosY, int R, int G, int B)
{

	SDL_Rect Boundaries;
	Boundaries.x = PosX;
	Boundaries.y = PosY;
	Boundaries.w = D_PlayerAbstand;
	Boundaries.h = D_PlayerAbstand;
	SDL_SetRenderDrawColor(&renderer, R, G, B, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(&renderer, &Boundaries);
	


};