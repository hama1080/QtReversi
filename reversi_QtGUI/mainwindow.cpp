#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_setting.h"
#include <qevent.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	:kWindowWidth(900), kWindowHeight(950), QMainWindow(parent), ui(new Ui::MainWindow), next_index_(0)
{
    ui->setupUi(this);
	this->resize(kWindowWidth, kWindowHeight);

	scene_ = new QGraphicsScene(QRect(0, 0, kWindowWidth-50, kWindowHeight-50));
	view_ = new QGraphicsView(scene_);
	view_->setBackgroundBrush(QBrush(Qt::gray));
	setCentralWidget(view_);

	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(finishedTimerSlot()));
	timer->start(0);

    connect(ui->actionRestart, SIGNAL(triggered()), this, SLOT(Restart()));

	QDialog* setting_dialog = new QDialog(this);
	setting_dialog->setModal(true);
	ui_setting = new Ui::Dialog();
	ui_setting->setupUi(setting_dialog);
	setting_dialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddReversi(Reversi * reversi, Vec2d render_pos)
{
	RenderReversi render_reversi(scene_, reversi, render_pos);
	render_reversi_list_.push_back(render_reversi);
	return;
}

void MainWindow::finishedTimerSlot()
{
	emit nextPreProcessSignal(next_index_);
}

void MainWindow::repaintSlot(unsigned int reversi_num)
{
	render_reversi_list_[reversi_num].UpdateScene();

	this->repaint();
}

void MainWindow::finishedPostProcessSlot(unsigned int reversi_num)
{
	render_reversi_list_[reversi_num].UpdateScene();

	this->repaint();

	next_index_ = reversi_num + 1;
	if (next_index_ == render_reversi_list_.size())
		next_index_ = 0;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		int x = event->x();
		int y = event->y();
		Vec2d put_pos = render_reversi_list_[0].GetClickPos(x, y);

		if(Reversi::GetWaitingFlag())
			emit leftClickSignal(put_pos);
		this->repaint();
	}
}

void MainWindow::Restart()
{
    emit restartSignal();
}
