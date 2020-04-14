// FourPlayer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Defines.h"


#include "Background.h"
#include "RectangleDrawer.h"
#include "Player.h"
#include "Ball.h"
#include "NPC.h"
#include "Menu.h"
#include "PointCounter.h"
#include "GameManager.h"

std::vector<Ball>* ballsPointer;

int main(int argc, char* argv[])
{
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	IMG_Init(IMG_INIT_JPG);

	Background* MyBackground = new Background();
	RectangleDrawer* Playerbounds1 = new RectangleDrawer();
	RectangleDrawer* Playerbounds2 = new RectangleDrawer();
	RectangleDrawer* Playerbounds3 = new RectangleDrawer();
	RectangleDrawer* Playerbounds4 = new RectangleDrawer();

	Player* Player1 = new Player(ScreenWidth / 2 - (D_BouncerWidth / 2), ScreenHeight - D_RectangleSpace + 1); //// Spawn Player Centered in Screen

	NPC* NPC1 = new NPC(ScreenWidth / 2 - (D_BouncerWidth / 2), 0 + D_RectangleSpace - D_NPCHeight - 1, D_NPCWidth, D_NPCHeight, 0, 255, 0, 1);

	NPC* NPC2 = new NPC(0 + D_RectangleSpace - D_NPCHeight - 1, ScreenHeight / 2, D_NPCHeight, D_NPCWidth, 255, 0, 0, 2);

	NPC* NPC3 = new NPC(ScreenWidth - D_RectangleSpace + 1, ScreenHeight / 2, D_NPCHeight, D_NPCWidth, 0, 0, 255, 2);

	//Menu* MainMenu = new Menu;

	PointCounter* Red = new PointCounter(0 - 1, 0 - 1);
	PointCounter* Green = new PointCounter(ScreenWidth - D_RectangleSpace + 1, 0 - 1);
	PointCounter* Blue = new PointCounter(ScreenWidth - D_RectangleSpace + 1, ScreenHeight - D_RectangleSpace + 1);
	PointCounter* Yellow = new PointCounter(0 - 1, ScreenHeight - D_RectangleSpace + 1);

	GameManager* GameRules = new GameManager();

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {


		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;





		if (SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, 0, &window, &renderer) == 0) {

			//SDL_bool done = SDL_FALSE;

			MyBackground->InitBackground(*renderer);
			Player1->InitTextures(*renderer);
			NPC1->InitTextures(*renderer, "Bouncer2.bmp");
			NPC2->InitTextures(*renderer, "Bouncer3.bmp");
			NPC3->InitTextures(*renderer, "Bouncer4.bmp");

			GameRules->InitRules(*renderer);

			//MainMenu->InitMenu(*renderer, D_RectangleSpace, D_RectangleSpace);
			Red->InitPoints(*renderer);
			Green->InitPoints(*renderer);
			Blue->InitPoints(*renderer);	
			Yellow->InitPoints(*renderer);

			//----- intializing vector somewhere in your code ----- //
			std::vector<Ball> balls;
			//----- adding new balls --------//
			balls.push_back(Ball(ScreenWidth / 2 - D_BallDiameter, ScreenHeight / 2 - D_BallDiameter));

			int MakeShiftTimer = 0;

			while (DONE == 0) {
				int before = SDL_GetTicks();
				SDL_Event event;
			
				SDL_RenderClear(renderer);



				MyBackground->BackgroundRender(*renderer);


				Playerbounds1->Render(*renderer, 0 - 1, 0 - 1, 255, 0, 0);																//// RED
				Playerbounds2->Render(*renderer, ScreenWidth - D_RectangleSpace + 1, 0 - 1, 0, 255, 0);									//// GREEN
				Playerbounds3->Render(*renderer, ScreenWidth - D_RectangleSpace + 1, ScreenHeight - D_RectangleSpace + 1, 0, 0, 255);		//// BLUE
				Playerbounds4->Render(*renderer, 0 - 1, ScreenHeight - D_RectangleSpace + 1, 255, 255, 0);								//// YELLOW


				Player1->Render(*renderer);
				Player1->MovementInput();
				Player1->Colission();


				NPC1->Movement(&balls);
				NPC1->Colission();
				NPC1->Render(*renderer);

				NPC2->Movement(&balls);
				NPC2->Colission();
				NPC2->Render(*renderer);

				NPC3->Movement(&balls);
				NPC3->Colission();
				NPC3->Render(*renderer);

				//MainMenu->Render(*renderer);
				Red->Render(*renderer);
				Green->Render(*renderer);
				Blue->Render(*renderer);
				Yellow->Render(*renderer);

				GameRules->Render(*renderer);


				//----- calling their functions -//
				for (auto& ball : balls) {
					ball.Render(*renderer);
					ball.Movement();
					ball.Collision(*Player1, *NPC1, *NPC2, *NPC3);
					ball.OutOfBounds(*renderer, *Red, *Green, *Blue, *Yellow);
				}

				if (MakeShiftTimer == 60 * 10)
				{
					balls.push_back(Ball(ScreenWidth / 2 - D_BallDiameter, ScreenHeight / 2 - D_BallDiameter));
					MakeShiftTimer = 0;
				}

				SDL_RenderPresent(renderer);
				MakeShiftTimer++;


				int after = SDL_GetTicks();
				int ticks = after - before;

				if (ticks < 16)
				{
					SDL_Delay(16 - ticks);
				}
				ticks = SDL_GetTicks() - before;


				if (GameRules->GameEnding(*Red, *Green, *Blue, *Yellow))
				{
					SDL_Delay(1000);
					DONE = 1;
				}


				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						DONE = 1;
					}
				}
			}
		}


		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	delete MyBackground;
	delete Player1;
	delete Playerbounds1;
	delete Playerbounds2;
	delete Playerbounds3;
	delete Playerbounds4;
	delete NPC1;
	delete NPC2;
	delete NPC3;
	delete Red;
	delete Green;
	delete Blue;
	delete Yellow;
	delete GameRules;




	TTF_Quit();
	SDL_Quit();

	return 0;
}