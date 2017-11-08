#include <QtCore/QCoreApplication>
#include <iostream>

#include <reversi.h>
#include <board.h>
#include <cell.h>

using namespace std;

void RenderBoard(Board* board)
{
	cout << "render board" << endl;
	Vector2d size = board->GetBoardSize();
	for (unsigned int x = 1; x != size.GetX() + 1; x++)
	{
		for (unsigned int y = 1; y != size.GetY() + 1; y++)
		{
			Vector2d pos(x, y);
			Cell cell = board->GetCell(pos);
			CELL_STATE state = cell.GetCellState();
			switch (state)
			{
			case CELL_STATE::EMPTY:
				cout << "E";
				break;
			case CELL_STATE::AROUND:
				cout << "A";
				break;
			case CELL_STATE::STONE:
				cout << "S";
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

