#ifndef TOWER_H
#define TOWER_H

#include "map.h"
#include "monster.h"

#define doubleThreatLevel[n]=-DistanceToFinal[n]; //这个减号是什么意思???

class Tower
{
    friend Map;

    friend Monster;

public:
    Tower();

    int arrayLocation[2];//位置坐标，[0]为x，[1]为y

    int intAttackInterval;//攻击间隔，单位毫秒

    int intAttack;//攻击力

    int intCost;//价格

    int arraySize[2];//塔的大小，长乘宽，[0]为水平长度，[1]为竖直长度

    double doubleAttackRadius;//攻击范围，默认为圆形，该变量代表圆的半径

    int intHitPoint;//塔的剩余血量

    bool boolMonsterDetected;//

    int intTimeOfLastAttack;//上次攻击的时间

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
        }//构造函数，初始化整个塔

    void ProduceMonster(int MonsterType);

    bool ProduceTower(int TowerType,int x,int y);//x y 表示塔左上角坐标

    bool MapisOccupied(int x,int y,int towersizex,int towersizey);

    void MapStateChangeToTower(int x,int y,int towersizex,int towersizey,char newstate);//修改MapState为塔

    void update(int time,Map* map);//time表示当前的时间，单位毫秒，该函数被timer调用，用以更新塔的攻击CD及血量

    bool isInAttackingRange(Monster* monster);//判断怪是否在塔的攻击范围内

    Monster* searchMap(Map* map);//从map类索取怪的信息，判断要打哪个怪
};

#endif // TOWER_H
