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

Player* Player::GetNextPlayer()
{
	return next_player_;
}

STONE_COLOR Player::GetPlayerColor()
{
	return color_;
}

void Player::SetPassFlag(bool is_pass)
{
	is_pass_ = is_pass;
}

bool Player::IsPass()
{
	return is_pass_;
}
