#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "renderReversi.h"

using namespace std;

class Reversi;
class Board;
class Player;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	const unsigned int kWindowWidth;
	const unsigned int kWindowHeight;

	class QGraphicsScene* scene_;
	class QGraphicsView* view_;

	Ui::MainWindow *ui;
	vector<RenderReversi> render_reversi_list_;

public:
	Vec2d top_left_;
	explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void AddReversi(Reversi* reversi, Vec2d render_pos = Vec2d(0, 0));

public slots:
	void finishedPostProcessSlot();
	void finishedTimerSlot();
	void repaintSlot();

signals:
	void leftClickSignal(Vec2d click_pos);
	void nextPreProcessSignal();

protected:
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

};

#endif // MAINWINDOW_H
