#pragma once

#include <vector>
using namespace std;

class Board;
class Player;

class Reversi{
private:
	Board* board_;
	vector<Player*> player_list_;
	Player* now_player_;

public:
	Reversi();
	~Reversi();

	void Initialize();
	void PreProcess();
	void PostProcess();

	Board* GetBoardPtr();
};