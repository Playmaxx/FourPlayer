#include "NPC.h"



NPC::NPC(int PosX, int PosY, int _Width, int _Height, int _ColorR, int _ColorG, int _ColorB) :

	NPCPosX(PosX),
	NPCPosY(PosY),
	NPCWidth(_Width),
	NPCHeight(_Height),
	ColorR(_ColorR),
	ColorG(_ColorG),
	ColorB(_ColorB)

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

void NPC::Movement()
{
	for (auto& ball : balls) {
		ball.GetBallPosX();
		ball.GetBallPosY();
	}


}