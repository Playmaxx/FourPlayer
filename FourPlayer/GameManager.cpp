#include "GameManager.h"


GameManager::GameManager() :
	TutorialFont(TTF_OpenFont("Font/consolab.ttf", 150))
{}

GameManager::~GameManager()
{}


bool GameManager::GameEnding(PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow)
{


	if (Red.GetScore() > 9 || Green.GetScore() > 9 || Blue.GetScore() > 9 || Yellow.GetScore() > 9)
	{
		if (Red.GetScore() > 9) {
			std::cout << "RED WON" << "\n";
		}
		if (Green.GetScore() > 9) {
			std::cout << "GREEN WON" << "\n";
		}
		if (Blue.GetScore() > 9) {
			std::cout << "BLUE WON" << "\n";
		}
		if (Yellow.GetScore() > 9) {
			std::cout << "YELLOW WON" << "\n";
		}
		//std::cout << Yellow.GetScore() << "\n";
		return true;

	}

	return false;

};

void GameManager::InitRules(SDL_Renderer& renderer)
{

	surfaceMessage = TTF_RenderText_Blended(TutorialFont, "First to 10 Points wins", White);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);


	Message_rect.w = 500; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
	Message_rect.x = ScreenWidth / 2 - Message_rect.w / 2;  //controls the rect's x coordinate 
	Message_rect.y = ScreenHeight / 2 - Message_rect.h / 2 - 100; // controls the rect's y coordinte


}

void GameManager::Render(SDL_Renderer& renderer)
{
	if (i < 60 * 8)
	{
		SDL_RenderCopy(&renderer, Message, NULL, &Message_rect);
		i++;
	}
}