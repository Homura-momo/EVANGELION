#include "GAGHIEL.h"
#include"HERO.h"
extern HERO* hero;
GAGHIEL::GAGHIEL() :BOSS(100, 10, 1000, &images->gaghiel[UP], &images->gaghiel[DOWN], &images->gaghiel[LEFT], &images->gaghiel[RIGHT]), knife(5, length, CAMP::enemy) {}
void GAGHIEL::skill() {
	for (DIRECTION d = UP; d <= RIGHT; d = DIRECTION(d + 1))knife.use(x, y, d);//���ĸ�����ʹ��knife
}
void GAGHIEL::walk() {
	if (walktime()) {
		if (rand() % 50 == 0) {//��1/50�����ƶ�������Աߣ�����ʹ���˺���ҵĶԳ����غ�
	//�����±��ʾ�ĸ�����ÿһ����ͬ�±��tempx,tempyΪBOSS����ҵ����������ֵ�����
			int tempx[4] = { hero->getx() + hero->getlength() / 2 - length / 2,hero->getx() + hero->getlength() / 2 - length / 2,hero->getx() - length,hero->getx() + hero->getlength() };
			int tempy[4] = { hero->gety() - length,hero->gety() + hero->getlength(),hero->gety() + hero->getlength() / 2 - length / 2,hero->gety() + hero->getlength() / 2 - length / 2 };
			for (int i = 0; i < 4; i++) {
				if (empty(tempx[i], tempy[i], length)) {//����ĸ��������п�����������ĵ�������
					setmap(x, y, length, empty_s);//��ԭ��λ������Ϊ��
					x = tempx[i];
					y = tempy[i];
					setmap(x, y, length, code);
					break;
				}
			}
		}
		else track();
	}
}
