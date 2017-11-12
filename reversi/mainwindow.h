#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stone.h"
#include "board.h"

using namespace std;

class Reversi;
class Board;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	Reversi* reversi_;
	explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	void PaintStone(Vec2d pos, STONE_COLOR color);
	void PaintOutline(Vec2d board_size);
	void PaintBoard(Board* board);

	class QGraphicsScene* scene_;
	class QGraphicsView* view_;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
