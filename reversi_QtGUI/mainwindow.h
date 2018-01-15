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
class Dialog;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	const unsigned int kWindowWidth;
	const unsigned int kWindowHeight;
	unsigned int next_index_;

	class QGraphicsScene* scene_;
	class QGraphicsView* view_;

	Ui::MainWindow *ui;
	Ui::Dialog *ui_setting;

public:
	vector<RenderReversi> render_reversi_list_;
	Vec2d top_left_;
	explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void AddReversi(Reversi* reversi, Vec2d render_pos = Vec2d(0, 0));

public slots:
	void finishedPostProcessSlot(unsigned int reversi_num);
	void finishedTimerSlot();
	void repaintSlot(unsigned int reversi_num);

signals:
	void leftClickSignal(pair<unsigned int, unsigned int> click_pos);
	void nextPreProcessSignal(unsigned int next_index);
    void restartSignal();

protected:
	void mousePressEvent(QMouseEvent *event);

protected slots:
    void Restart();
};

#endif // MAINWINDOW_H
