#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "renderReversi.h"
#include "board.h"
#include "cell.h"
#include "player.h"

RenderReversi::RenderReversi(QGraphicsScene* scene, Reversi * reversi, Vec2d render_pos)
	:scene_(scene), reversi_(reversi), render_pos_(render_pos), kCellSize(40)
{
	pair<unsigned int, unsigned int>  size = reversi->GetBoardPtr()->GetBoardSize();
	render_board_size_.first = kCellSize * size.first;		// board_width
	render_board_size_.second =  kCellSize * size.second;	//board_height

	// Render board
	scene_->addRect(render_pos_.first, render_pos_.second, render_board_size_.first, render_board_size_.second, QPen(Qt::black), QBrush(Qt::darkGreen));
	AddOutline(size, render_pos_);
}

void RenderReversi::Rendering()
{
	PaintBoard(reversi_->GetBoardPtr());
	PaintPlayerInfo(reversi_->GetNowPlayer(), render_pos_);
	JudgeResult result = reversi_->GetGameResult();
	if (result != JudgeResult::NotFinished)
	{
		PaintGameResult(result, render_pos_);
		PaintStoneCount(reversi_->GetBoardPtr()->GetStoneCnt(), render_pos_);
	}
}

QGraphicsTextItem*  RenderReversi::PaintText(string str, unsigned int pos_x, unsigned int pos_y)
{
	QFont font("Times", 20, QFont::Bold);
	QGraphicsTextItem* text = scene_->addText(QString::fromStdString(str), font);
	text->setPos(pos_x, pos_y);
	return text;
}

void RenderReversi::PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color, Vec2d render_offset)
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

	scene_->addEllipse(render_rect, pen, brush);
}

void RenderReversi::AddOutline(pair<unsigned int, unsigned int> board_size, Vec2d render_offset)
{
	QPen pen(Qt::black, 2);
	for (unsigned int x = 0; x <= board_size.first; x++)
	{
		QPoint start(x * kCellSize + render_offset.first, render_offset.second);
		QPoint end(x * kCellSize + render_offset.first, render_board_size_.first + render_offset.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}

	for (unsigned int y = 0; y <= board_size.first; y++)
	{
		QPoint start(0 + render_offset.first, y * kCellSize + render_offset.second);
		QPoint end(render_board_size_.second + render_offset.first, y * kCellSize + render_offset.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}
	return;
}

void RenderReversi::PaintBoard(Board * board)
{
	Vec2d size = board->GetBoardSize();

	// render stone
	for (unsigned int y = 0; y != size.first + 2; y++)
	{
		for (unsigned int x = 0; x != size.second + 2; x++)
		{
			Vec2d pos(x, y);
			Cell cell = board->GetCell(pos);
			CELL_STATE state = cell.GetCellState();
			switch (state)
			{
			case CELL_STATE::EMPTY:
			case CELL_STATE::AROUND:
				break;

			case CELL_STATE::STONE:
				switch (cell.GetStoneColor())
				{
				case STONE_COLOR::BLACK:
					PaintStone(pos, STONE_COLOR::BLACK, render_pos_);
					break;

				case STONE_COLOR::WHITE:
					PaintStone(pos, STONE_COLOR::WHITE, render_pos_);
					break;

				default:
					break;
				}

				break;
			default:
				break;
			}
		}
	}
}

void RenderReversi::PaintPlayerInfo(Player * player, Vec2d render_offset)
{
	STONE_COLOR color = player->GetPlayerColor();
	string print_str;
	switch (color)
	{
	case STONE_COLOR::BLACK:
		print_str = "Black";
		break;
	case STONE_COLOR::WHITE:
		print_str = "White";
		break;
	default:
		break;
	}
	if (player->IsPass())
		print_str = "Pass";

	QGraphicsTextItem* text = PaintText(print_str, render_offset.first, render_board_size_.second + render_offset.second);
	text->deleteLater();
}

void RenderReversi::PaintGameResult(JudgeResult result, Vec2d render_offset)
{
	string print_str;
	switch (result)
	{
	case JudgeResult::BlackWin:
		print_str = "Black Win!";
		break;
	case JudgeResult::WhiteWin:
		print_str = "White Win!";
		break;
	case JudgeResult::Draw:
		print_str = "Draw";
		break;
	default:
		break;
	}

	PaintText(print_str, render_offset.first, render_board_size_.second + render_offset.second);
}

void RenderReversi::PaintStoneCount(map<STONE_COLOR, unsigned int> stone_cnt_map, Vec2d render_offset)
{
	string print_str = "";
	for (auto stone_cnt : stone_cnt_map)
	{
		switch (stone_cnt.first)
		{
		case STONE_COLOR::BLACK:
			print_str += "Black: " + to_string(stone_cnt.second) + "\t";
			break;

		case STONE_COLOR::WHITE:
			print_str += "White: " + to_string(stone_cnt.second) + "\t";
			break;

		default:
			print_str += "Other: " + to_string(stone_cnt.second) + "\t";
			break;
		}
	}
	PaintText(print_str, render_offset.first, render_board_size_.second + render_offset.second + 25);

	return;
}
