#include "human.h"

Human::Human(STONE_COLOR color) 
:Player(color)
{
}

Vec2d Human::PutStone()
{
	return Vec2d(0, 0);
}