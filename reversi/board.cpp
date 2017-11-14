#include "board.h"
#include "cell.h"

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
