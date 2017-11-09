#ifndef BOARD_H
#define BOARD_H

#define Vec2d pair<unsigned int, unsigned int> 
#include <map>
#include "stone.h"
#include "vector2d.h"
using namespace std;

class Cell;

class Board
{
private:
	const Vector2d board_size_;
	map<Vector2d, Cell> board_;
	map<STONE_COLOR, unsigned int> stone_cnt_; // Express the number of each stone.

public:
    Board(unsigned int size_x = 8, unsigned int size_y = 8);
	
	void Initialize();
	void PutStone(Vector2d pos);
	Cell GetCell(Vector2d pos);
	Vector2d GetBoardSize();
};

#endif // BOARD_H