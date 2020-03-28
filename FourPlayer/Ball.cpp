#include "Ball.h"


Ball::Ball(int PosX, int PosY) :

	BallPosX(PosX),
	BallPosY(PosY)

{};

Ball::~Ball()
{};

void Ball::Render(SDL_Renderer& renderer)
{
	SDL_Rect BallBox;
	BallBox.x = BallPosX;
	BallBox.y = BallPosY;
	BallBox.w = D_BallRadius;
	BallBox.h = D_BallRadius;
	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	SDL_RenderFillRect(&renderer, &BallBox);

}

void Ball::Movement()
{

	//std::cout << "DirectionX " << DirectionX << "\n";
	//std::cout << "DirectionY " << DirectionY << "\n";

	if (DirectionX * DirectionY != 0)
	{
		BallPosX = BallPosX + DirectionX * D_BallSpeed;
		BallPosY = BallPosY + DirectionY * D_BallSpeed;

	}

}



void Ball::Collision(Player& Player1)
{
	if (BallPosX + D_BallRadius >= Player1.GetPlayerPosX() &&
		BallPosX + D_BallRadius <= Player1.GetPlayerPosX() + D_PlayerWidth &&
		BallPosY + D_BallRadius >= Player1.GetPlayerPosY() &&
		BallPosY + D_BallRadius <= Player1.GetPlayerPosY() + D_PlayerWidth)
	{
		DirectionY = DirectionY * -1;
	}



}