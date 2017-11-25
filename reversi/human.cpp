#include "human.h"
#include "reversi.h"

Human::Human(STONE_COLOR color) 
:Player(color)
{
}

bool Human::AskPutStonePosition(Vec2d& put_pos, Board* board)
{
	// not use put_pos
	Reversi::SetWaitingFlag(true);
	return true;
}