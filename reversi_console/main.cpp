#include <QtCore/QCoreApplication>
#include <iostream>

#include <reversi.h>
#include <board.h>

using namespace std;

void RenderBoard(Board* board)
{
	cout << "render board" << endl;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	Reversi reversi;
	RenderBoard(reversi.GetBoardPtr());
	return a.exec();
}

