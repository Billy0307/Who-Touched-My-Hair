#ifndef TOWER_H
#define TOWER_H

#include "monster.h"

// �򵥰�����
class Tower
{
public:
    Tower(double x, double y, double w, double h, double wr, double hr, double bw, double bh, double bwr, double bhr, const char * tower, const char * bullet) {
        arrayLocation[0] = x;
        arrayLocation[1] = y;
        doubleWidth = w;
        doubleHeight =h;
        doubleWidthRef = wr;
        doubleHeightRef = hr;

        doubleBullet = 1.1;
        doubleBulWidth = bw;
        doubleBulHeight = bh;
        doubleBulWidthRef = bwr;
        doubleBulHeightRef = bhr;

        intMonsterChosen = -1;
        strTower = tower;
        strBullet = bullet;
    }
    // ģ�����ҹ�
    int search(std::vector<Monster *> vecMonster) {
        double min_dist = 9999;
        double dist = 0;
        intMonsterChosen = -1;
        for (int i = 0; i < vecMonster.size(); i++) {
            dist = (arrayLocation[0] - vecMonster[i]->xMonPost)*(arrayLocation[0] - vecMonster[i]->xMonPost) +
                   (arrayLocation[1] - vecMonster[i]->yMonPost)*(arrayLocation[1] - vecMonster[i]->yMonPost);
            if (dist < min_dist && dist < 5) {
                min_dist = dist;
                intMonsterChosen = i;
            }
        }
        return intMonsterChosen;
    }
    // ģ��������
    void attack(Monster * monster) {
        monster->intHitPoint -= 1;
    }
    int arrayLocation[2];
    // ��Ҫ�Ĳ���
    double doubleWidth, doubleHeight;        // ���Ŀ�/�ߣ�������ͼ����������仯
    double doubleWidthRef, doubleHeightRef;  // ����������
    double doubleBulWidth, doubleBulHeight;  // �ӵ��Ŀ��
    double doubleBulWidthRef, doubleBulHeightRef; // ����������
    double doubleBullet;         // �����ӵ���ͼ��ֻ���ʼ��Ϊ1.1
    int intMonsterChosen;        // ���������������е���ţ��޶���ʱ��Ϊ-1
    const char * strTower;       // ͼƬ·��(����
    const char * strBullet;      // ͼƬ·��(�ӵ�)
};

#endif // TOWER_H
