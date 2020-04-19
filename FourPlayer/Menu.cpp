#include "Menu.h"


Menu::Menu(MenuScreens& _ScreenRef) :
	MenuFont(TTF_OpenFont("Font/consolab.ttf", 150)),
	ScreenRef(_ScreenRef)
{}

Menu::~Menu()
{}

void Menu::InitMenu(SDL_Renderer& renderer, int _width, int _height)
{


	surfaceMessage = TTF_RenderText_Blended(MenuFont, "Start Game", White);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);


	Message_rect.w = _width; // controls the width of the rect
	Message_rect.h = _height; // controls the height of the rect
	Message_rect.x = ScreenWidth / 2 - Message_rect.w / 2;  //controls the rect's x coordinate 
	Message_rect.y = ScreenHeight / 2 - Message_rect.h / 2; // controls the rect's y coordinte





	Endscreen_rect.w = 900; // controls the width of the rect
	Endscreen_rect.h = 300; // controls the height of the rect
	Endscreen_rect.x = ScreenWidth / 2 - Endscreen_rect.w / 2;  //controls the rect's x coordinate 
	Endscreen_rect.y = ScreenHeight / 2 - Endscreen_rect.h / 2; // controls the rect's y coordinte
}

void Menu::Render(SDL_Renderer& renderer, MenuScreens& Screen)
{
	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(&renderer, Message, NULL, &Message_rect);
	SDL_RenderDrawRect(&renderer, &Message_rect);

}

void Menu::SwitchScreen(SDL_MouseButtonEvent MouseEvent) {

	if (MouseEvent.x >= Message_rect.x &&
		MouseEvent.x <= Message_rect.x + Message_rect.w &&
		MouseEvent.y >= Message_rect.y &&
		MouseEvent.y <= Message_rect.y + Message_rect.h)
	{
		ScreenRef = MenuScreens::Ingame;
	}
}

void Menu::GameOverScreen(SDL_Renderer& renderer)
{
	SDL_DestroyTexture(EMessage);
	SDL_FreeSurface(EndscreenMessage);

	EndscreenMessage = TTF_RenderText_Blended(MenuFont, "Game Over", White);
	EMessage = SDL_CreateTextureFromSurface(&renderer, EndscreenMessage);

	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(&renderer, EMessage, NULL, &Message_rect);

}