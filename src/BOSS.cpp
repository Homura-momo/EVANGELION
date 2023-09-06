#include"BOSS.h"
BOSS::BOSS(int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4) :ENEMY(large_length, HP_max, speed, firerate, i1, i2, i3, i4, boss_s) {}
void BOSS::attackway(){//�����������˺����������/�ϰ�����ż���
	harmnear(x, y, length, 1,CAMP::enemy,4);
	skill();
}
void BOSS::die()const{
	barriers->bossdoor->open();//��������
	barriers->buildaward(x,y,5,0,1);//���ɽ���
	score += 1000;//��������
}
void BOSS::draw()const {
	ROLE::draw();
	setlinecolor(WHITE);
	setfillcolor(RED);
	//����Ѫ������ʾѪ��
	rectangle(LENGTH - HP_max, 0, LENGTH - 1, 15);
	if (HP > 0) {
		solidrectangle(LENGTH - HP_max, 0, LENGTH - 1 - HP_max + HP, 15);
		shownum(LENGTH - HP_max - 25, 0, HP);
	}
}