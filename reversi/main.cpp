#include "mainwindow.h"
#include <QApplication>

#include "reversi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	vector<Reversi*> reversi_list;
	for(unsigned int i = 0; i != 1; i++)
	{
		Reversi* reversi = new Reversi();
		Vec2d render_pos(i * 350, 0);
		w.AddReversi(reversi, render_pos);
		reversi_list.push_back(reversi);
	}

	for (unsigned int i = 0; i != reversi_list.size(); i++)
	{
		QObject::connect(reversi_list[i], SIGNAL(finishedPostProcessSignal()),
			&w, SLOT(finishedPostProcessSlot()));

		if(i == reversi_list.size() - 1){
			QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
				reversi_list[0], SLOT(nextPreProcessSlot()));
		}
		else{
			QObject::connect(&w, SIGNAL(nextPreProcessSignal()),
			reversi_list[i+1], SLOT(nextPreProcessSlot()));
		}
		QObject::connect(reversi_list[i], SIGNAL(repaintSignal()),
			&w, SLOT(repaintSlot()));
	}
//	QObject::connect(&w, SIGNAL(leftClickSignal(pair<unsigned int, unsigned int>)),
//		reversi, SLOT(leftClickSlot(pair<unsigned int, unsigned int>)));

	reversi_list[0]->PreProcess();

    return a.exec();
}
