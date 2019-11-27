#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <vector>
#include "tower.h"
#include "monster.h"

// ��ͼ����
namespace Ui {
    class myMainWindow;
}

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = 0);
    ~myMainWindow();
    void paintEvent(QPaintEvent *);
    void paintTower(QPainter *);
    void paintMonster(QPainter *);
private slots:
    void updateMap();
private:
    Ui::myMainWindow *ui;
    std::vector<Tower *> vecTower;     // ����������������Ϣ
    std::vector<Monster *> vecMonster; // �������������ڴ�Ź�����Ϣ
    double mapWidth, mapHeight;    // ��ͼ��/��
    double wRatio, hRatio;         // ��ͼ����
};

#endif // MYMAINWINDOW_H
