#include "Background.h"




SDL_Texture* BackgroundTex;

void Background::InitBackground(SDL_Renderer& renderer)
{

	SDL_Surface* tmpSurface = IMG_Load("Textures/Background.bmp");
	BackgroundTex = SDL_CreateTextureFromSurface(&renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);


	std::cout << "Rendered Background" << "\n";

}

void Background::BackgroundRender(SDL_Renderer& renderer)
{

	SDL_RenderCopy(&renderer, BackgroundTex, NULL, NULL);

}

