#pragma once
#include "Defines.h"

class Menu
{
public:

	Menu();
	~Menu();

	void InitMenu(SDL_Renderer& renderer);
	void Render(SDL_Renderer& renderer);



private:

	TTF_Font* MenuFont;
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;




};

