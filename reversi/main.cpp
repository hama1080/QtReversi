#include "mainwindow.h"
#include <QApplication>

#include "reversi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	Reversi* reversi = new Reversi();
	w.AddReversi(reversi);

	QObject::connect(&w, SIGNAL(leftClickSignal(pair<unsigned int, unsigned int>)),
		reversi, SLOT(leftClickSlot(pair<unsigned int, unsigned int>)));
	QObject::connect(reversi, SIGNAL(finishedPostProcessSignal()),
		&w, SLOT(finishedPostProcessSlot()));
	QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
		reversi, SLOT(nextPreProcessSlot()));
	QObject::connect(reversi, SIGNAL(repaintSignal()),
		&w, SLOT(repaintSlot()));

	reversi->PreProcess();

    return a.exec();
}
