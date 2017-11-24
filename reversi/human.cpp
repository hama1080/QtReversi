#include "human.h"
#include "reversi.h"

Human::Human(STONE_COLOR color) 
:Player(color)
{
}

bool Human::AskPutStonePosition()
{
	Reversi::SetWaitingFlag(true);
	return true;
}