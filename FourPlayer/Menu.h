#pragma once
#include "Defines.h"

class Menu
{
public:

	Menu(MenuScreens& _ScreenRef);
	~Menu();

	void InitMenu(SDL_Renderer& renderer, int _width, int _height);
	void Render(SDL_Renderer& renderer, MenuScreens& Screen);
	void GameOverScreen(SDL_Renderer& renderer);
	void SwitchScreen(SDL_MouseButtonEvent MouseEvent);

private:

	TTF_Font* MenuFont;
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;	
	SDL_Surface* EndscreenMessage;
	SDL_Texture* EMessage;
	SDL_Rect Message_rect;
	SDL_Rect Endscreen_rect;

	MenuScreens& ScreenRef;

	int x, y;

};

