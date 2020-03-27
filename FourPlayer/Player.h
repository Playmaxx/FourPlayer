#pragma once
#include "Defines.h"

class Player
{

public:

	Player(int PosX, int PosY);
	~Player();

	void Render(SDL_Renderer& renderer);
	void MovementInput();
	
	void Colission();


private:

	int PlayerPosX;
	int PlayerPosY;

















};

