#include "NPC.h"
#include "Ball.h"


NPC::NPC(int PosX, int PosY, int _Width, int _Height, int _ColorR, int _ColorG, int _ColorB, int _Orientation) :

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
	Ball tempBall = *balls->begin();
	int tempDistance = INT_MAX;

	for (auto& ball : *balls) {

		int temp = hypot(ball.GetBallPosX() - NPCPosX, ball.GetBallPosY() - NPCPosY);
		if (temp < tempDistance)
		{
			tempDistance = temp;
			tempBall = ball;

		}

	}
	std::cout << tempDistance << "\n";
	if (Orientation == 1)
	{

		if (tempBall.GetBallPosX() - NPCPosX > 0)
			NPCPosX = NPCPosX + D_PlayerSpeed;
		if (tempBall.GetBallPosX() - NPCPosX < 0)
			NPCPosX = NPCPosX - D_PlayerSpeed;
	}
	if (Orientation == 2)
	{

		if (tempBall.GetBallPosY() - NPCPosY > 0)
			NPCPosY = NPCPosY + D_PlayerSpeed;
		if (tempBall.GetBallPosY() - NPCPosY < 0)
			NPCPosY = NPCPosY - D_PlayerSpeed;
	}

}


void NPC::Colission()
{
	if (Orientation == 1) {
		if (NPCPosX >= ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1)
		{
			NPCPosX = ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1;
		}

		if (NPCPosX <= 0 + D_RectangleSpace - 1)
		{
			NPCPosX = 0 + D_RectangleSpace - 1;
		}
	}
	if (Orientation == 2) {
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
