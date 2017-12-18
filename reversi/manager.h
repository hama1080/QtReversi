#pragma once
#include <vector>
#include <QObject>
#include "reversi.h"
#include <iostream>
using namespace std;

class Manager : public QObject {
	Q_OBJECT

private:
public:
	vector<Reversi*> reversi_list_;

public slots:
	void nextPreprocessSlot(unsigned int next_index)
	{
		reversi_list_[next_index]->PreProcess();
	}

};