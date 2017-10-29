#ifndef CELL_H
#define CELL_H

enum class CELL_STATE
{
    EMPTY,
    STONE
};

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
};

#endif // CELL_H
