#include "monster.cpp"
#include "tower.cpp"
class Map{
public:
    double DistanceToFinal[100];//���ﵽ�յ�ľ���/-������в��
    Monster* monsterExisted[100];//��ͼ�ϴ��ڵĹ���
    int intMonsterNumbers;
    Tower* towerExisted[100];//��ͼ�ϴ��ڵĹ���
    int intTowerNumbers;
    int sizex,sizey;
    char **MapState; //r · b ��  t �� 
    
    Map(int x=50,int y=30,int roadLocation[][2],int roadlength)
	{
		intMonsterNumbers=0;
		intTowerNumbers=0;
		sizex=x;
		sizey=y;
		MapState= new MapState[x][y];
		for (int i=0;i<x;i++)
			for (int j=0;j<y;j++)
				MapState[i][j]='b'; 
		for (int i=0;i<roadlength;i++)
			MapState[roadLocation[i][0]][roadLocation[i][1]];
	}
    
    void ProduceMonster(int MonsterType=0);
    bool ProduceTower(int TowerType=0,int x,int y);//x y ��ʾ�����Ͻ����� 
    bool MapisOccupied(int x,int y,int towersizex,int towersizey);
    void MapStateChangeToTower(int x,int y,int towersizex,int towersizey,char newstate);//�޸�MapStateΪ�� 
    void Update();//time��ʾ��ǰ��ʱ�䣬��λ���룬�ú�����timer���ã����Ը������Ĺ���CD��Ѫ��
    
    
};

void Map::ProduceMonster(int MonsterType=0)
{
	switch (MonsterType)
	{
		case 0:
			monsterExisted[intMonsterNumbers]=new Monster(100,1);//0�Ź� 100 1
			break;
		
		default:
			break; 
	}
	intMonsterNumbers++;
}

bool Map::ProduceTower(int TowerType=0,int x,int y)
{
	switch (TowerType)
	{
		case 0:
			towerExisted[intTowerNumbers]=new Tower0(x,y);//0���� 
			if (MapisOccupied(x,y,towerExisted[intTowerNumbers]->arraySize[0],towerExisted[intTowerNumbers]->arraySize[1])==0)//δ��ռ�� ���Խ��� 
			{
				intTowerNumbers++;
				MapStateChangeToTower(x,y,towerExisted[intTowerNumbers]->arraySize[0],towerExisted[intTowerNumbers]->arraySize[1],'t');//�޸�MapState 
				return true;
			}	
			else
			{
				delete towerExisted[intTowerNumbers];
				return false;
			}
			break;
		
		default:
			break; 
	}

}

bool Map::MapisOccupied(int x,int y,int towersizex,int towersizey)
{
	for (int i=0;i<towersizex;i++)
		for (int j=0;j<towersizey;j++)
			if (MapState[i+x][j+y]!='b')
				return false;
	return true;
}

void Map::MapStateChange(int x,int y,int towersizex,int towersizey,char newstate)
{
	for (int i=0;i<towersizex;i++)
		for (int j=0;j<towersizey;j++)
			MapState[i+x][j+y]=newstate;
}

void Map::Update(int time)//time�ĵ�λ��ms 
{
	for (int i=0;i<intMonsterNumbers;i++)//���й����ƶ� 
		DistanceToFinal[i]=monsterExisted[i]->move();
	for (int i=0;i<intTowerNumbers;i++)//���������� 
		towerExisted[i]->update(time,this);
	for (int i=0;i<intMonsterNumbers;i++)//�жϹ����Ƿ����� ������delete ͬʱά��
	{
		int newintMonsterNumbers=0;
		if (monsterExisted[i]->intHitPoint<=0)
		{
			delete monsterExisted[i];
			monsterExisted[i]=nullptr;
		}
		else 
		{
			monsterExisted[newintMonsterNumbers]=monsterExisted[i];
			newintMonsterNumbers++;
		}	
	}
	intMonsterNumbers=newintMonsterNumbers; 
}
