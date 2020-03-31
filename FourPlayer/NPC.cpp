#include "NPC.h"
#include "Ball.h"


NPC::NPC(float PosX, float PosY, int _Width, int _Height, int _ColorR, int _ColorG, int _ColorB, int _Orientation) :

	NPCPosX(PosX),
	NPCPosY(PosY),
	NPCWidth(_Width),
	NPCHeight(_Height),
	ColorR(_ColorR),
	ColorG(_ColorG),
	ColorB(_ColorB),
	Orientation(_Orientation)

{}

NPC::~NPC()
{};


void NPC::Render(SDL_Renderer& renderer)
{
	SDL_Rect NPCBox;
	NPCBox.x = NPCPosX;
	NPCBox.y = NPCPosY;
	NPCBox.w = NPCWidth;
	NPCBox.h = NPCHeight;

	SDL_SetRenderDrawColor(&renderer, ColorR, ColorG, ColorB, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(&renderer, &NPCBox);


}

void NPC::Movement(std::vector<Ball>* balls)
{
	Ball tempBallX = *balls->begin();
	Ball tempBallY = *balls->begin();
	float tempDistanceX = 500;
	float tempDistanceY = FLT_MAX;

	for (auto& ball : *balls) {

		float tempX = ball.GetBallPosX() - NPCPosX;

		

		if (ball.GetBallDirectionX() <= 0) {
			//std::cout << ball.GetBallDirectionX() << "\n";
			if (tempX < tempDistanceX)
			{
				tempDistanceX = tempX;
				tempBallX = ball;
			}
		}

		if (ball.GetBallDirectionX() >= 0) {
			//std::cout << ball.GetBallDirectionX() << "\n";
			if (tempX > tempDistanceX) ///// HIER FIXEN
			{
				tempDistanceX = tempX;
				tempBallX = ball;
			}
		}


		/*	if (tempX > tempDistanceX && ball.GetBallDirectionX() >= 0)
			{
				tempDistanceX = tempX;
				tempBallX = ball;
			}*/

		float tempY = ball.GetBallPosY() - NPCPosY;

		if (tempY < tempDistanceY)
		{
			tempDistanceY = tempY;
			tempBallY = ball;
		}

	}

	if (Orientation == 1)
	{

		if ((tempBallY.GetBallPosX() + D_BallRadius) - (NPCPosX + D_BouncerWidth / 2) > 0)
			NPCPosX = NPCPosX + D_PlayerSpeed;
		if ((tempBallY.GetBallPosX() + D_BallRadius) - (NPCPosX + D_BouncerWidth / 2) < 0)
			NPCPosX = NPCPosX - D_PlayerSpeed;
	}

	if (Orientation == 2)
	{

		if ((tempBallX.GetBallPosY() + D_BallRadius) - (NPCPosY + D_BouncerWidth / 2) > 0)
			NPCPosY = NPCPosY + D_PlayerSpeed;
		if ((tempBallX.GetBallPosY() + D_BallRadius) - (NPCPosY + D_BouncerWidth / 2) < 0)
			NPCPosY = NPCPosY - D_PlayerSpeed;
	}

}


void NPC::Colission()
{
	if (Orientation == 1)
	{
		if (NPCPosX >= ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1)
		{
			NPCPosX = ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1;
		}

		if (NPCPosX <= 0 + D_RectangleSpace - 1)
		{
			NPCPosX = 0 + D_RectangleSpace - 1;
		}
	}
	if (Orientation == 2)
	{
		if (NPCPosY >= ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1)
		{
			NPCPosY = ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1;
		}

		if (NPCPosY <= 0 + D_RectangleSpace - 1)
		{
			NPCPosY = 0 + D_RectangleSpace - 1;
		}
	}

}
