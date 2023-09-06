#include "DOOR.h"
#include"ENEMYS.h"
extern ENEMYS* enemys;
DOOR::DOOR(int length, int code, IMAGE* image) :BARRIER(length, code, image), t(0) {}
void DOOR::build(int _x, int _y) {
	BARRIER::build(_x, _y);
	t = GetTickCount();
}
bool DOOR::create(int n) {
	//�����±��ʾ�ĸ�����ÿһ����ͬ�±��tempx,tempyΪ������������������ɵĵ��˵�����
	int tempx[4] = { x,x,x - length,x + length };
	int tempy[4] = { y - length,y + length,y,y };
	for (int i = 0; i < 4; i++) {
		if (empty(tempx[i], tempy[i], length)) {//����ĸ��������п�����,������һ������
			if (n == boss_s)enemys->boss->build(tempx[i], tempy[i], DIRECTION(i));//����Ϊboss
			else {//����Ϊmob��ѡ��ָ��
				MOB** mob;
				switch (n) {
				case average1_s:
					mob = enemys->average1;
					break;
				case average2_s:
					mob = enemys->average2;
					break;
				default:
					return 0;
				}
				for (int j = 0; j < mob_n; j++) {
					if (mob[j]->build(tempx[i], tempy[i], DIRECTION(i)))return 1;//�ɹ�����һ��С��ʱ����ѭ��
				}
				return 1;
			}
		}
		}
	return 0;//û�п����򣬷���0
}
