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

void Player::SetNextPlayer(Player* next_player)
{
	next_player_ = next_player;
	return;
}

STONE_COLOR Player::GetPlayerColor()
{
	return color_;
}
