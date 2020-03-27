// FourPlayer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Defines.h"

#include "Background.h"
#include "RectangleDrawer.h"
#include "Player.h"


int main(int argc, char* argv[])
{


	Background* MyBackground = new Background();
	RectangleDrawer* Playerbounds1 = new RectangleDrawer();
	RectangleDrawer* Playerbounds2 = new RectangleDrawer();
	RectangleDrawer* Playerbounds3 = new RectangleDrawer();
	RectangleDrawer* Playerbounds4 = new RectangleDrawer();

	Player* Player1 = new Player(ScreenWidth / 2 - (D_PlayerWidth / 2), ScreenHeight - D_PlayerAbstand + 1); //// Spawn Player Centered in Screen

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {

		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		




		if (SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, 0, &window, &renderer) == 0) {

			SDL_bool done = SDL_FALSE;

			MyBackground->InitBackground(*renderer);



			while (!done) {
				int before = SDL_GetTicks();
				SDL_Event event;
				{}
				SDL_RenderClear(renderer);

				MyBackground->BackgroundRender(*renderer);


				Playerbounds1->Render(*renderer, 0 - 1, 0 - 1, 255, 0, 0);																//// RED
				Playerbounds2->Render(*renderer, ScreenWidth - D_PlayerAbstand + 1, 0 - 1, 0, 255, 0);									//// GREEN
				Playerbounds3->Render(*renderer, ScreenWidth - D_PlayerAbstand + 1, ScreenHeight - D_PlayerAbstand + 1, 0, 0, 255);		//// BLUE
				Playerbounds4->Render(*renderer, 0 - 1, ScreenHeight - D_PlayerAbstand + 1, 255, 255, 0);								//// YELLOW



				
				Player1->Render(*renderer);
				Player1->MovementInput();
				Player1->Colission();












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