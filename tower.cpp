//����Ҫ�ӵ�ͼ����ȡ������Ϣ�������Ҫ������͵�ͼ�඼д�ò��ܼ�������update����

#include "monster.cpp"
#include "map.cpp"
#define doubleThreatLevel[n]=-DistanceToFinal[n];

class Tower{
public:
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
    Monster* searchMap(Map* map);//��map��������в�������յ㣩���ڹ�����Χ�ڵĹ���
    bool isInAttackingRange(Monster* monster);//�ж�monster�ǲ��������Ĺ�����Χ��
};

bool Tower::update(int time,Map* map){
    Monster* monsterDetected=searchMap(map);
    if (monsterDetected&&(time-intTimeOfLastAttack>=intAttackInterval)){
         monsterDetected->intHitPoint-=intAttack;//�Թ��޽��й���
        intTimeOfLastAttack=time;
    }
    return (intHitPoint>0);//��������ݻ٣�����false,�����Ȼ���ڣ�����true
}

Monster* Tower::searchMap(Map* map){
    Monster* monsterDetected=nullptr;
    int i=0;//������
    int intMonster=-1;//���ڱ�ʾmonsterDetected��map->monsterExisted�е�rank
    while(i<map->intMonsterNumbers){
        if(isInAttackingRange(map->monsterExisted[i])){
            if(monsterDetected){
                if(map->doubleThreatLevel[i]>map->doubleThreatLevel[intMonster]){
                    monsterDetected=map->monsterExisted[i];
                    intMonster=i;
                }
            }
            else{
                monsterDetected=map->monsterExisted[i];
                intMonster=i;
            }
        }
    } //�������ڴ�map����ȡ������Ϣ���Ӷ��ж�Ҫ���ĸ�����
    return monsterDetected;
}

bool Tower::isInAttackingRange(Monster* monster){
    double intDistance=(monster->arrayLocation[0]-arrayLocation[0])*
            (monster->arrayLocation[0]-arrayLocation[0])+
            (monster->arrayLocation[1]-arrayLocation[1])*
            (monster->arrayLocation[1]-arrayLocation[1]);
    return(intDistance<=doubleAttackRadius);
}

class Tower0 : public Tower
{
	Tower0(int Locationx=1,int Locationy=1):Tower(Locationx,Locationy,1000,10,10,2,2,5.0,100){ }//���캯������ʼ��������	
};
