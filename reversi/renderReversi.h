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
	void PaintOutline(QGraphicsScene* scene, pair<unsigned int, unsigned int> board_size, Vec2d render_offset);
	void PaintBoard(QGraphicsScene* scene, Board* board, Vec2d render_offset);
	void PaintPlayerInfo(QGraphicsScene* scene, Player * player, Vec2d render_offset);
	void PaintGameResult(QGraphicsScene* scene, JudgeResult result, Vec2d render_offset);

public:
	RenderReversi(Reversi* reversi, Vec2d render_pos);
	void Rendering(QGraphicsScene* scene);

};