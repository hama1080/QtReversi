#include "computer.h"
#include "board.h"
#include <random>

using namespace std;

Computer::Computer(STONE_COLOR color)
	:Player(color)
{
}

bool Computer::AskPutStonePosition(Vec2d& put_pos, Board* board)
{
	map<Vec2d, vector<Vec2d>> possible_pos_map = board->GetPossiblePutPos();

	random_device rnd;
	vector<Vec2d> possible_pos_vec;
	size_t index = rnd() % possible_pos_map.size();
	for (auto possible_pos : possible_pos_map)
		possible_pos_vec.push_back(possible_pos.first);

	// set put_pos
	put_pos.first = (possible_pos_vec.begin() + index)->first;
	put_pos.second = (possible_pos_vec.begin() + index)->second;
	return false;
}
