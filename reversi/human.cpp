#include "human.h"
#include "vector2d.h"

Human::Human(STONE_COLOR color) 
:Player(color)
{
}

Vector2d Human::PutStone()
{
	return Vector2d(0, 0);
}