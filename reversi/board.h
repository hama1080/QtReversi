#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include "stone.h"
#include "common.h"
using namespace std;

enum class PreProcessState
{
	CanPut,
	Pass,
};

class Cell;

class Board
{
private:
	map<Vec2d, vector<Vec2d>> possible_pos_map_;

	const Vec2d board_size_;
	map<Vec2d, Cell> board_;
	map<STONE_COLOR, unsigned int> stone_cnt_; // Express the number of each stone.
	map<Vec2d, vector<Vec2d>> SearchPossiblePutPos(STONE_COLOR player_color);

public:
    Board(unsigned int size_x = 8, unsigned int size_y = 8);
	
	void Initialize();
	Vec2d GetBoardSize();
	Cell GetCell(Vec2d pos);

	void PutStone(Vec2d pos, STONE_COLOR color);
	map<STONE_COLOR, unsigned int> GetStoneCnt();
	map<Vec2d, vector<Vec2d>> GetPossiblePutPos();

	PreProcessState PreProcess(STONE_COLOR player_color);
	bool PostProcess(STONE_COLOR player_color, Vec2d put_pos);
};

#endif // BOARD_H