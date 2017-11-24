#include "computer.h"

Computer::Computer(STONE_COLOR color)
	:Player(color)
{
}

bool Computer::AskPutStonePosition()
{
	return false;
}
