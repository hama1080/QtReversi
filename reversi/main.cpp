#include "mainwindow.h"
#include <QApplication>

#include "reversi.h"
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	Manager manager;
	for(unsigned int i = 0; i != 4; i++)
	{
		for(unsigned int j =0; j != 4; j++)
		{
			Reversi* reversi = new Reversi();
			Vec2d render_pos(i * 200, j * 200);
			w.AddReversi(reversi, render_pos);
			manager.reversi_list_.push_back(reversi);
		}
	}

	for (unsigned int i = 0; i != manager.reversi_list_.size(); i++)
	{
		QObject::connect(manager.reversi_list_[i], SIGNAL(finishedPostProcessSignal(unsigned int)),
			&w, SLOT(finishedPostProcessSlot(unsigned int)));

		QObject::connect(&w, SIGNAL(nextPreProcessSignal(unsigned int)),
			&manager, SLOT(nextPreprocessSlot(unsigned int)));

		QObject::connect(manager.reversi_list_[i], SIGNAL(repaintSignal(unsigned int)),
			&w, SLOT(repaintSlot(unsigned int)));
	}
//	QObject::connect(&w, SIGNAL(leftClickSignal(pair<unsigned int, unsigned int>)),
//		reversi, SLOT(leftClickSlot(pair<unsigned int, unsigned int>)));

	manager.reversi_list_[0]->PreProcess();

    return a.exec();
}
