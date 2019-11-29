#include "monster.h"
/*��ҪMap�ṩ�ı���
Map.roadAmount; //��·���ӵ��ܸ���
*/
#include"map.h"

Monster::Monster(int blood, double speed, Map *thismap) {
    intHitPoint = blood;
    monsterMoveSpeed = speed;
	map = thismap;
    locationOrder = 0;
}

double Monster::move() {
    locationOrder += monsterMoveSpeed;
    return (double(map->roadCellAmount) - locationOrder); //�����ô���£�
}

bool Monster::hitHome() {
    return (locationOrder == map->roadCellAmount + 1);
}
