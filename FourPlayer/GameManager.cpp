#include "GameManager.h"


GameManager::GameManager(MenuScreens& _ScreenRef) :
	TutorialFont(TTF_OpenFont("Font/consolab.ttf", 150)),
	ScreenRef(_ScreenRef)
{}

GameManager::~GameManager()
{}


void GameManager::GameEnding(PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow)
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
		ScreenRef = MenuScreens::Endscreen;
	}
};

void GameManager::InitRules(SDL_Renderer& renderer)
{
	Message_rect.w = 500; // controls the width of the rect
	Message_rect.h = 80; // controls the height of the rect
	Message_rect.x = ScreenWidth / 2 - Message_rect.w / 2;  //controls the rect's x coordinate 
	Message_rect.y = ScreenHeight / 2 +200; // controls the rect's y coordinte

	surfaceMessage = TTF_RenderText_Blended(TutorialFont, "First to 10 Points wins", White);
	Message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);

	Message2_rect.w = 500; // controls the width of the rect
	Message2_rect.h = 70; // controls the height of the rect
	Message2_rect.x = ScreenWidth / 2 - Message_rect.w / 2;  //controls the rect's x coordinate 
	Message2_rect.y = ScreenHeight / 2 + 300; // controls the rect's y coordinte

	surfaceMessage2 = TTF_RenderText_Blended(TutorialFont, "Use A / D to move", White);
	Message2 = SDL_CreateTextureFromSurface(&renderer, surfaceMessage2);
}

void GameManager::Render(SDL_Renderer& renderer)
{

		SDL_RenderCopy(&renderer, Message, NULL, &Message_rect);
		SDL_RenderCopy(&renderer, Message2, NULL, &Message2_rect);

}