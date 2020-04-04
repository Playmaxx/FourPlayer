#pragma once
#include "Defines.h"
#include "Player.h"
#include "NPC.h"
#include "PointCounter.h"

class Ball
{
public:

	Ball(float PosX, float PosY);
	~Ball();

	void Render(SDL_Renderer& renderer);
	void Movement();
	void Collision(Player& Player1, NPC& NPC1, NPC& NPC2, NPC& NPC3);
	void OutOfBounds(SDL_Renderer& renderer, PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow);



	int const GetBallPosX();
	int const GetBallPosY();
	float const GetBallDirectionX();
	float const GetBallDirectionY();

	void inline SetBallPositionX(int x) {
		BallPosX = x;
	}
	void inline SetBallPositionY(int y) {
		BallPosY = y;
	}
	void inline SetBallDirectionX(int x) {
		DirectionX = x;
	}
	void inline SetBallDirectionY(int y) {
		DirectionY = y;
	}

private:

	SDL_Color cWhite = { 255, 255, 255 };
	SDL_Color cRed = { 255, 0, 0 };
	SDL_Color cGreen = { 0, 255, 0 };
	SDL_Color cBlue = { 0, 0, 255 };
	SDL_Color cYellow = { 255, 255, 0 };

	SDL_Color cColor = cWhite;



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
inline const float Ball::GetBallDirectionX() {
	return DirectionX;
}
inline const float Ball::GetBallDirectionY() {
	return DirectionY;
}