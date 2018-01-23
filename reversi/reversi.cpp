﻿#include "reversi.h"
#include "board.h"
#include "human.h"
#include "computer.h"
#include "common.h"
#include <iostream>
#include <algorithm>

using namespace std;

const vector<Vec2d> kDirectionList{ UpperLeft, Upper, UpperRight, CenterLeft, CenterRight, LowerLeft, Lower, LowerRight};
bool Reversi::waiting_human_input = false;
unsigned int Reversi::reversi_count = 0;

Reversi::Reversi(Mode mode, PlayerType player0, PlayerType player1)
{
	mode_ = mode;
	Initialize(mode_, player0, player1);
	reversi_num_ = reversi_count;
	reversi_count++;
	return;
}

Reversi::~Reversi()
{

}

JudgeResult Reversi::JudgeGame()
{
	map<STONE_COLOR, unsigned int> stone_cnt = board_->GetStoneCnt();

	STONE_COLOR max_color = STONE_COLOR::BLACK;
	unsigned int max_cnt = 0;
	for (auto i : stone_cnt) {
		if (i.second >= max_cnt)
		{
			max_color = i.first;
			max_cnt = i.second;
		}
	}

	unsigned int change_cnt = 0;
	for (auto i : stone_cnt) {
		if (i.second == max_cnt)
			change_cnt++;
	}
	if (change_cnt == stone_cnt.size())
		return JudgeResult::Draw;
	switch (max_color)
	{
	case STONE_COLOR::BLACK:
		return JudgeResult::BlackWin;

	case STONE_COLOR::WHITE:
		return JudgeResult::WhiteWin;
	}
}

void Reversi::Initialize(Mode mode, PlayerType player0, PlayerType player1)
{
	if (mode == Mode::LargeScale)
		board_ = new Board(25, 25);
	else
		board_ = new Board();	// default, multi

	player_list_.clear();
	if (player0 == PlayerType::Human)
		player_list_.push_back(new Human(STONE_COLOR::BLACK));
	else
		player_list_.push_back(new Computer(STONE_COLOR::BLACK));

	if (player1 == PlayerType::Human)
		player_list_.push_back(new Human(STONE_COLOR::WHITE));
	else
		player_list_.push_back(new Computer(STONE_COLOR::WHITE));


	// create player loop: black->white->black->white->...
	for (vector<Player*>::iterator i = player_list_.begin(); i != player_list_.end() - 1; i++)
		(*i)->SetNextPlayer(*(i + 1));
	(*(player_list_.end() - 1))->SetNextPlayer(*player_list_.begin());

	now_player_ = *player_list_.begin();
	game_result_ = JudgeResult::NotFinished;
}

void Reversi::leftClickSlot(Vec2d click_pos)
{
	PostProcess(click_pos);
	return;
}

//call before player input
void Reversi::PreProcess()
{
	if (game_result_ != JudgeResult::NotFinished) {	// game is already finished.
		emit finishedPostProcessSignal(reversi_num_);
		return;
	}

	PreProcessState state = board_->PreProcess(now_player_->GetPlayerColor());

	if(state == PreProcessState::Pass)
	{
		// skip the post process and change the player
		now_player_->SetPassFlag(true);
		now_player_ = now_player_->GetNextPlayer();

		// pass loop->all player pass->game end
		if (now_player_->IsPass())
		{
			game_result_ = JudgeGame();
			now_player_ = nullptr;
			emit repaintSignal(reversi_num_);
			return;
		}

		emit finishedPostProcessSignal(reversi_num_);
		return;
	}

	now_player_->SetPassFlag(false);

	Vec2d put_pos;
	bool wait_input = now_player_->AskPutStonePosition(put_pos, board_);	// Ask player about put position

	if (wait_input)
		return;
	else
		PostProcess(put_pos);
}

// call after player input
void Reversi::PostProcess(Vec2d put_pos)
{
	// put & reverse
	bool success = board_->PostProcess(now_player_->GetPlayerColor(), put_pos);
	if(success){
		Vec2d board_size = board_->GetBoardSize();
		map<STONE_COLOR, unsigned int> stone_cnt_map = board_->GetStoneCnt();
		
		unsigned int total_stone = 0;
		for (auto stone_cnt : stone_cnt_map)
			total_stone += stone_cnt.second;

		if (total_stone == board_size.first * board_size.second){
			game_result_ = JudgeGame();
			now_player_ = nullptr;
			emit finishedPostProcessSignal(reversi_num_);
			emit repaintSignal(reversi_num_);
			return;
		}
		else {
			now_player_ = now_player_->GetNextPlayer();
		}
	}
	emit finishedPostProcessSignal(reversi_num_);	// call PreProcess after this signal is emitted
	return;
}

Mode Reversi::GetMode()
{
	return mode_;
}

Board* Reversi::GetBoardPtr()
{
	return board_;
}

void Reversi::SetWaitingFlag(bool flag)
{
	waiting_human_input = flag;
	return;
}

bool Reversi::GetWaitingFlag()
{
	return waiting_human_input;
}

Player* Reversi::GetNowPlayer()
{
	return now_player_;
}

JudgeResult Reversi::GetGameResult()
{
	return game_result_;
}

