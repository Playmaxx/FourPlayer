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


	SDL_SetRenderDrawColor(&renderer, cColor.r, cColor.g, cColor.b, SDL_ALPHA_OPAQUE);

	SDL_RenderFillRect(&renderer, &BallBox);

}

void Ball::Movement()
{

	BallPosX = BallPosX + DirectionX * D_BallSpeed;
	BallPosY = BallPosY + DirectionY * D_BallSpeed;
	//std::cout << "DirectionX " << DirectionX << "\n";
	//std::cout << "DirectionY " << DirectionY << "\n";
	if (cColor.r == cWhite.r && cColor.g == cWhite.g && cColor.b == cWhite.b)
	{
		if (DirectionX <= 0.6 && DirectionX >= -0.6)
		{
			DirectionX = DirectionX * 2;
		}

		if (DirectionY <= 0.6 && DirectionY >= -0.6)
		{
			DirectionY = DirectionY * 2.0;
		}
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
			cColor = cYellow;
			//std::cout << "DirectionY" << DirectionY << "\n";

			DirectionX = (((BallPosX + D_BallRadius) - (Player1.GetPlayerPosX() + (D_BouncerWidth / 2))) / (D_BouncerWidth / 2));

			//std::cout << "BallPosX" << BallPosX << "\n";
			//std::cout << "PlayerPosX" << Player1.GetPlayerPosX() << "\n";

			if (DirectionY <= 0.6 && DirectionY >= -0.6)
			{
				DirectionY = DirectionY * 2.0;
			}
			//std::cout << "DirectionX" << DirectionX << "\n";
		}
	}

	if (BallPosX + D_BallRadius >= NPC1.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC1.GetNPCPosX() + D_BouncerWidth &&
		BallPosY + D_BallRadius >= NPC1.GetNPCPosY() + (D_BouncerHeight / 4) * 3 &&
		BallPosY + D_BallRadius <= NPC1.GetNPCPosY() + D_BouncerHeight)
	{
		if (DirectionY < 0) {
			DirectionY = DirectionY * -1;
			cColor = cGreen;

			DirectionX = (((BallPosX + D_BallRadius) - (NPC1.GetNPCPosX() + (D_BouncerWidth / 2))) / (D_BouncerWidth / 2));

			if (DirectionY <= 0.6 && DirectionY >= -0.6)
			{
				DirectionY = DirectionY * 2.0;
			}
		}
	}

	if (BallPosX + D_BallRadius >= NPC2.GetNPCPosX() + (D_BouncerHeight / 4) * 3 &&
		BallPosX + D_BallRadius <= NPC2.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC2.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC2.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX < 0) {
			DirectionX = DirectionX * -1;
			cColor = cRed;

			DirectionY = (((BallPosY + D_BallRadius) - (NPC2.GetNPCPosY() + (D_BouncerWidth / 2))) / (D_BouncerWidth / 2));

			if (DirectionX <= 0.6 && DirectionX >= -0.6)
			{
				DirectionX = DirectionX * 2.0;
			}
		}

	}

	if (BallPosX + D_BallRadius >= NPC3.GetNPCPosX() &&
		BallPosX + D_BallRadius <= NPC3.GetNPCPosX() + D_BouncerHeight &&
		BallPosY + D_BallRadius >= NPC3.GetNPCPosY() &&
		BallPosY + D_BallRadius <= NPC3.GetNPCPosY() + D_BouncerWidth)
	{
		if (DirectionX > 0) {
			DirectionX = DirectionX * -1;
			cColor = cBlue;

			DirectionY = (((BallPosY + D_BallRadius) - (NPC3.GetNPCPosY() + (D_BouncerWidth / 2))) / (D_BouncerWidth / 2));

			if (DirectionX <= 0.6 && DirectionX >= -0.6)
			{
				DirectionX = DirectionX * 2.0;
			}
		}
	}
}

void Ball::OutOfBounds(SDL_Renderer& renderer, PointCounter& Red, PointCounter& Green, PointCounter& Blue, PointCounter& Yellow)
{
	if (BallPosX > ScreenWidth || BallPosX < 0 || BallPosY > ScreenHeight || BallPosY < 0)
	{
		if (cColor.r == cYellow.r && cColor.g == cYellow.g && cColor.b == cYellow.b) {

			Yellow.UpdatePoints(renderer);
			//std::cout << "Yellow Point" << "\n";
		}
		if (cColor.r == cRed.r && cColor.g == cRed.g && cColor.b == cRed.b) {

			Red.UpdatePoints(renderer);
			//std::cout << "Red Point" << "\n";
		}
		if (cColor.r == cGreen.r && cColor.g == cGreen.g && cColor.b == cGreen.b) {

			Green.UpdatePoints(renderer);
			//std::cout << "Green Point" << "\n";
		}
		if (cColor.r == cBlue.r && cColor.g == cBlue.g && cColor.b == cBlue.b) {

			Blue.UpdatePoints(renderer);
			//std::cout << "Blue Point" << "\n";
		}

		BallPosX = ScreenWidth / 2 - D_BallDiameter;
		BallPosY = ScreenHeight / 2 - D_BallDiameter;
		cColor = cWhite;

		DirectionX = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
		DirectionY = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
	}
	if ((abs(BallPosX + D_BallRadius - ScreenWidth / 2) > ScreenWidth / 2 - D_RectangleSpace + 1)
		&& (abs(BallPosY + D_BallRadius - ScreenHeight / 2) > ScreenWidth / 2 - D_RectangleSpace + 1))
	{
		BallPosX = ScreenWidth / 2 + D_BallDiameter;
		BallPosY = ScreenHeight / 2 + D_BallDiameter;
		cColor = cWhite;

		DirectionX = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
		DirectionY = ((float)rand() / RAND_MAX) * (1 - -1) + -1;
	}
}

