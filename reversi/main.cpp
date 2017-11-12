#include "mainwindow.h"
#include <QApplication>

#include "reversi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	w.reversi_ = new Reversi();

    return a.exec();
}
