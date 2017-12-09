#pragma once
#include "reversi.h"
#include "stone.h"

class QGraphicsScene;

class RenderReversi
{
private:
	const unsigned int kCellSize;

	QGraphicsScene* scene_;
	Reversi* reversi_;
	Vec2d render_pos_;
	Vec2d render_board_size_;

	void PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color, Vec2d render_offset);
	void PaintOutline(pair<unsigned int, unsigned int> board_size, Vec2d render_offset);
	void PaintBoard(Board* board, Vec2d render_offset);
	void PaintPlayerInfo(Player * player, Vec2d render_offset);
	void PaintGameResult(JudgeResult result, Vec2d render_offset);

public:
	RenderReversi(QGraphicsScene* scene, Reversi* reversi, Vec2d render_pos);
	void Rendering();

};