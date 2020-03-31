// FourPlayer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Defines.h"


#include "Background.h"
#include "RectangleDrawer.h"
#include "Player.h"
#include "Ball.h"
#include "NPC.h"

std::vector<Ball>* ballsPointer;

int main(int argc, char* argv[])
{


	Background* MyBackground = new Background();
	RectangleDrawer* Playerbounds1 = new RectangleDrawer();
	RectangleDrawer* Playerbounds2 = new RectangleDrawer();
	RectangleDrawer* Playerbounds3 = new RectangleDrawer();
	RectangleDrawer* Playerbounds4 = new RectangleDrawer();

	Player* Player1 = new Player(ScreenWidth / 2 - (D_BouncerWidth / 2), ScreenHeight - D_RectangleSpace + 1); //// Spawn Player Centered in Screen

	NPC* NPC1 = new NPC(ScreenWidth / 2 - (D_BouncerWidth / 2), 0 + D_RectangleSpace - D_NPCHeight - 1, D_NPCWidth, D_NPCHeight, 0, 255, 0, 1);

	NPC* NPC2 = new NPC(0 + D_RectangleSpace - D_NPCHeight - 1, ScreenHeight / 2, D_NPCHeight, D_NPCWidth, 255, 0, 0, 2);

	NPC* NPC3 = new NPC(ScreenWidth - D_RectangleSpace + 1, ScreenHeight / 2, D_NPCHeight, D_NPCWidth, 0, 0, 255, 2);




	if (SDL_Init(SDL_INIT_VIDEO) == 0) {

		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;





		if (SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, 0, &window, &renderer) == 0) {

			SDL_bool done = SDL_FALSE;

			MyBackground->InitBackground(*renderer);

			//----- intializing vector somewhere in your code ----- //
			std::vector<Ball> balls;
			//----- adding new balls --------//
			for (int i = 0; i < 2; i++)
			{
				balls.push_back(Ball(ScreenWidth / 2 - D_BallDiameter, ScreenHeight / 2 - D_BallDiameter));
			}


			while (!done) {
				int before = SDL_GetTicks();
				SDL_Event event;
				{}
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


				//----- calling their functions -//
				for (auto& ball : balls) {
					ball.Render(*renderer);
					ball.Movement();
					ball.Collision(*Player1, *NPC1, *NPC2, *NPC3);
					ball.OutOfBounds();
				}


				SDL_RenderPresent(renderer);



				int after = SDL_GetTicks();
				int ticks = after - before;

				if (ticks < 16)
				{
					SDL_Delay(16 - ticks);
				}
				ticks = SDL_GetTicks() - before;

				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
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



	SDL_Quit();

	return 0;
}