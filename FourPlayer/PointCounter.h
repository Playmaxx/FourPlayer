#pragma once
#include "Defines.h"


class PointCounter
{
public:


	PointCounter( int _x, int _y);
	~PointCounter();

	void InitPoints(SDL_Renderer& renderer);
	void Render(SDL_Renderer& renderer);
	void UpdatePoints(SDL_Renderer& renderer);

private:

	TTF_Font* PointFont;
	SDL_Color Black = { 0, 0, 0 };
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect;

	int Score = 0;

	int PosX;
	int PosY;
	//std::string scoreText = std::to_string(Score);


};

