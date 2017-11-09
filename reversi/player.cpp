#include "player.h"

Player::Player(STONE_COLOR color)
{
	color_ = color;
	return;
}

void Player::SetPlayerColor(STONE_COLOR color)
{
	color_ = color;
	return;
}

STONE_COLOR Player::GetPlayerColor()
{
	return color_;
}
