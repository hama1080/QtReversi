#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stone.h"

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
	void MousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	void PaintStone(pair<unsigned int, unsigned int> pos, STONE_COLOR color);
	void PaintOutline(pair<unsigned int, unsigned int> board_size);

	class QGraphicsScene* scene_;
	class QGraphicsView* view_;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
