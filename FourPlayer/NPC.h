#pragma once
#include "Defines.h"
class Ball;

class NPC
{

public:

	NPC(float PosX, float PosY, int _Width, int _Height, int _ColorR, int _ColorG, int _ColorB, int _Orientation);
	~NPC();

	void Render(SDL_Renderer& renderer);
	void Movement(std::vector<Ball>* balls);

	void Colission();

	float const GetNPCPosX();
	float const GetNPCPosY();

	void inline SetNPCPositionX(float x) {
		NPCPosX = x;
	}
	void inline SetNPCPositionY(float y) {
		NPCPosY = y;
	}

	//std::vector<Ball> GetBallVector();

	/*void inline SetNPCPositionX(std::vector<Ball> B) {
		balls = B;
	}*/


private:

	float NPCPosX;
	float NPCPosY;
	int NPCWidth;
	int NPCHeight;
	int ColorR;
	int ColorG;
	int ColorB;
	int Orientation;
	
	//std::vector<Ball> balls;

};

inline const float NPC::GetNPCPosX() {
	return NPCPosX;
}
inline const float NPC::GetNPCPosY() {
	return NPCPosY;
}

//inline const std::vector<Ball> NPC::GetBallVector() {
//	return balls;
//}