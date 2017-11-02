#ifndef CELL_H
#define CELL_H

enum class CELL_STATE
{
    EMPTY,
	AROUND,
    STONE
};

enum class STONE_COLOR;
class Stone;

class Cell
{
private:
    CELL_STATE cell_state_;
    Stone* stone_;

public:
    Cell();
    void SetStone(STONE_COLOR color);
    CELL_STATE GetCellState();
    STONE_COLOR GetStoneColor();
};

#endif // CELL_H
