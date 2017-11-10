#include <QtCore/QCoreApplication>
#include <iostream>

#include <reversi.h>
#include <board.h>
#include <cell.h>

using namespace std;

void RenderBoard(Board* board)
{
	cout << "render board" << endl;
	Vec2d size = board->GetBoardSize();
	for (unsigned int y = 0; y != size.first + 2; y++)
	{
		for (unsigned int x = 0; x != size.second + 2; x++)
		{
			Vec2d pos(x, y);
			Cell cell = board->GetCell(pos);
			CELL_STATE state = cell.GetCellState();
			switch (state)
			{
			case CELL_STATE::EMPTY:
				cout << "□";
				break;
			case CELL_STATE::AROUND:
				cout << "　";
				break;
			case CELL_STATE::STONE:
				switch (cell.GetStoneColor())
				{
				case STONE_COLOR::BLACK:
					cout << "○";
					break;

				case STONE_COLOR::WHITE:
					cout << "●";
					break;

				default:
					break;
				}

				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Reversi reversi;
	RenderBoard(reversi.GetBoardPtr());
	return a.exec();
}

