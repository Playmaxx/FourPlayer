#pragma once
#include "Defines.h"

class Player
{

public:

	Player(float PosX, float PosY);
	~Player();

	void Render(SDL_Renderer& renderer);
	void MovementInput();
	
	void Colission();

	int const GetPlayerPosX();
	int const GetPlayerPosY();

	void inline SetPlayerPositionX(int x) {
		PlayerPosX = x;
	}
	void inline SetPlayerPositionY(int y) {
		PlayerPosY = y;
	}


private:

	float PlayerPosX;
	float PlayerPosY;



};

inline const int Player::GetPlayerPosX() {
	return PlayerPosX;
}
inline const int Player::GetPlayerPosY() {
	return PlayerPosY;
}