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



void Ball::Collision(Player& Player1, NPC& NPC1, NPC& NPC2, NPC& NPC3)
{
	if (BallPosX + D_BallRadius >= Player1.GetPlayerPosX() &&
		BallPosX + D_BallRadius <= Player1.GetPlayerPosX() + D_BouncerWidth &&
		BallPosY + D_BallRadius >= Player1.GetPlayerPosY() &&
		BallPosY + D_BallRadius <= Player1.GetPlayerPosY() + D_BouncerHeight / 4)
	{
		if (DirectionY > 0)
			DirectionY = DirectionY * -1;
	}

	if (BallPosX + D_BallRadius >= NPC1.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC1.GetNPCPosX() + D_BouncerWidth &&
		BallPosY + D_BallRadius >= NPC1.GetNPCPosY() + D_BouncerHeight / 4 * 3 &&
		BallPosY + D_BallRadius <= NPC1.GetNPCPosY() + D_BouncerHeight)
	{
		if (DirectionY < 0)
			DirectionY = DirectionY * -1;
	}

	if (BallPosX + D_BallRadius >= NPC2.GetNPCPosX() + D_BouncerHeight / 4 * 3 &&
		BallPosX + D_BallRadius <= NPC2.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC2.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC2.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX < 0)
			DirectionX = DirectionX * -1;
	}

	if (BallPosX + D_BallRadius >= NPC3.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC3.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC3.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC3.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX > 0)
			DirectionX = DirectionX * -1;
	}

	if (BallPosX > ScreenWidth || BallPosX < 0 || BallPosY > ScreenHeight || BallPosY < 0)
	{
		BallPosX = ScreenWidth / 2;
		BallPosY = ScreenHeight / 2;
	}


}