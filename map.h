#pragma once
//#ifndef MAP_H
//#define MAP_H

class Monster;
class Tower;

class Map
{
public:

    int sizex, sizey;

    int roadCellAmount;//��·���ӵ�����

    int roadLocation[100][2];//��˳�����еĵ�·����λ��

    double DistanceToFinal[100];//���ﵽ�յ�ľ���/-������в��

    int intTowerNumbers;

    int intMonsterNumbers;
    
    int intHairBlood;//ͷ��Ѫ�� 
    
    Monster* monsterExisted[100];//��ͼ�ϴ��ڵĹ���

    Tower* towerExisted[100];//��ͼ�ϴ��ڵ��� 

    int **MapState; //-2Ϊͷ�� -1Ϊ·��0Ϊ�գ�1Ϊ����2��ʾ������������һ��͸������

    Map( int road[][2], int roadlength, int x=50, int y=30,int hairblood=10);

    void ProduceMonster(int MonsterType);

    bool ProduceTower(int TowerType,int x,int y);//x y ��ʾ�����Ͻ�����

    bool MapisOccupied(int x,int y,int towersizex,int towersizey); //ָ��λ�õĸ����Ƿ�ռ��

    void MapStateChange(int x,int y,int towersizex,int towersizey,int newstate);//�޸�MapStateΪ�� //���ǽ���һ����

    bool Update(int);//time��ʾ��ǰ��ʱ�䣬��λ���룬�ú�����timer���ã����Ը������Ĺ���CD��Ѫ�����ж���Ϸ�Ƿ������trueΪ��Ϸ���� 

};

//#endif // MAP_H
