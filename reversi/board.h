#ifndef BOARD_H
#define BOARD_H

#include <map>
#include "stone.h"
#include "common.h"
using namespace std;

class Cell;

class Board
{
private:
	const Vec2d board_size_;
	map<Vec2d, Cell> board_;
	map<STONE_COLOR, unsigned int> stone_cnt_; // Express the number of each stone.

public:
    Board(unsigned int size_x = 8, unsigned int size_y = 8);
	
	void Initialize();
	Vec2d GetBoardSize();
	Cell GetCell(Vec2d pos);

	void PutStone(Vec2d pos, STONE_COLOR color);
};

#endif // BOARD_H