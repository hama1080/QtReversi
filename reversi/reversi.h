﻿#pragma once

#include <vector>
#include <qobject.h>
#include "common.h"

using namespace std;

enum class JudgeResult
{
	NotFinished,
	BlackWin,
	WhiteWin,
	Draw,
};

enum class PlayerType
{
	Human,
	Computer
};

class Board;
class Player;

class Reversi : public QObject{
	Q_OBJECT

private:
	static bool waiting_human_input;
	static unsigned int reversi_count;

	unsigned int reversi_num_;
	JudgeResult game_result_;

	Board* board_;
	vector<Player*> player_list_;
	Player* now_player_;

	JudgeResult JudgeGame();
	Mode mode_;

public:
	Reversi(Mode mode = Mode::Default, PlayerType player0 = PlayerType::Computer, PlayerType player1 = PlayerType::Computer);
	~Reversi();

	void Initialize(PlayerType player0, PlayerType player1);
	void PreProcess();
	void PostProcess(Vec2d put_pos);

	Mode GetMode();
	Board* GetBoardPtr();
	static void SetWaitingFlag(bool flag);
	static bool GetWaitingFlag();
	Player* GetNowPlayer();
	JudgeResult GetGameResult();

signals:
	void finishedPostProcessSignal(unsigned int);
	void repaintSignal(unsigned int);

public slots:
	void leftClickSlot(Vec2d click_pos);
};
