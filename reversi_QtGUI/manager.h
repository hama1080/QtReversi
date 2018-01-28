#pragma once
#include "mainwindow.h"

#include "settingDialog.h"
#include <vector>
#include <QObject>
#include <reversi.h>
#include <iostream>
class Manager : public QObject {
	Q_OBJECT

private:
public:
	vector<Reversi*> reversi_list_;
	MainWindow* w;
	Manager();

public slots:
	void nextPreprocessSlot(unsigned int next_index);
	void restartSlot();

};
