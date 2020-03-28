#pragma once
#include "Defines.h"

class NPC
{

public:

	NPC(int PosX, int PosY, int _Width, int _Height, int _ColorR, int _ColorG, int _ColorB);
	~NPC();

	void Render(SDL_Renderer& renderer);
	void Movement();

	void Colission();

	int const GetNPCPosX();
	int const GetNPCPosY();

	void inline SetNPCPositionX(int x) {
		NPCPosX = x;
	}
	void inline SetNPCPositionY(int y) {
		NPCPosY = y;
	}


private:

	int NPCPosX;
	int NPCPosY;
	int NPCWidth;
	int NPCHeight;
	int ColorR;
	int ColorG;
	int ColorB;


};

inline const int NPC::GetNPCPosX() {
	return NPCPosX;
}
inline const int NPC::GetNPCPosY() {
	return NPCPosY;
}

