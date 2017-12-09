#pragma once
#include "reversi.h"

class RenderReversi
{
private:
	Reversi* reversi_;
	Vec2d render_pos_;
	Vec2d render_board_size_;

public:
	RenderReversi(Reversi* reversi, Vec2d render_pos, Vec2d render_board_size);

};