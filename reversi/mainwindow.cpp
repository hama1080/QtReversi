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

void MainWindow::paintEvent(QPaintEvent *event)
{
	scene_->addEllipse(QRect(20, 20, 80, 80), QPen(Qt::black), QBrush(Qt::black, Qt::SolidPattern));
	scene_->addEllipse(QRect(20, 120, 80, 80), QPen(Qt::white), QBrush(Qt::white, Qt::SolidPattern));
}
