#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "cell.h"
#include "board.h"
#include "reversi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	scene_ = new QGraphicsScene(QRect(0, 0, 640, 640));
	scene_->addRect(0, 0, 640, 640, QPen(Qt::black), QBrush(Qt::darkGreen));   //  [2]
	view_ = new QGraphicsView(scene_);
	view_->setBackgroundBrush(QBrush(Qt::gray));
	setCentralWidget(view_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		qDebug("MousePress x=%d,y=%d", event->x(), event->y());
	}
}

void MainWindow::PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color)
{
	const unsigned int kCellSize = 80;
	const unsigned int kEllipseDiameter = 60;
	const unsigned int kOffset = (kCellSize - kEllipseDiameter) / 2;
	QRect renderPos(
		(pos.first - 1) * kCellSize + kOffset,
		(pos.second - 1) * kCellSize + kOffset,
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

	scene_->addEllipse(renderPos, pen, brush);
}

void MainWindow::PaintOutline(pair<unsigned int, unsigned int> board_size)
{
	const int kCellSize = 80;
	const int kBoardLength = kCellSize * board_size.first;
	const int kBoardWidth = kCellSize * board_size.second;

	QPen pen(Qt::black, 2);
	for (unsigned int x = 0; x <= board_size.first; x++)
	{
		QPoint start(x * kCellSize, 0);
		QPoint end(x * kCellSize, kBoardLength);
		QLine line(start, end);
		scene_->addLine(line, pen);
	}

	for (unsigned int y = 0; y <= board_size.first; y++)
	{
		QPoint start(0, y * kCellSize);
		QPoint end(kBoardWidth, y * kCellSize);
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
