#pragma once
#include "player.h"

class Board;
class Computer : public Player
{
private:
public:
	Computer(STONE_COLOR color);
	virtual bool AskPutStonePosition(Vec2d& put_pos, Board* board);
};
