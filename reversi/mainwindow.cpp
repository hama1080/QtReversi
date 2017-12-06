#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>

#include "cell.h"
#include "board.h"
#include "reversi.h"
#include "player.h"

const unsigned int kWindowWidth = 700;
const unsigned int kWindowHeight = 700;
const unsigned int kCellSize = 40;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->resize(kWindowWidth, kWindowHeight);

	scene_ = new QGraphicsScene(QRect(0, 0, kWindowWidth, kWindowHeight));
	view_ = new QGraphicsView(scene_);
	view_->setBackgroundBrush(QBrush(Qt::gray));
	setCentralWidget(view_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddReversi(Reversi * reversi, Vec2d render_pos)
{
	RenderReversi render_reversi;
	render_reversi.reversi = reversi;
	render_reversi.render_pos = render_pos;
	render_reversi_list_.push_back(render_reversi);
	return;
}

void MainWindow::finishedTimerSlot()
{
	emit nextPreProcessSignal();
}

void MainWindow::repaintSlot()
{
	this->repaint();
}

void MainWindow::finishedPostProcessSlot()
{
	this->repaint();
	QTimer::singleShot(1, this, SLOT(finishedTimerSlot()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
//	top_left_ = Vec2d((kWindowWidth - kSceneWidth) / 2, (kWindowHeight - kSceneHeight) / 2);


	//if (event->button() == Qt::LeftButton) {
	//	int x = event->x() - top_left_.first;
	//	int y = event->y() - top_left_.second;
	//	Vec2d put_pos(x / kCellSize, y / kCellSize);

	//	// modify put position. ex: (0,0)->(1,1)
	//	put_pos.first += 1;
	//	put_pos.second += 1;

	//	if(Reversi::GetWaitingFlag())
	//		emit leftClickSignal(put_pos);
	//	this->repaint();
	//}
}

void MainWindow::PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color, Vec2d render_offset)
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

void MainWindow::PaintOutline(pair<unsigned int, unsigned int> board_size, Vec2d render_offset)
{
	const int kBoardWidth = kCellSize * board_size.first;
	const int kBoardHeight = kCellSize * board_size.second;

	QPen pen(Qt::black, 2);
	for (unsigned int x = 0; x <= board_size.first; x++)
	{
		QPoint start(x * kCellSize + render_offset.first, render_offset.second);
		QPoint end(x * kCellSize + render_offset.first, kBoardWidth + render_offset.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}

	for (unsigned int y = 0; y <= board_size.first; y++)
	{
		QPoint start(0+ render_offset.first, y * kCellSize + render_offset.second);
		QPoint end(kBoardHeight + render_offset.first, y * kCellSize + render_offset.second);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}
	return;
}

void MainWindow::PaintBoard(Board* board, Vec2d render_offset)
{
	Vec2d size = board->GetBoardSize();

	// render board
	const unsigned int kBoardWidth = kCellSize * 8;
	const unsigned int kBoardHeight = kCellSize * 8;
	scene_->addRect(render_offset.first, render_offset.second, kBoardWidth, kBoardHeight, QPen(Qt::black), QBrush(Qt::darkGreen));

	// render outline
	PaintOutline(size, render_offset);

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
					PaintStone(pos, STONE_COLOR::BLACK, render_offset);
					break;

				case STONE_COLOR::WHITE:
					PaintStone(pos, STONE_COLOR::WHITE, render_offset);
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

void MainWindow::PaintPlayerInfo(Player * player, Vec2d render_offset)
{
	STONE_COLOR color = player->GetPlayerColor();
	QString print_str;
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
	if(player->IsPass())
		print_str = "Pass";

	const unsigned int kBoardWidth = kCellSize * 8;
	const unsigned int kBoardHeight = kCellSize * 8;
	QFont font("Times", 20, QFont::Bold);
	QGraphicsTextItem* text = scene_->addText(print_str, font);
	text->setPos(render_offset.first, kBoardHeight + render_offset.second);
	text->deleteLater();

}


void MainWindow::paintEvent(QPaintEvent *event)
{
	for (auto render_reversi : render_reversi_list_)
	{
		PaintBoard(render_reversi.reversi->GetBoardPtr(), render_reversi.render_pos);
		PaintPlayerInfo(render_reversi.reversi->GetNowPlayer(), render_reversi.render_pos);
	}
	return;
}
