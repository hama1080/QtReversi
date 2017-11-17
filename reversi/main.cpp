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

    return a.exec();
}
