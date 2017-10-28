#include "cell.h"

Cell::Cell()
{
    cell_state_ = CELL_STATE::EMPTY;
    stone_ = nullptr;
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
