#pragma once
#include <string>
#include <map>
#include "reversi.h"
#include "stone.h"

using namespace std;
class QGraphicsScene;
class QGraphicsTextItem;
class QGraphicsEllipseItem;

class RenderReversi
{
private:
	unsigned int kCellSize;

	QGraphicsScene* scene_;
	Reversi* reversi_;
	Vec2d render_pos_;
	Vec2d render_board_size_;

	QGraphicsTextItem* player_info_;
	map<Vec2d, QGraphicsEllipseItem*> stone_map_;

	QGraphicsTextItem* AddText(string str, unsigned int pos_x, unsigned int pos_y);

	QGraphicsEllipseItem* AddStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color);
	void AddOutline(pair<unsigned int, unsigned int> board_size);
	void UpdateBoard(Board* board);
	void UpdatePlayerInfo(Player * player);
	void AddGameResult(JudgeResult result);
	void AddStoneCount(map<STONE_COLOR, unsigned int> stone_cnt_map);

public:
	RenderReversi(Mode mode, QGraphicsScene* scene, Reversi* reversi, Vec2d render_pos);
	void UpdateScene();
	Vec2d GetClickPos(int x, int y);
	void Initialize(Mode mode);

};