#ifndef PLAYER_H
#define PLAYER_H

#include "stone.h"
#include "common.h"

class Board;
class Player
{
private:
	STONE_COLOR color_;
	Player* next_player_;
	bool is_pass_;

public:
	Player(STONE_COLOR color);
	
	void SetPlayerColor(STONE_COLOR color);
	void SetNextPlayer(Player* next_player);
	Player* GetNextPlayer();

	STONE_COLOR GetPlayerColor();
	void SetPassFlag(bool is_pass);
	bool IsPass();
	virtual bool AskPutStonePosition(Vec2d& put_pos, Board* board) = 0;
};

#endif // PLAYER_H