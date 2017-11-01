#pragma once

#include "player.h"

class Human : public Player
{
private:
public:
	virtual Vector2d PutStone();
};
