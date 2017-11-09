#include "stone.h"

Stone::Stone(STONE_COLOR color)
{
    this->color_ = color;
    return;
}

STONE_COLOR Stone::GetStoneColor()
{
    return color_;
}

void Stone::SetStoneColor(STONE_COLOR color)
{
    this->color_ = color;
    return;
}

void Stone::Reverse()
{
    color_ = color_ == STONE_COLOR::BLACK ? STONE_COLOR::WHITE : STONE_COLOR::BLACK;
}
