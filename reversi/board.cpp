#include "board.h"
#include "cell.h"
#include <iostream>
using namespace std;

map<Vec2d, vector<Vec2d>> Board::SearchPossiblePutPos(STONE_COLOR player_color)
{
	// search empty cell
	vector<Vec2d> empty_cell_list;
	for (unsigned int x = 0; x != board_size_.first + 2; x++){
		for (unsigned int y = 0; y != board_size_.second + 2; y++){
			Vec2d pos(x, y);
			if (board_[pos].GetCellState() == CELL_STATE::EMPTY)
				empty_cell_list.push_back(pos);
		}
	}

	// check player_stone can put on empty cell
	for (auto empty_cell : empty_cell_list)
	{
		//cout << "empty cell: " << empty_cell.first << ", " << empty_cell.second << endl;
		for (auto dir : kDirectionList)
		{
			Vec2d dir_pos(empty_cell.first + dir.first, empty_cell.second + dir.second);
			if (board_[dir_pos].GetCellState() == CELL_STATE::EMPTY ||
				board_[dir_pos].GetCellState() == CELL_STATE::AROUND)
				continue;

			//cout << "pos: " << pos.first << ", " << pos.second << endl;
			if (board_[dir_pos].GetStoneColor() != player_color)
			{
				for (unsigned int tmp = 2; tmp != 10; tmp++)
				{
					Vec2d check_pos(empty_cell.first + dir.first * tmp, empty_cell.second + dir.second * tmp);
					//cout << "check_pos: " << check_pos.first << ", " << check_pos.second << endl;
					if (board_[check_pos].GetCellState() == CELL_STATE::EMPTY ||
						board_[check_pos].GetCellState() == CELL_STATE::AROUND)
						break;

					if (board_[check_pos].GetStoneColor() == player_color)
					{
						cout << "posiible_pos: " << empty_cell.first << ", " << empty_cell.second << endl;
						break;
					}
				}
			}

		}

	}

	return map<Vec2d, vector<Vec2d>>();
}

Board::Board(unsigned int size_x, unsigned int size_y)
:board_size_(size_x, size_y)
{
	for (unsigned int x = 0; x != size_x + 2; x++)
	{
		for (unsigned int y = 0; y != size_y + 2; y++)
		{
			Vec2d pos(x, y);
			if (x == 0 || x == size_x + 1 || y == 0 || y == size_y + 1)
				board_[pos] = Cell(CELL_STATE::AROUND);	// around playable area = AROUND cell
			else
				board_[pos] = Cell(CELL_STATE::EMPTY);	// playable area = EMPTY cell
		}
	}

	// set initial stone
	unsigned int x0 = size_x / 2;
	unsigned int x1 = size_x / 2 + 1;
	unsigned int y0 = size_y / 2;
	unsigned int y1 = size_y / 2 + 1;
	board_[Vec2d(x0, y0)].SetStone(STONE_COLOR::WHITE);
	board_[Vec2d(x0, y1)].SetStone(STONE_COLOR::BLACK);
	board_[Vec2d(x1, y0)].SetStone(STONE_COLOR::BLACK);
	board_[Vec2d(x1, y1)].SetStone(STONE_COLOR::WHITE);

}

Vec2d Board::GetBoardSize()
{
	return board_size_;
}

Cell Board::GetCell(Vec2d pos)
{
	return board_[pos];
}

void Board::PutStone(Vec2d pos, STONE_COLOR color)
{
	board_[pos].SetStone(color);
	return;
}
