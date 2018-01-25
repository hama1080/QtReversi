#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include "renderReversi.h"
#include "board.h"
#include "cell.h"
#include "player.h"
#include "common.h"

RenderReversi::RenderReversi(QGraphicsScene* scene, Reversi * reversi, Vec2d render_pos)
	:scene_(scene), reversi_(reversi), render_pos_(render_pos)
{
	mode_ = reversi->GetMode();
	switch (mode_)
	{
	case Mode::Default:
	case Mode::LargeScale:
		kCellSize = 30;
		break;

	case Mode::Multi:
		kCellSize = 20;
		break;

	default:
		// unexpected mode
		break;
	}
	pair<unsigned int, unsigned int>  size = reversi->GetBoardPtr()->GetBoardSize();
	render_board_size_.first = kCellSize * size.first;		// board_width
	render_board_size_.second =  kCellSize * size.second;	//board_height

	// Render board
	scene_->addRect(render_pos_.first, render_pos_.second, render_board_size_.first, render_board_size_.second, QPen(Qt::black), QBrush(Qt::darkGreen));
	AddOutline(size);
	player_info_ = nullptr;

	UpdateScene();
}

void RenderReversi::UpdateScene()
{
	UpdateBoard(reversi_->GetBoardPtr());
	UpdatePlayerInfo(reversi_->GetNowPlayer());

	JudgeResult result = reversi_->GetGameResult();
	if (result != JudgeResult::NotFinished)
	{
		AddGameResult(result);
		AddStoneCount(reversi_->GetBoardPtr()->GetStoneCnt());
	}
}

Vec2d RenderReversi::GetClickPos(int x, int y)
{
	unsigned int put_pos_x = (x - render_pos_.first) / kCellSize;
	unsigned int put_pos_y = (y - render_pos_.second) / kCellSize;
	return Vec2d(put_pos_x, put_pos_y);
}

void RenderReversi::ChangeMode(Mode mode)
{
	mode_ = mode;
	return;
}

QGraphicsTextItem*  RenderReversi::AddText(string str, unsigned int pos_x, unsigned int pos_y)
{
	QFont font("Times", kCellSize / 2, QFont::Bold);
	QGraphicsTextItem* text = scene_->addText(QString::fromStdString(str), font);
	text->setPos(pos_x, pos_y);
	return text;
}

QGraphicsEllipseItem* RenderReversi::AddStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color)
{
	const unsigned int kEllipseDiameter = kCellSize * 0.75f;
	const unsigned int kOffset = (kCellSize - kEllipseDiameter) / 2;

	// modify render position. ex: (1,1)->(0,0)
	Vec2d render_pos(pos.first - 1, pos.second - 1);

	QRect render_rect(
		render_pos.first * kCellSize + kOffset + render_pos_.first,
		render_pos.second * kCellSize + kOffset + render_pos_.second,
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

	return scene_->addEllipse(render_rect, pen, brush);
}

void RenderReversi::AddOutline(pair<unsigned int, unsigned int> board_size)
{
	QPen pen(Qt::black, 2);
	for (unsigned int x = 0; x <= board_size.first; x++)
	{
		QPoint start(x * kCellSize + render_pos_.first, render_pos_.second);
		QPoint end(x * kCellSize + render_pos_.first, render_board_size_.first + render_pos_.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}

	for (unsigned int y = 0; y <= board_size.first; y++)
	{
		QPoint start(0 + render_pos_.first, y * kCellSize + render_pos_.second);
		QPoint end(render_board_size_.second + render_pos_.first, y * kCellSize + render_pos_.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}
	return;
}

void RenderReversi::UpdateBoard(Board * board)
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
					if (stone_map_.count(pos) == 0){
						stone_map_[pos] = AddStone(pos, STONE_COLOR::BLACK);
					}else{
						stone_map_[pos]->setPen(QPen(Qt::black));
						stone_map_[pos]->setBrush(QBrush(Qt::black, Qt::SolidPattern));
					}
					break;

				case STONE_COLOR::WHITE:
					if (stone_map_.count(pos) == 0){
						stone_map_[pos] = AddStone(pos, STONE_COLOR::WHITE);
					}else{
						stone_map_[pos]->setPen(QPen(Qt::white));
						stone_map_[pos]->setBrush(QBrush(Qt::white, Qt::SolidPattern));
					}
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

void RenderReversi::UpdatePlayerInfo(Player * player)
{
	if (player == nullptr) {
		player_info_->setPlainText("");
		return;
	}
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

	if (player_info_ == nullptr)
		player_info_ = AddText(print_str, render_pos_.first, render_board_size_.second + render_pos_.second);
	else
		player_info_->setPlainText(QString::fromStdString(print_str));
}

void RenderReversi::AddGameResult(JudgeResult result)
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

	AddText(print_str, render_pos_.first, render_board_size_.second + render_pos_.second);
}

void RenderReversi::AddStoneCount(map<STONE_COLOR, unsigned int> stone_cnt_map)
{
	string print_str = "";
	for (auto stone_cnt : stone_cnt_map)
	{
		switch (stone_cnt.first)
		{
		case STONE_COLOR::BLACK:
			print_str += "Black: " + to_string(stone_cnt.second) + "  ";
			break;

		case STONE_COLOR::WHITE:
			print_str += "White: " + to_string(stone_cnt.second) + "  ";
			break;

		default:
			print_str += "Other: " + to_string(stone_cnt.second) + "  ";
			break;
		}
	}
	AddText(print_str, render_pos_.first, render_board_size_.second + render_pos_.second + kCellSize / 2);

	return;
}

void RenderReversi::Initialize()
{
	switch (mode_)
	{
	case Mode::Default:
	case Mode::LargeScale:
		kCellSize = 30;
		break;

	case Mode::Multi:
		kCellSize = 20;
		break;

	default:
		// unexpected mode
		break;
	}
	scene_->clear();
	stone_map_.clear();

	// Render board
	pair<unsigned int, unsigned int>  size = reversi_->GetBoardPtr()->GetBoardSize();
	render_board_size_.first = kCellSize * size.first;
	render_board_size_.second = kCellSize * size.second;
	scene_->addRect(render_pos_.first, render_pos_.second, render_board_size_.first, render_board_size_.second, QPen(Qt::black), QBrush(Qt::darkGreen));
	AddOutline(size);
	player_info_ = nullptr;

	UpdateScene();
}

