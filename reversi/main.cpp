#include "mainwindow.h"
#include <QApplication>

#include "reversi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	w.reversi_ = new Reversi();

	QObject::connect(&w, SIGNAL(leftClickSignal(pair<unsigned int, unsigned int>)),
		w.reversi_, SLOT(leftClickSlot(pair<unsigned int, unsigned int>)));
	QObject::connect(w.reversi_, SIGNAL(finishedPostProcessSignal()),
		&w, SLOT(finishedPostProcessSlot()));

	QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
		w.reversi_, SLOT(nextPreProcessSlot()));

	w.reversi_->PreProcess();

    return a.exec();
}
