//#pragma once
#ifndef TOWER_H
#define TOWER_H
#include <iostream>
using namespace std;

class Map;
class Monster;

class Tower
{
public:
	Tower();

	int arrayLocation[2];//λ�����꣬[0]Ϊx��[1]Ϊy

	int intAttackInterval;//�����������λ����

	int intAttack;//������

	int intCost;//�۸�

	int arraySize[2];//���Ĵ�С�����˿�[0]Ϊˮƽ���ȣ�[1]Ϊ��ֱ����

	double doubleAttackRadius;//������Χ��Ĭ��ΪԲ�Σ��ñ�������Բ�İ뾶

	int intHitPoint;//����ʣ��Ѫ��

	bool boolMonsterDetected;//

	int intTimeOfLastAttack;//�ϴι�����ʱ��

	Tower(int Locationx = 1, int Locationy = 1, int AttackInterval = 1000,
		int Attack = 10, int Cost = 10, int Sizex = 1, int Sizey = 1,
		double AttackRadius = 5, int HitPoint = 100);//���캯������ʼ��������

	bool update(int time, Map* map);//time��ʾ��ǰ��ʱ�䣬��λ���룬�ú�����timer���ã����Ը������Ĺ���CD��Ѫ��

	bool isInAttackingRange(Monster* monster, Map* map);//�жϹ��Ƿ������Ĺ�����Χ��

	Monster* searchMap(Map* map);//��map����ȡ�ֵ���Ϣ���ж�Ҫ���ĸ���
};


class Tower0 : public Tower
{
public:
	Tower0(int Locationx = 1, int Locationy = 1) :Tower(Locationx, Locationy, 0, 10, 10, 2, 2, 2.0, 100) { }//���캯������ʼ��������
};

#endif // TOWER_H