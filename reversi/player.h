#ifndef PLAYER_H
#define PLAYER_H

#include "stone.h"

class Vector2d;
class Player
{
private:
	STONE_COLOR color_;
	Player* next_player_;

public:
	Player(STONE_COLOR color);
	
	void SetPlayerColor(STONE_COLOR color);
	void SetNextPlayer(Player* next_player);
	Player* GetNextPlayer();

	STONE_COLOR GetPlayerColor();
	virtual Vector2d PutStone() = 0;
};

#endif // PLAYER_H