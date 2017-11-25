#include "computer.h"

Computer::Computer(STONE_COLOR color)
	:Player(color)
{
}

bool Computer::AskPutStonePosition(Vec2d& put_pos)
{
	// set put_pos
	put_pos.first = 4;
	put_pos.second = 3;
	return false;
}
