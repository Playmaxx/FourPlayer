#pragma once
#include "Defines.h"
#include "Player.h"

class Ball
{
public:

	Ball(int PosX, int PosY);
	~Ball();

	void Render(SDL_Renderer& renderer);
	void Movement();
	void Collision(Player& Player1);

private:

	

	float BallPosX;
	float BallPosY;

	float DirectionX = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
	float DirectionY = ((float)rand() / RAND_MAX) * (1 - -1) + -1;

	



};

