#pragma once

#include <vector>
#include "common.h"

using namespace std;

class Board;
class Player;

class Reversi{
private:
	static bool waiting_human_input;

	Board* board_;
	vector<Player*> player_list_;
	Player* now_player_;

public:
	Reversi();
	~Reversi();

	void Initialize();
	void PreProcess();
	void PostProcess(Vec2d put_pos);

	Board* GetBoardPtr();
	static void SetWaitingFlag(bool flag);
};
