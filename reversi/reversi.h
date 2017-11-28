#pragma once

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

class Board;
class Player;

class Reversi : public QObject{
	Q_OBJECT

private:
	static bool waiting_human_input;

	Board* board_;
	vector<Player*> player_list_;
	Player* now_player_;

	JudgeResult JudgeGame(unsigned int black_cnt, unsigned int white_cnt);
	JudgeResult JudgeGameFinished();

public:
	Reversi();
	~Reversi();

	void Initialize();
	void PreProcess();
	void PostProcess(Vec2d put_pos);

	Board* GetBoardPtr();
	static void SetWaitingFlag(bool flag);
	static bool GetWaitingFlag();

signals:
	void finishedPostProcessSignal();
public slots:
	void leftClickSlot(Vec2d click_pos);
	void finishedPostProcessSlot();
};
