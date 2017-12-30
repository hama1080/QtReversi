#pragma once
#include <vector>
#include <QObject>
#include "reversi.h"

class Manager : public QObject {
	Q_OBJECT

private:
public:
	vector<Reversi*> reversi_list_;

public slots:
	void nextPreprocessSlot(unsigned int next_index)
	{
		if(reversi_list_.size() == 1)
			reversi_list_[next_index]->PreProcess();

		// In order to suppress the twice execution of pre-process, keep the index pre-processed before.
		static int before_preprocess_index = -1;
		if (before_preprocess_index != next_index)
		{
			before_preprocess_index = next_index;
			reversi_list_[next_index]->PreProcess();
		}
	}

};