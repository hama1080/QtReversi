#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	scene_ = new QGraphicsScene(QRect(0, 0, 800, 800));
	scene_->addRect(0, 0, 600, 600, QPen(Qt::black), QBrush(Qt::darkGreen));   //  [2]
	view_ = new QGraphicsView(scene_);
	view_->setBackgroundBrush(QBrush(Qt::gray));
	setCentralWidget(view_);

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		qDebug("MousePress x=%d,y=%d", event->x(), event->y());
	}
}

void MainWindow::PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color)
{
	const unsigned int kOffset = 20;
	const unsigned int kEllipseGap = 60;
	const unsigned int kEllipseDiameter = 50;
	QRect renderPos(kOffset + pos.first * kEllipseGap, kOffset + pos.second * kEllipseGap, kEllipseDiameter, kEllipseDiameter);

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


void MainWindow::paintEvent(QPaintEvent *event)
{
	PaintStone(pair<unsigned int, unsigned int>(1, 1), STONE_COLOR::BLACK);
	PaintStone(pair<unsigned int, unsigned int>(2, 1), STONE_COLOR::WHITE);
	PaintOutline(pair<unsigned int, unsigned int>(8, 8));
}
