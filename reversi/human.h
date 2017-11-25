#pragma once

#include "player.h"

class Board;
class Human : public Player
{
private:
public:
	Human(STONE_COLOR color);
	virtual bool AskPutStonePosition(Vec2d& put_pos, Board* board);
};
