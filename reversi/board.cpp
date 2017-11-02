#include "board.h"
#include "vector2d.h"
#include "cell.h"

Board::Board(unsigned int size_x, unsigned int size_y)
{
	for (unsigned int x = 0; x != size_x + 2; x++)
	{
		for (unsigned int y = 0; y != size_y + 2; y++)
		{
			Vector2d pos(x, y);

			if (x == 0 || x == size_x + 1 || y == 0 || y == size_y + 1)
				board_[pos] = Cell(CELL_STATE::AROUND);	// around playable area = AROUND cell
			else
				board_[pos] = Cell(CELL_STATE::EMPTY);	// playable area = EMPTY cell
		}

	}
}

