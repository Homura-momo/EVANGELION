#include "SHIELD.h"
SHIELD::SHIELD(int length, CAMP camp) :PICKPROP(length, camp, &images->shield) {}
void SHIELD::skill(int x, int y, DIRECTION direction)const {//����1����ֹ�˺���
	for (int i = 0; i < attack_n; i++) {
		if (attacks->remain[i].build(x, y, length, direction, camp, length / 2, length / 4, 5, BLUE))break;
	}
}
void SHIELD::defend(int& h) {
	if (num > 0) {
		if (num >= h) {//�����������㣬����ȫ���˺�
			num -= h;
			h = 0;
		}
		else
		{//�����������㣬ֻ���ղ����˺�
			num = 0;
			h -= num;
		}
	}
}
void SHIELD::show(int x, int y)const {//��������������0����һ��Ȧ����ʾ���Լ��������˺�
	if (num > 0) {
		setlinecolor(WHITE);
		circle(x + length / 2, y + length / 2, 0.7 * length);
	}
}