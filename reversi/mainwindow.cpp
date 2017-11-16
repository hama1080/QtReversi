#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "cell.h"
#include "board.h"
#include "reversi.h"

const unsigned int kWindowWidth = 700;
const unsigned int kWindowHeight = 700;
const unsigned int kCellSize = 80;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	// should change depending on board size
	const unsigned int kSceneWidth = kCellSize * 8;
	const unsigned int kSceneHeight = kCellSize * 8;

    ui->setupUi(this);
	this->resize(kWindowWidth, kWindowHeight);


	scene_ = new QGraphicsScene(QRect(0, 0, kSceneWidth, kSceneHeight));
	scene_->addRect(0, 0, kSceneWidth, kSceneHeight, QPen(Qt::black), QBrush(Qt::darkGreen));   //  [2]
	view_ = new QGraphicsView(scene_);
	view_->setBackgroundBrush(QBrush(Qt::gray));
	setCentralWidget(view_);

	top_left_ = Vec2d((kWindowWidth - kSceneWidth) / 2, (kWindowHeight - kSceneHeight) / 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	static bool tmpflag = false;

	if (event->button() == Qt::LeftButton) {
		int x = event->x() - top_left_.first;
		int y = event->y() - top_left_.second;
		Vec2d put_pos(x / kCellSize, y / kCellSize);

		// modify put position. ex: (0,0)->(1,1)
		put_pos.first += 1;
		put_pos.second += 1;

		/////  tmp
		tmpflag ? reversi_->GetBoardPtr()->PutStone(put_pos, STONE_COLOR::BLACK) : reversi_->GetBoardPtr()->PutStone(put_pos, STONE_COLOR::WHITE);
		tmpflag = !tmpflag;
		this->repaint();
		/////

		if(Reversi::GetWaitingFlag())
			emit leftClickSignal(put_pos);
	}
}

void MainWindow::PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color)
{
	const unsigned int kEllipseDiameter = 60;
	const unsigned int kOffset = (kCellSize - kEllipseDiameter) / 2;

	// modify render position. ex: (1,1)->(0,0)
	Vec2d render_pos(pos.first - 1, pos.second - 1);

	QRect render_rect(
		render_pos.first * kCellSize + kOffset,
		render_pos.second * kCellSize + kOffset,
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

void MainWindow::PaintOutline(pair<unsigned int, unsigned int> board_size)
{
	const int kBoardWidth = kCellSize * board_size.first;
	const int kBoardHeight = kCellSize * board_size.second;

	QPen pen(Qt::black, 2);
	for (unsigned int x = 0; x <= board_size.first; x++)
	{
		QPoint start(x * kCellSize, 0);
		QPoint end(x * kCellSize, kBoardWidth);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}

	for (unsigned int y = 0; y <= board_size.first; y++)
	{
		QPoint start(0, y * kCellSize);
		QPoint end(kBoardHeight, y * kCellSize);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}
	return;
}

void MainWindow::PaintBoard(Board* board)
{
	Vec2d size = board->GetBoardSize();

	// render outline
	PaintOutline(size);

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
					PaintStone(pos, STONE_COLOR::BLACK);
					break;

				case STONE_COLOR::WHITE:
					PaintStone(pos, STONE_COLOR::WHITE);
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



void MainWindow::paintEvent(QPaintEvent *event)
{
	PaintBoard(reversi_->GetBoardPtr());
}
