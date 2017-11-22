#pragma once

#include <vector>
#include <qobject.h>
#include "common.h"

using namespace std;

class Board;
class Player;

class Reversi : public QObject{
	Q_OBJECT

private:
	static bool waiting_human_input;

	Board* board_;
	vector<Player*> player_list_;
	Player* now_player_;

	bool JudgeGameEnd();

public:
	Reversi();
	~Reversi();

	void Initialize();
	void PreProcess();
	void PostProcess(Vec2d put_pos);

	Board* GetBoardPtr();
	static void SetWaitingFlag(bool flag);
	static bool GetWaitingFlag();

public slots:
	void leftClickSlot(Vec2d click_pos);

};
