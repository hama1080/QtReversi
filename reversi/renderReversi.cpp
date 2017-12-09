#include <QGraphicsScene>
#include "renderReversi.h"

RenderReversi::RenderReversi(Reversi * reversi, Vec2d render_pos, Vec2d render_board_size)
	:reversi_(reversi), render_pos_(render_pos), render_board_size_(render_board_size), kCellSize(40)
{
}

void RenderReversi::PaintStone(QGraphicsScene * scene, pair<unsigned int, unsigned int> pos, STONE_COLOR color, Vec2d render_offset)
{
	const unsigned int kEllipseDiameter = kCellSize * 0.75f;
	const unsigned int kOffset = (kCellSize - kEllipseDiameter) / 2;

	// modify render position. ex: (1,1)->(0,0)
	Vec2d render_pos(pos.first - 1, pos.second - 1);

	QRect render_rect(
		render_pos.first * kCellSize + kOffset + render_offset.first,
		render_pos.second * kCellSize + kOffset + render_offset.second,
		kEllipseDiameter, kEllipseDiameter);

	QPen pen;
	QBrush brush;
	switch (color)
	{
	case STONE_COLOR::BLACK:
		pen = QPen(Qt::black);
		brush = QBrush(Qt::black, Qt::SolidPattern);
		break;

	case STONE_COLOR::WHITE:
		pen = QPen(Qt::white);
		brush = QBrush(Qt::white, Qt::SolidPattern);
		break;

	default:
		// black
		pen = QPen(Qt::black);
		brush = QBrush(Qt::black, Qt::SolidPattern);
		break;
	}

	scene->addEllipse(render_rect, pen, brush);
}
