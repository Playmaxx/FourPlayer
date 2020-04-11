#pragma once
#include "Defines.h"
#include "PointCounter.h"

class GameManager
{
public:

	GameManager();
	~GameManager();

	bool GameEnding(PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow);

	void InitRules(SDL_Renderer& renderer);

	void Render(SDL_Renderer& renderer);
	



private:

	TTF_Font* TutorialFont;
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage;
	SDL_Surface* surfaceMessage2;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
	SDL_Rect Message2_rect;
	SDL_Texture* Message2;
	


	int i = 0;





};

