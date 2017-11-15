#include "human.h"
#include "reversi.h"

Human::Human(STONE_COLOR color) 
:Player(color)
{
}

void Human::AskPutStonePosition()
{
	Reversi::SetWaitingFlag(true);
	return;
}