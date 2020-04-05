#pragma once
#include "Defines.h"

class Player
{

public:

	Player(float PosX, float PosY);
	~Player();

	void InitTextures(SDL_Renderer& renderer);

	void Render(SDL_Renderer& renderer);
	void MovementInput();
	
	void Colission();

	float const GetPlayerPosX();
	float const GetPlayerPosY();

	void inline SetPlayerPositionX(int x) {
		PlayerPosX = x;
	}
	void inline SetPlayerPositionY(int y) {
		PlayerPosY = y;
	}


private:

	float PlayerPosX;
	float PlayerPosY;
	SDL_Texture* PlayerTex;


};

inline const float Player::GetPlayerPosX() {
	return PlayerPosX;
}
inline const float Player::GetPlayerPosY() {
	return PlayerPosY;
}