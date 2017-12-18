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
	for(unsigned int i = 0; i != 2; i++)
	{
		Reversi* reversi = new Reversi();
		Vec2d render_pos(i * 350, 0);
		w.AddReversi(reversi, render_pos);
		manager.reversi_list_.push_back(reversi);
	}

	for (unsigned int i = 0; i != manager.reversi_list_.size(); i++)
	{
		QObject::connect(manager.reversi_list_[i], SIGNAL(finishedPostProcessSignal(unsigned int)),
			&w, SLOT(finishedPostProcessSlot(unsigned int)));

		if(i == manager.reversi_list_.size() - 1){
			QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
				manager.reversi_list_[0], SLOT(nextPreProcessSlot()));
		}
		else{
			QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
				manager.reversi_list_[i+1], SLOT(nextPreProcessSlot()));
		}
		QObject::connect(manager.reversi_list_[i], SIGNAL(repaintSignal(unsigned int)),
			&w, SLOT(repaintSlot(unsigned int)));
	}
//	QObject::connect(&w, SIGNAL(leftClickSignal(pair<unsigned int, unsigned int>)),
//		reversi, SLOT(leftClickSlot(pair<unsigned int, unsigned int>)));

	manager.reversi_list_[0]->PreProcess();

    return a.exec();
}
