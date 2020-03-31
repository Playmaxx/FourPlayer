#include "Menu.h"


Menu::Menu() :
	MenuFont(TTF_OpenFont("Font/consolab.ttf", 150))
{}

Menu::~Menu()
{}

void Menu::InitMenu(SDL_Renderer& renderer)
{


	White = { 255, 255, 255 };
	surfaceMessage = TTF_RenderText_Blended(MenuFont, "Play", White);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);


	Message_rect.w = 200; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
	Message_rect.x = ScreenWidth / 2 - Message_rect.w / 2;  //controls the rect's x coordinate 
	Message_rect.y = ScreenHeight / 2 - Message_rect.h / 2; // controls the rect's y coordinte



}

void Menu::Render(SDL_Renderer& renderer)
{
	SDL_RenderCopy(&renderer, Message, NULL, &Message_rect);
}