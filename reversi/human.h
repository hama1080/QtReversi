#pragma once

#include "player.h"

class Human : public Player
{
private:
public:
	Human(STONE_COLOR color);
	virtual Vector2d PutStone();
};
