#ifndef BOARD_H
#define BOARD_H

#include <map>
#include "stone.h"
using namespace std;

class Vector2d;
class Cell;

class Board
{
private:
	map<Vector2d, Cell> board_;
	map<STONE_COLOR, unsigned int> stone_cnt_; // Express the number of each stone.

public:
    Board();
	
	void Initialize();
	void PutStone(Vector2d pos);
};

#endif // BOARD_H