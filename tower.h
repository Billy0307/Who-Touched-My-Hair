//#pragma once
#ifndef TOWER_H
#define TOWER_H

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

    Tower(int Locationx=1,int Locationy=1,int AttackInterval=1000,
              int Attack=10,int Cost=10,int Sizex=2,int Sizey=2,
              double AttackRadius=5,int HitPoint=100):
              intAttackInterval(AttackInterval),intAttack(Attack),
              intCost(Cost),doubleAttackRadius(AttackRadius),
              intHitPoint(HitPoint){
            arrayLocation[0]=Locationx;
            arrayLocation[1]=Locationy;
            arraySize[0]=Sizex;
            arraySize[1]=Sizey;
        }//���캯������ʼ��������

    bool update(int time,Map* map);//time��ʾ��ǰ��ʱ�䣬��λ���룬�ú�����timer���ã����Ը������Ĺ���CD��Ѫ��

    bool isInAttackingRange(Monster* monster,Map* map);//�жϹ��Ƿ������Ĺ�����Χ��

    Monster* searchMap(Map* map);//��map����ȡ�ֵ���Ϣ���ж�Ҫ���ĸ���
};


class Tower0 : public Tower
{
public:
    Tower0(int Locationx=1,int Locationy=1):Tower(Locationx,Locationy,1000,10,10,2,2,5.0,100){ }//���캯������ʼ��������
};

#endif // TOWER_H
