#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qevent.h>
#include <qpainter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(Qt::black);
	painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
	painter.drawEllipse(20, 20, 80, 80);

	painter.setPen(Qt::white);
	painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
	painter.drawEllipse(20, 120, 80, 80);
}
