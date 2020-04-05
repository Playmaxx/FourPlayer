#include "PointCounter.h"


PointCounter::PointCounter(int _x, int _y) :
	PointFont(TTF_OpenFont("Font/consolab.ttf", 150))
{
	PosX = _x + 33;
	PosY = _y + 27;
};

PointCounter::~PointCounter()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
};

void PointCounter::InitPoints(SDL_Renderer& renderer)
{
	std::string scoreText = std::to_string(Score);
	surfaceMessage = TTF_RenderText_Blended(PointFont, scoreText.c_str(), Black);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);


	Message_rect.w = D_RectangleSpace / 3 ; // controls the width of the rect
	Message_rect.h = D_RectangleSpace / 2; // controls the height of the rect
	Message_rect.x = PosX;  //controls the rect's x coordinate 
	Message_rect.y = PosY; // controls the rect's y coordinte

}

void PointCounter::Render(SDL_Renderer& renderer)
{

	SDL_RenderCopy(&renderer, Message, NULL, &Message_rect);



}

void PointCounter::UpdatePoints(SDL_Renderer& renderer)
{

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	Score = Score + 1;
	std::string scoreText = std::to_string(Score);
	surfaceMessage = TTF_RenderText_Blended(PointFont, scoreText.c_str(), Black);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);
}