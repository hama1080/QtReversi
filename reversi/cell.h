#ifndef CELL_H
#define CELL_H

enum class CELL_STATE
{
    EMPTY,
    BLACK,
    WHITE
};

class Cell
{
private:
    CELL_STATE cell_state_;

public:
    Cell();
    void SetCellState();
    CELL_STATE GetCellState();

    void Reverse();
};

#endif // CELL_H
