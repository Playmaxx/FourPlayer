#pragma once
#include "Defines.h"
#include "Player.h"
#include "NPC.h"

class Ball
{
public:

	Ball(int PosX, int PosY);
	~Ball();

	void Render(SDL_Renderer& renderer);
	void Movement();
	void Collision(Player& Player1, NPC& NPC1, NPC& NPC2, NPC& NPC3);


	int const GetBallPosX();
	int const GetBallPosY();

	void inline SetBallPositionX(int x) {
		BallPosX = x;
	}
	void inline SetBallPositionY(int y) {
		BallPosY = y;
	}

private:

	

	float BallPosX;
	float BallPosY;

	float DirectionX = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
	float DirectionY = ((float)rand() / RAND_MAX) * (1 - -1) + -1;

	

};

inline const int Ball::GetBallPosX() {
	return BallPosX;
}
inline const int Ball::GetBallPosY() {
	return BallPosY;
}