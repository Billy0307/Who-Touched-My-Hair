#include <iostream>
using namespace std;

int roadCellAmount=1;//��·���ӵ�����
int roadLocation[100][2]={0};//��˳�����еĵ�·����λ��

class Monster{
public:
    int intHitPoint;//�����Ѫ��
    int arrayLocation[2];//�����λ��
	int monsterMoveSpeed;//������ٶ�
    int locationOrder;//���ﴦ�ڵڼ�����·������
    Monster(int blood, int speed){//���캯��
        intHitPoint = blood;
        monsterMoveSpeed = speed;
        *arrayLocation = *roadLocation[0];
    }
    void move();//����ǰ��һ��
    bool hitHome();//�жϹ����Ƿ��ϼ�
};

void Monster::move(){
    locationOrder += monsterMoveSpeed;
    *arrayLocation = *roadLocation[locationOrder];
}
/*
������дmove����
1 positionӦ����double���ͣ���Ȼ������ 
2 ϣ�����ṩmove������ roadLocation �� rank(double����) 
*/ 

bool Monster::hitHome(){
    return locationOrder==roadCellAmount-1;
}


int main(){
    Monster m(1,1);
    m.move();
    cout<<"1111111";
    return 0;
} 
