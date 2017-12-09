#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
	:kWindowWidth(700), kWindowHeight(700), QMainWindow(parent), ui(new Ui::MainWindow)
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
	RenderReversi render_reversi(reversi, render_pos);
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


void MainWindow::paintEvent(QPaintEvent *event)
{
	for (auto render_reversi : render_reversi_list_)
	{
		render_reversi.Rendering(scene_);
	}
	return;
}
