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

void NPC::InitTextures(SDL_Renderer& renderer, std::string TexturName)
{

	std::string texturpfad = "Textures/" + TexturName;
	SDL_Surface* tmpSurface = IMG_Load(texturpfad.c_str());
	NPCTex = SDL_CreateTextureFromSurface(&renderer, tmpSurface);

}
void NPC::Render(SDL_Renderer& renderer)
{
	SDL_Rect NPCBox;
	NPCBox.x = NPCPosX;
	NPCBox.y = NPCPosY;
	NPCBox.w = NPCWidth;
	NPCBox.h = NPCHeight;

	SDL_RenderCopy(&renderer, NPCTex, NULL, &NPCBox);


}

void NPC::Movement(std::vector<Ball> *balls)
{
	Ball tempBallX = *balls->begin();
	Ball tempBallY = *balls->begin();
	float tempDistanceX = FLT_MAX;
	float tempDistanceY = FLT_MAX;

	//balls.push_back(Ball(ScreenWidth / 2 - D_BallDiameter, ScreenHeight / 2 - D_BallDiameter));

	for (auto& ball : *balls) {

		float tempX = abs(ball.GetBallPosX() - NPCPosX);

		if (tempX < tempDistanceX)
		{
			tempDistanceX = tempX;
			tempBallX = ball;
		}

		float tempY = abs(ball.GetBallPosY() - NPCPosY);

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
