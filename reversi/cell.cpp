#include "cell.h"

Cell::Cell()
{
    cell_state_ = CELL_STATE::EMPTY;
    return;
}

void Cell::SetCellState(CELL_STATE state)
{
    cell_state_ = state;
    return;
}

CELL_STATE Cell::GetCellState()
{
    return cell_state_;
}

void Cell::Reverse()
{
    if(cell_state_ == CELL_STATE::EMPTY)
        return;

    cell_state_ =
            cell_state_ == CELL_STATE::BLACK ? CELL_STATE::WHITE : CELL_STATE::BLACK;
    return;
}
