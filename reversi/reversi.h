#pragma once

#include <vector>
using namespace std;

class Board;
class Player;

class Reversi{
private:
	Board* board_;
	vector<Player*> player_list_;

public:
	Reversi();
	~Reversi();

	void Initialize();
	Board* GetBoardPtr();
};