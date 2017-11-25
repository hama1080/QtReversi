#include "computer.h"
#include "board.h"

Computer::Computer(STONE_COLOR color)
	:Player(color)
{
}

bool Computer::AskPutStonePosition(Vec2d& put_pos, Board* board)
{
	map<Vec2d, vector<Vec2d>> possible_pos_map = board->GetPossiblePutPos();

	// set put_pos
	put_pos.first = possible_pos_map.begin()->first.first;		//tmp
	put_pos.second = possible_pos_map.begin()->first.second;	//tmp
	return false;
}
