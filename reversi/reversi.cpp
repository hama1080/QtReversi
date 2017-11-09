#include "reversi.h"
#include "board.h"
#include "human.h"

Reversi::Reversi()
{
	Initialize();
	return;
}

Reversi::~Reversi()
{

}

void Reversi::Initialize()
{
	board_ = new Board();
	player_list_.push_back(new Human(STONE_COLOR::BLACK));
	player_list_.push_back(new Human(STONE_COLOR::WHITE));
}

Board* Reversi::GetBoardPtr()
{
	return board_;
}