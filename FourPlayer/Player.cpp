#include "Player.h"


Player::Player(float PosX, float PosY) :

	PlayerPosX(PosX),
	PlayerPosY(PosY)

{}

Player::~Player()
{};


void Player::Render(SDL_Renderer& renderer)
{
	SDL_Rect PlayerBox;
	PlayerBox.x = PlayerPosX;
	PlayerBox.y = PlayerPosY;
	PlayerBox.w = D_BouncerWidth;
	PlayerBox.h = D_BouncerHeight;

	SDL_SetRenderDrawColor(&renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(&renderer, &PlayerBox);


} 

void Player::MovementInput()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_A]) {
		PlayerPosX = PlayerPosX - D_PlayerSpeed;
	}
	if (state[SDL_SCANCODE_D]) {
		PlayerPosX = PlayerPosX + D_PlayerSpeed;
	}

}

void Player::Colission()
{

	if (PlayerPosX >= ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1)
	{
		PlayerPosX = ScreenWidth - D_RectangleSpace - D_BouncerWidth + 1;
	}

	if (PlayerPosX <= 0 + D_RectangleSpace - 1)
	{
		PlayerPosX = 0 + D_RectangleSpace - 1;
	}
}