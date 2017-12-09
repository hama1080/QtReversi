#pragma once
#include "reversi.h"
#include "stone.h"

class QGraphicsScene;

class RenderReversi
{
private:
	const unsigned int kCellSize;

	Reversi* reversi_;
	Vec2d render_pos_;
	Vec2d render_board_size_;

	void PaintStone(QGraphicsScene* scene, pair<unsigned int, unsigned int> pos, STONE_COLOR color, Vec2d render_offset);

public:
	RenderReversi(Reversi* reversi, Vec2d render_pos, Vec2d render_board_size);

};