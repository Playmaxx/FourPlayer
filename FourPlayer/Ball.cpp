#include "Ball.h"


Ball::Ball(float PosX, float PosY) :

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
	BallBox.w = D_BallDiameter;
	BallBox.h = D_BallDiameter;
	SDL_SetRenderDrawColor(&renderer, R, G, B, SDL_ALPHA_OPAQUE);

	SDL_RenderFillRect(&renderer, &BallBox);

}

void Ball::Movement()
{

	//std::cout << "DirectionX " << DirectionX << "\n";
	//std::cout << "DirectionY " << DirectionY << "\n";

	if (DirectionX <= 0.4 && DirectionX >= -0.4)
	{
		DirectionX = DirectionX * 2;
	}

	if (DirectionY <= 0.4 && DirectionY >= -0.4)
	{
		DirectionY = DirectionY * 2.0;
	}

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
		if (DirectionY > 0) {

			DirectionY = DirectionY * -1;
			DirectionX = DirectionX * ((BallPosX + D_BallRadius - (Player1.GetPlayerPosX() + D_BouncerWidth / 2)) / D_BouncerWidth);
			R = 255;
			G = 255;
			B = 0;
		}
	}


	if (BallPosX + D_BallRadius >= NPC1.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC1.GetNPCPosX() + D_BouncerWidth &&
		BallPosY + D_BallRadius >= NPC1.GetNPCPosY() + (D_BouncerHeight / 4) * 3 &&
		BallPosY + D_BallRadius <= NPC1.GetNPCPosY() + D_BouncerHeight)
	{
		if (DirectionY < 0) {
			DirectionY = DirectionY * -1;
			R = 0;
			G = 255;
			B = 0;
		}
	}

	if (BallPosX + D_BallRadius >= NPC2.GetNPCPosX() + (D_BouncerHeight / 4) * 3 &&
		BallPosX + D_BallRadius <= NPC2.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC2.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC2.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX < 0) {
			DirectionX = DirectionX * -1;
			R = 255;
			G = 0;
			B = 0;
		}
	}

	if (BallPosX + D_BallRadius >= NPC3.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC3.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC3.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC3.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX > 0) {
			DirectionX = DirectionX * -1;
			R = 0;
			G = 0;
			B = 255;
		}
	}

}
void Ball::OutOfBounds()
{
	if (BallPosX > ScreenWidth || BallPosX < 0 || BallPosY > ScreenHeight || BallPosY < 0)
	{
		BallPosX = ScreenWidth / 2 + D_BallDiameter;
		BallPosY = ScreenHeight / 2 + D_BallDiameter;
		R = 255;
		G = 255;
		B = 255;
		DirectionX = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
		DirectionY = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
	}
}