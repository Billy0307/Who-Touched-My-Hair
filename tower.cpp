#include "tower.h"
#include "map.h"
#include "monster.h"

Tower::Tower(int Locationx, int Locationy, int AttackInterval,
	int Attack, int Cost, int Sizex, int Sizey,
	double AttackRadius, int HitPoint) :
	intAttackInterval(AttackInterval), intAttack(Attack),
	intCost(Cost), doubleAttackRadius(AttackRadius),
	intHitPoint(HitPoint) {
	arrayLocation[0] = Locationx;
	arrayLocation[1] = Locationy;
	arraySize[0] = Sizex;
	arraySize[1] = Sizey;
}
bool Tower::update(int time, Map* map) {
	Monster* monsterDetected = searchMap(map);
	if (monsterDetected && (time - intTimeOfLastAttack >= intAttackInterval)) {
		monsterDetected->intHitPoint -= intAttack; //�Թ��޽��й���
		intTimeOfLastAttack = time;
	}
	return (intHitPoint > 0); //��������ݻ٣�����false,�����Ȼ���ڣ�����true
}

Monster* Tower::searchMap(Map* map) {
	Monster* monsterDetected = nullptr;
	int i = 0; //������
	int intMonster = -1; //���ڱ�ʾmonsterDetected��map->monsterExisted�е�rank
	while (i < map->intMonsterNumbers) {
		if (isInAttackingRange(map->monsterExisted[i], map)) {
			if (monsterDetected) {
				if (map->DistanceToFinal[i] < map->DistanceToFinal[intMonster]) {
					monsterDetected = map->monsterExisted[i];
					intMonster = i;
				}
			}
			else {
				monsterDetected = map->monsterExisted[i];
				intMonster = i;
			}
		}
		i++;
	} //�������ڴ�map����ȡ������Ϣ���Ӷ��ж�Ҫ���ĸ�����
	return monsterDetected;
}

bool Tower::isInAttackingRange(Monster* monster, Map* map) {
	double monsterx, monstery;
	monsterx = (map->roadLocation[(int)(monster->locationOrder)][0]) * ((int)(monster->locationOrder) + 1 - monster->locationOrder) + (map->roadLocation[1 + (int)(monster->locationOrder)][0]) * (monster->locationOrder - (int)(monster->locationOrder));
	monstery = (map->roadLocation[(int)(monster->locationOrder)][1]) * ((int)(monster->locationOrder) + 1 - monster->locationOrder) + (map->roadLocation[1 + (int)(monster->locationOrder)][1]) * (monster->locationOrder - (int)(monster->locationOrder));
	double intDistance = (monsterx - arrayLocation[0]) *
		(monsterx - arrayLocation[0]) +
		(monstery - arrayLocation[1]) *
		(monstery - arrayLocation[1]);
	return(intDistance <= doubleAttackRadius);
}