#include"SAKIEL.h"
SAKIEL::SAKIEL() :BOSS(100, 10, 1000, &images->sakiel[UP], &images->sakiel[DOWN], &images->sakiel[LEFT], &images->sakiel[RIGHT]) {}
void SAKIEL::skill() {
	harmnear(x, y, length, 2, CAMP::enemy,6);//�˺������������/�ϰ���
}
void SAKIEL::walk() {
	if (walktime()) {
		if (rand() % 50 == 0) {//��1/50����һ���ƶ�25������
			for (int i = 0; i < 25; i++)track();
		}
		else track();
	}
}