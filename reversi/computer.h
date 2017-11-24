#pragma once
#include "player.h"

class Computer : public Player
{
private:
public:
	Computer(STONE_COLOR color);
	virtual bool AskPutStonePosition();
};
